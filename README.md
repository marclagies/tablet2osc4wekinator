# tablet2osc4wekinator
Send OSC messages with a graphic tablet.

The program sends these six __stylus__ parameters via OSC:<br>
* x position
* y position
* pressure
* x tilt
* y tilt
* rotation

## Installation
Install __Qt 5.7__ and __xinput__ as well as the development versions of __liblo__ and __libXi__.<br>
* Start Qt Creator.
* Create new __Qt Widgets Application__.
* Name the project __tablet2osc4wekinator__.
* Close Project.
* Copy _tablet2osc4wekinator_ files into project directory.
* Open _tablet2osc4wekinator_ project and build project.


If versions or paths of the required libraries are bad, try editing _tablet2osc4wekinator.pro_.<br>
<br>
You find the executable program in your build folder.<br>

## Setup
1. List devices on the command line:<br>
<br>
__xinput list__<br>
<br>
`% xinput list`<br>
`⎡ Virtual core pointer                    	id=2	[master pointer  (3)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Finger touch      	id=14	[slave  pointer  (2)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Pen stylus        	id=15	[slave  pointer  (2)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Pen eraser        	id=16	[slave  pointer  (2)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Pen cursor        	id=17	[slave  pointer  (2)]`<br>
`⎣   ↳ Wacom Intuos5 touch L Pen pad           	id=18	[slave  pointer  (2)]`<br>
<br>
2. Detach stylus from core pointer (optional):<br>
<br>
__xinput float 15__<br>
<br>
`% xinput float 15`<br>
`% xinput list`<br>
`⎡ Virtual core pointer                    	id=2	[master pointer  (3)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Finger touch      	id=14	[slave  pointer  (2)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Pen eraser        	id=16	[slave  pointer  (2)]`<br>
`⎜   ↳ Wacom Intuos5 touch L Pen cursor        	id=17	[slave  pointer  (2)]`<br>
`⎣   ↳ Wacom Intuos5 touch L Pen pad           	id=18	[slave  pointer  (2)]`<br>
`∼ Wacom Intuos5 touch L Pen stylus        	id=15	[floating slave]`

## Running tablet2osc4wekinator
tablet2osc4wekinator takes four arguments:<br>
* Device name of stylus
* IP address of OSC listener
* OSC input address
* OSC input port


__`./tablet2osc4wekinator "Wacom Intuos5 touch L Pen stylus" "127.0.0.1" "/wek/inputs" "6448"`__<br>

## Thanks
tablet2osc4wekinator is based on Sylvain Hanneton's tablet2osc.

## Links:
tablet2osc - https://sourceforge.net/p/tablet2osc/wiki/Home/<br>
Wekinator - http://www.wekinator.org
