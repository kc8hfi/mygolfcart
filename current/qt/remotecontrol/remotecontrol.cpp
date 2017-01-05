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

#include <QDebug>
#include <QtNetwork>
#include <QAbstractSocket>
#include <QString>
#include <QKeyEvent>
#include <QShortcut>
#include <QTimer>
#include "about.h"
#include "connectioninfo.h"
#include "remotecontrol.h"
#include "Joystick.h"

/*!
*define a bunch of constants for the commands that get sent to the server
*/
const QString START_VEHICLE_FORWARD     = "BVF";
const QString STOP_VEHICLE_FORWARD      = "EVF";
const QString START_VEHICLE_REVERSE     = "BVB";
const QString STOP_VEHICLE_REVERSE      = "EVB";
const QString START_VEHICLE_LEFT        = "BVL";
const QString STOP_VEHICLE_LEFT         = "EVL";
const QString START_VEHICLE_RIGHT       = "BVR";
const QString STOP_VEHICLE_RIGHT        = "EVR";

const QString START_TURRET_LEFT         = "BTL";
const QString STOP_TURRET_LEFT          = "ETL";
const QString START_TURRET_RIGHT        = "BTR";
const QString STOP_TURRET_RIGHT         = "ETR";
const QString START_TURRET_UP           = "BTU";
const QString STOP_TURRET_UP            = "ETU";
const QString START_TURRET_DOWN         = "BTD";
const QString STOP_TURRET_DOWN          = "ETD";

const QString START_FIRE                = "SF";
const QString STOP_FIRE                 = "EF";

const QString HEART_BEAT                = "ping";
/*!
*set up a new RemoteControl object
*/
RemoteControl::RemoteControl(QMainWindow *parent)
	: QMainWindow(parent)
{
     remoteControl.setupUi(this);

     startfwd = 0;
     startbwk = 0;
     startleft = 0;
     startright = 0;

     ipaddress = "";
     port = "";

     //make a socket
     socket = new QTcpSocket(this);
     //connect(socket, SIGNAL(readyRead()), this, SLOT(readFortune()));
     connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
               this, SLOT(displayError(QAbstractSocket::SocketError)));

     connect(socket, SIGNAL(connected()),this,SLOT(connectionSuccess()));
     
     connect(socket, SIGNAL(readyRead()), this, SLOT(getthestuff()));

     joystick = new Joystick();

     connect (joystick,SIGNAL(buttonPress(int)), this, SLOT(buttonPress(int)));
     connect (joystick,SIGNAL(buttonRelease(int)), this, SLOT(buttonRelease(int)));
     connect (joystick,SIGNAL(axisEvent(int,int)), this, SLOT(axisEvent(int,int)));
     
     //set up a new timer 
     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(heartBeat()));

     timerDelay = 3000; //in milliseconds,  1000ms = 1s
     //w = new QShortcut(Qt::Key_W, this, SLOT(start_forward()));
     //w->setAutoRepeat(false);

     //QWidget::setShortcutAutoRepeat(false);
     /*http://doc.qt.nokia.com/4.6/qt4-network.html#tcp-client*/

     remoteControl.statusBar->showMessage("Not connected");
}//end constructor

/*!
 * shows that about dialog box
 */
void RemoteControl::about()
{
     About about;
     about.exec();
}

void RemoteControl::heartBeat()
{
     //qDebug()<<"timer fired";
     QTextStream out(socket);
     out << HEART_BEAT;
     out << "\n";
     
}


void RemoteControl::getthestuff()
{
     QString temp = "";
     while (socket->bytesAvailable())
     {
          temp = socket->readAll();
          
/*          
        buffer.append(socket->readAll());
        int packetSize = getPacketSize(buffer);
        while(packetSize>0)
        {
            handlePacket(buffer.left(packetSize);
            buffer.remove(0,packetSize);
            packetSize = getPacketSize(buffer);
        }
    }*/
     }
     remoteControl.textBrowser->append(temp);
}


/*!
*Opens a dialog box,  gets the ip address and port of the server.  
*Makes a connection to the server, display an error message if the 
*connection could not be made
*/
void RemoteControl::serverConnect()
{
     //show a dialog box to get the ip and port
     ConnectionInfo d;
     if (d.exec())
     {
          qDebug()<<d.getIp();
          qDebug()<<d.getPort();
          if (d.getIp() != "" && d.getPort() != "")
          {
               if(socket->state() == QAbstractSocket::UnconnectedState)
               {
                    socket->connectToHost(d.getIp(), d.getPort().toInt());
                    ipaddress = d.getIp();
                    port = d.getPort();
                    timer->stop();
               }
               else if(socket->state() == QAbstractSocket::ConnectedState)
               {
                    socket->disconnectFromHost();
                    socket->connectToHost(d.getIp(), d.getPort().toInt());
                    ipaddress = d.getIp();
                    port = d.getPort();
               }
          }
     }
}//end serverConnect

/*!
 * disconnect from the server
 */
void RemoteControl::serverDisconnect()
{
     if(socket->state() == QAbstractSocket::ConnectedState)
     {
          socket->disconnectFromHost();
          remoteControl.statusBar->showMessage("Not connected");
          timer->stop();
          qDebug()<<"stopped the timer";
          remoteControl.textBrowser->setText("");
     }
}

/*!
*displays the error message if a connection could not be made
*/
void RemoteControl::displayError(QAbstractSocket::SocketError error)
{
     qDebug()<<"Failed to make a network connection!" << error;
     //remoteControl.infoLabel->setText("Connection failed!");
     remoteControl.statusBar->showMessage("Connection failed!");
}


/*!
 * connection was successful, update the interface to indicate it
 */
void RemoteControl::connectionSuccess()
{
     //remoteControl.infoLabel->setText("Connected to: " + ipaddress +":" +port);
     remoteControl.statusBar->showMessage("Connected to: " + ipaddress +":" +port);
     qDebug()<<"start the timer";
     timer->start(timerDelay);        //in milliseconds,  1000ms = 1s

}

/*!
 * handles the d-pad on the joystick
*/
void RemoteControl::axisEvent(int axis, int value)
{
    /*
     if (axis == 1 && value == -32768)
     {
          //qDebug()<<"forward";
          start_forward();
          startfwd = 1;
     }
     if (axis == 1 && value == 32767)
     {
          //qDebug()<<"backward";
          start_reverse();
          startbwk = 1;
     }
     */
    /*
     if (axis == 1 && value == 0)
     {
          if (startfwd == 1)
          {
               //qDebug()<<"stop forward";
               stop_forward();
               startfwd = 0;
          }
          if(startbwk == 1)
          {
               //qDebug()<<"stop backward";
               stop_reverse();
               startbwk = 0;
          }
          //qDebug()<<"stop forward or backward";
     }
     */
     //part of the code that deals with the x-axis
     if (axis == 0 && value == -32768)
     {
          //qDebug()<<"left";
          start_left();
          startleft = 1;
     }
     if (axis == 0 && value == 32767)
     {
          //qDebug()<<"right";
          start_right();
          startright = 1;
     }
     if (axis == 0 && value == 0)
     {
          if (startleft == 1)
          {
               //qDebug()<<"stop left";
               stop_left();
               startleft = 0;
          }
          if(startright == 1)
          {
               //qDebug()<<"stop right";
               stop_right();
               startright = 0;
          }
          //qDebug()<<"stop forward or backward";
     }
     //qDebug()<<"axis: "<<axis<<" value:"<<value;
}//end axisEvent

/*!red = 0
 * yellow = 1
 * green = 2
 * blue = 3
 * l1 = 4
 * r1 = 5
 * l2 = 6
 * r2 = 7
 * select = 8
 * start = 9
 */ 

void RemoteControl::buttonPress(int button)
{
     qDebug()<<button<<" pressed";
     switch(button)
     {
          case 0:
               //start_fire();
               start_forward();
          break;
          case 1:
               qDebug()<<"start the brakes";
          break;
          case 2:
               start_turret_up();
          break;
          case 3:
               start_turret_down();
          break;
          case 4:
               start_turret_left();
          break;
          case 5:
               start_turret_right();
          break;
     }
}//end buttonPress

void RemoteControl::buttonRelease(int button)
{
     qDebug()<<button<<" released";
     switch(button)
     {
          case 0:
               //stop_fire();
               stop_forward();
          break;
          case 1:
               qDebug()<<"stop the brakes";
          break;
          case 2:
               stop_turret_up();
          break;
          case 3:
               stop_turret_down();
          break;
          case 4:
               stop_turret_left();
          break;
          case 5:
               stop_turret_right();
          break;
     }
}

//sends the start forward command
void RemoteControl::start_forward()
{
     qDebug()<<"start forward";
     QTextStream out(socket);
     out << START_VEHICLE_FORWARD;
     out << "\n";
}

//sends the stop forward command
void RemoteControl::stop_forward()
{
     //qDebug()<<"stop forward";
     QTextStream out(socket);
     out << STOP_VEHICLE_FORWARD;
     out << "\n";
}

//sends the start reverse command
void RemoteControl::start_reverse()
{
     //qDebug()<<"start going backward";
     QTextStream out(socket);
     out << START_VEHICLE_REVERSE;
     out << "\n";
}

//sends the stop reverse command
void RemoteControl::stop_reverse()
{
     //qDebug()<<"stop going backward";
     QTextStream out(socket);
     out << STOP_VEHICLE_REVERSE;
     out << "\n";
}

void RemoteControl::start_left()
{
     //qDebug()<<"start left";
     QTextStream out(socket);
     out << START_VEHICLE_LEFT;
     out << "\n";
}

void RemoteControl::stop_left()
{
     //qDebug()<<"stop left";
     QTextStream out(socket);
     out << STOP_VEHICLE_LEFT;
     out << "\n";
}

void RemoteControl::start_right()
{
     //qDebug()<<"start right";
     QTextStream out(socket);
     out << START_VEHICLE_RIGHT;
     out << "\n";
}

void RemoteControl::stop_right()
{
     //qDebug()<<"stop right";
     QTextStream out(socket);
     out << STOP_VEHICLE_RIGHT;
     out << "\n";
}

void RemoteControl::start_turret_left()
{
     //qDebug()<<"start turret left";
     QTextStream out(socket);
     out <<START_TURRET_LEFT;
     out <<"\n";
}

void RemoteControl::stop_turret_left()
{
     //qDebug()<<"stop turret left";
     QTextStream out(socket);
     out <<STOP_TURRET_LEFT;
     out <<"\n";
}

void RemoteControl::start_turret_right()
{
     //qDebug()<<"start turret right";
     QTextStream out(socket);
     out <<START_TURRET_RIGHT;
     out<<"\n";
}

void RemoteControl::stop_turret_right()
{
     //qDebug()<<"stop turret right";
     QTextStream out(socket);
     out<<STOP_TURRET_RIGHT;
     out<<"\n";
}

void RemoteControl::start_turret_up()
{
     //qDebug()<<"start turret up";
     QTextStream out(socket);
     out<<START_TURRET_UP;
     out<<"\n";
}

void RemoteControl::stop_turret_up()
{
     //qDebug()<<"stop turret up";
     QTextStream out(socket);
     out<<STOP_TURRET_UP;
     out<<"\n";
}

void RemoteControl::start_turret_down()
{
     //qDebug()<<"start turret down";
     QTextStream out(socket);
     out<<START_TURRET_DOWN;
     out<<"\n";
}

void RemoteControl::stop_turret_down()
{
     //qDebug()<<"stop turret down";
     QTextStream out(socket);
     out<<STOP_TURRET_DOWN;
     out<<"\n";
}

void RemoteControl::start_fire()
{
     qDebug()<<"start shooting";
     QTextStream out(socket);
     out<<START_FIRE;
     out<<"\n";
}

void RemoteControl::stop_fire()
{
     qDebug()<<"stop shooting";
     QTextStream out(socket);
     out<<STOP_FIRE;
     out<<"\n";
}

// void RemoteControl::keyPressEvent(QKeyEvent *event)
// {
//      qDebug()<<"a key was pressed";
//      if (!event->isAutoRepeat())
//      {
//           switch(event->key())
//           {
//                case Qt::Key_W:
//                     start_forward();
//                break;
//                case Qt::Key_A:
//                     start_left();
//                break;
//                case Qt::Key_S:
//                     start_reverse();
//                break;
//                case Qt::Key_D:
//                     start_right();
//                break;
//                case Qt::Key_I:
//                     start_turret_up();
//                break;
//                case Qt::Key_K:
//                     start_turret_down();
//                break;
//                case Qt::Key_J:
//                     start_turret_left();
//                break;
//                case Qt::Key_L:
//                     start_turret_right();
//                break;
//                case Qt::Key_Return:
//                     start_fire();
//                break;
//                default:
//                     qDebug()<<"beats me";
//                     QWidget::keyPressEvent(event);
//           }
//      }
// }

void RemoteControl::keyPressEvent(QKeyEvent *event)
{
     qDebug()<<"a key was pressed";
//      if (!event->isAutoRepeat())
//      {
//           switch(event->key())
//           {
//                case Qt::Key_W:
//                     start_forward();
//                break;
//                case Qt::Key_A:
//                     start_left();
//                break;
//                case Qt::Key_S:
//                     start_reverse();
//                break;
//                case Qt::Key_D:
//                     start_right();
//                break;
//                case Qt::Key_I:
//                     start_turret_up();
//                break;
//                case Qt::Key_K:
//                     start_turret_down();
//                break;
//                case Qt::Key_J:
//                     start_turret_left();
//                break;
//                case Qt::Key_L:
//                     start_turret_right();
//                break;
//                case Qt::Key_Return:
//                     start_fire();
//                break;
//                default:
//                     qDebug()<<"beats me";
//                     QWidget::keyPressEvent(event);
//           }
//      }
}

void RemoteControl::keyReleaseEvent(QKeyEvent *event)
{
     qDebug()<<event->key()<<" was released";
     remoteControl.textBrowser->setText("key was released");
}

// void RemoteControl::keyReleaseEvent(QKeyEvent *event)
// {
//      qDebug()<<event->key();
//      qDebug()<<"a key was released";
// 	if (!event->isAutoRepeat())
// 	{
// 		switch(event->key())
// 		{
// // 			case Qt::Key_W:
// // 				stop_forward();
// // 				break;
// 			case Qt::Key_A:
// 				stop_left();
// 				break;
// // 			case Qt::Key_S:
// // 				stop_reverse();
// // 				break;
// 			case Qt::Key_D:
// 				stop_right();
// 				break;
// // 			case Qt::Key_I:
// // 				stop_turret_up();
// // 				break;
// 			case Qt::Key_K:
// 				stop_turret_down();
// 				break;
// 			case Qt::Key_J:
// 				stop_turret_left();
// 				break;
// // 			case Qt::Key_L:
// // 				stop_turret_right();
// // 				break;
// // 			case Qt::Key_Return:
// // 				stop_fire();
// // 				break;
// 
// 			default:
// 				QWidget::keyPressEvent(event);
// 		}
// 	}
// }
