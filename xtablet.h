#ifndef XTABLET_H
#define XTABLET_H

#include <string.h>
#include <string>
#include <X11/extensions/XInput.h>

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

#define MAXDEVICENAME 256
#define MAXMESSAGE  512

class XTablet
{
public :
    // X Properties
    bool    Enabled;
    Display *TabletDisplay;
    XDevice *Tablet;
    XDeviceInfoPtr TabletInfoPtr;
    int nEventListCnt;
    XEventClass eventList[32];

    // XTablet Object Methods
    XTablet();
    ~XTablet(void);
    bool ConnectDevice(std::string name);
    bool OpenDevice(void);
    void PrepareEvents(void);
    void DispatchEvents(void);
    void (*EventCallback)(char *m);

    // Methods from XIDUMP.C
    Display* InitXInput(void);
    XDeviceInfoPtr GetDevice(Display* pDisp, const char* pszDeviceName);
};

#endif // XTABLET_H
