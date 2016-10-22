// tablet2osc4wekinator
// Author: Marc Lagies, 2016
//
// This program is based on Sylvain Hanneton's tablet2osc
// https://sourceforge.net/p/tablet2osc/wiki/Home/
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "mainwindow.h"

MainWindow *MW;
AcquisitionThread *tablet_thread;
void ProcessTabletEvents(char *m);

AcquisitionThread::AcquisitionThread(XTablet *Tab)
{
    this->Tablet = Tab;
}

void AcquisitionThread::run(void)
{
    Tablet->DispatchEvents();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MW = this;
    counter=0;
    xicounter = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayTabletName()
{
    this->setWindowTitle(this->TabletName + " -> " + this->IP);
}

void MainWindow::DisplayOscAddress()
{
    ui->label->setText(this->OscAddress);
}

void MainWindow::SetStatus(QString S)
{
    ui->statusBar->showMessage(S,0);
}

void MainWindow::Init()
{
    // Device initialisation
    T = new XTablet();
    T->EventCallback = ProcessTabletEvents;
    // Create the acquisition Thread
    tablet_thread = new AcquisitionThread(T);
    // Connection
    InitTablet(this->TabletName.toStdString().c_str());
}

void MainWindow::InitTablet(const char *devicename)
{
    char message[512];

    if (!T->ConnectDevice(devicename))
    {
        sprintf(message,"Unable to connect Device %s",devicename);
        SetStatus(message);
    }
    else
    {
        sprintf(message,"Connected..."); SetStatus(message);

        if (!T->OpenDevice())
        {
            sprintf(message,"Unable to open the device %s",devicename);
            SetStatus(message);
        }
        else
        {
            sprintf(message,"Connection opened..."); SetStatus(message);
            T->PrepareEvents();
            sprintf(message,"Events can be received and send..."); SetStatus(message);
            T->Enabled = true;
        }
    }
}

void MainWindow::InitOsc(void)
{
    address = lo_address_new(IP.toStdString().c_str(),OscPort.toStdString().c_str());
}

bool MainWindow::SendOscSixFloat(float f1,float f2, float f3, float f4, float f5, float f6)
{
    if (lo_send(address,OscAddress.toStdString().c_str(), "ffffff", f1,f2,f3,f4,f5,f6) == -1)
    {
        OscError(lo_address_errno(address), lo_address_errstr(address));
        return(false);
    }
    else {counter++; return(true);}
}

void MainWindow::OscError(int num, const char *message)
{
    char qmessage[512];

    sprintf(qmessage,"OSC error #%d : %s",num,message);
    SetStatus(QString(qmessage));
}

void MainWindow::IncXICounter(void)
{
    xicounter++;
}

void MainWindow::Run(void)
{
    tablet_thread->start();
}

[[noreturn]] void MainWindow::Stop(void)
{
    T->Enabled = false;
    tablet_thread->terminate();
    tablet_thread->wait();
    lo_address_free(address);
    printf("Tablet messages received : %d\n", xicounter);
    printf("Osc messages send        : %d\n", counter);
    printf("Exiting...\n");
    exit(0);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->text()=="Start")
    {
        ui->pushButton->setText("Quit");
        SetStatus("Running...");
        Run();
    }
    else Stop();
}

void ProcessTabletEvents(char *m)
{
    QString M(m);
    QString I;
    QStringList Part = M.split(" ");
    float x,y,p,tx,ty,w;

    MW->IncXICounter();
    sscanf(M.toStdString().c_str(),"x=%f y=%f p=%f tx=%f ty=%f w=%f",&x,&y,&p,&tx,&ty,&w);
    MW->SendOscSixFloat(x,y,p,tx,ty,w);

    // Display message in the console
    fprintf(stdout,"%s\n",m);
}
