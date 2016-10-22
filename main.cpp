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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Get arguments
//    w.TabletName = "Wacom Intuos5 touch L Pen stylus";
//    w.IP = "127.0.0.1";
//    w.OscAddress = "/wek/inputs";
//    w.OscPort = "6448";

    w.TabletName = QString(argv[1]);
    w.IP = QString(argv[2]);
    w.OscAddress = QString(argv[3]);
    w.OscPort = QString(argv[4]);

    // Show window
    w.show();
    w.DisplayTabletName();
    w.DisplayOscAddress();
    w.Init();
    w.InitOsc();

    return a.exec();
}
