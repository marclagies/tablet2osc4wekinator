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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QStringList>
#include "lo/lo.h"
#include <cstdio>
#include "ui_mainwindow.h"
#include "xtablet.h"

class AcquisitionThread : public QThread
{
public :
    XTablet *Tablet;
    AcquisitionThread(XTablet *Tab);
    void run();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString IP;
    QString OscAddress;
    QString TabletName;
    QString OscPort;
    lo_address address;
    void SetStatus(QString S);
    void DisplayOscAddress();
    void DisplayTabletName();
    void Init();
    void InitTablet(const char *devicename);
    void InitOsc(void);
    bool SendOscSixFloat(float f1,float f2, float f3, float f4, float f5, float f6);
    void IncXICounter(void);
    void OscError(int num, const char *message);
    void Run();
    void Stop();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    XTablet *T;
    int     counter;
    int     xicounter;
};

#endif // MAINWINDOW_H
