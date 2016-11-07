/*
 * Copyright 2010-2013
 * Richie Adams, Charles Amey, Donald Kinder, Chance Sheets
 * 

This file is part of Remote Control.

Remote Control is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Remote Control.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "ui_remotecontrolbase.h"
#include <QAbstractSocket>

class QTcpSocket;
class QShortcut;
class Joystick;

/*!
* RemoteControl class.  remote control gui interface for the powerwheels vehicle
* @author Charles Amey
* @version 0.2
*/


class RemoteControl : public QMainWindow, private Ui_RemoteControlBase
{
     Q_OBJECT
     public:
          /*!
          *create a new RemoteControl object
          */
          RemoteControl(QMainWindow *parent=0);
          
          /*!
          *keyboard key pressed event handler
          */
          void keyPressEvent(QKeyEvent *event);
          
          /*!
          *keyboard key released event handler
          */
          void keyReleaseEvent( QKeyEvent * event );
     public slots:
          /*!
          *display any errors that may occur when connecting to the server
          */
          void displayError(QAbstractSocket::SocketError);
          
          void getthestuff();
          
          /*!
               * if the connection was successful, do this
               */
          void connectionSuccess();
          
          /*!
           * shows the about dialog box
           */
          void about();
          
          /*!
          *displays a dialog box asking for the ip and port of the server,
          *then connects to the server
          */
          void serverConnect();
          
          /*!
           * disconnects from the server
           */
          void serverDisconnect();

          /*!
          *sends the signal to the server to tell the vehicle to start moving forward
          */
          void start_forward();
          
          /*!
          *sends the signal to the server to tell the vehicle to stop moving forward
          */
          void stop_forward();
          /*!
          *sends the signal to the server to tell the vehicle to start moving backward
          */
          void stop_reverse();
          /*!
          *sends the signal to the server to tell the vehicle to stop moving backward
          */		
          void start_reverse();
          
          /*!
          *sends the signal to the server to tell the vehicle to start turning left
          */
          void start_left();
          
          /*!
          *send the signal to the server to tell the vehicle to stop turning left
          */
          void stop_left();
          
          /*!
          *send the signal to the server to tell the vehicle to start turning right
          */
          void start_right();
          
          /*!
          *send the signal to the server to tell the vehicle to stop turning right
          */
          void stop_right();
          
          /*!
               * send signal to server to tell turret to start left
          */ 
          void start_turret_left();
          
          /*!
               * send signal to server to tell the turret to stop left
          */
          void stop_turret_left();
          
          /*!
               * send signal to server to tell the turret to start right
               */
          void start_turret_right();
          
          /*!
               * send signal to server to tell the turret to stop right
          */
          void stop_turret_right();
          
          /*!
               * send signal to server to tell the turret to start up
               */
          void start_turret_up();
          
          /*!
               * send signal to server to tell the turret to stop going up
               */
          void stop_turret_up();
          
          /*!
               * send signal to server to tell the turret to start down
               */
          void start_turret_down();

          /*!
               * send signal to server to tell the turret to stop going down
               */
          void stop_turret_down();
          

          /*!
               * send signal to start firing the gun
               */
          void start_fire();
          
          /*!
               * send signal to stop firing the gun
               */
          void stop_fire();
          
          /*!
               * event handler for the d-pad on the joystick
               */
          void axisEvent(int axis, int value);
          
          /*!
               * event handler for a joystick button press
               */
          void buttonPress(int button);
          
          /*!
               * event handler for a joystick button releas
               */
          void buttonRelease(int button);
          
          
          void heartBeat();
          
     private:
          //The actual gui object
          Ui_RemoteControlBase remoteControl;
          
          //the actual connection to the server
          QTcpSocket *socket;
          
          QTimer *timer;
          int timerDelay;
          
          //joystick
          Joystick *joystick;
          
          int startfwd;
          int startbwk;
          
          int startleft;
          int startright;
          
          QString ipaddress;
          QString port;
};

#endif
