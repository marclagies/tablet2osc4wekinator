# tablet2osc4wekinator
# Author: Marc Lagies, 2016
#
# This program is based on Sylvain Hanneton's tablet2osc
# https://sourceforge.net/p/tablet2osc/wiki/Home/
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T11:42:23
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tablet2osc4wekinator
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp \
           xtablet.cpp

HEADERS  += mainwindow.h \
            xtablet.h

LIBS += /usr/lib/x86_64-linux-gnu/libX11.so.6 \
        /usr/lib/x86_64-linux-gnu/libXext.so \
        /usr/lib/x86_64-linux-gnu/libXi.so \
        /usr/lib/liblo.so

FORMS += mainwindow.ui
