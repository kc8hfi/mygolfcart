#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectioninfo.h"

#include <QKeyEvent>
#include <QtNetwork>

const QString START_VEHICLE_FORWARD     = "BVF";
const QString STOP_VEHICLE_FORWARD      = "EVF";
const QString START_VEHICLE_LEFT        = "BVL";
const QString STOP_VEHICLE_LEFT         = "EVL";
const QString START_VEHICLE_RIGHT       = "BVR";
const QString STOP_VEHICLE_RIGHT        = "EVR";
const QString START_BRAKES              = "BB";
const QString STOP_BRAKES               = "EB";

const QString START_IGNITION            = "on";
const QString STOP_IGNITION             = "off";

const QString HEART_BEAT                = "ping";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    
     ip = "";
     port = "";
     startleft = 0;
     startright = 0;

    
     //make a socket
     socket = new QTcpSocket(this);
     connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
               this, SLOT(displayError(QAbstractSocket::SocketError)));

     connect(socket, SIGNAL(connected()),this,SLOT(connectionSuccess()));
     connect(socket, SIGNAL(readyRead()), this, SLOT(getStuff()));

     connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(serverConnect()));
     connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(serverDisconnect()));
     
     ui->heading->setStyleSheet("QLabel { background-color : white;}");
     ui->ticks->setStyleSheet("QLabel { background-color : white;}");
     ui->revolutions->setStyleSheet("QLabel { background-color : white;}");
     
     ui->goButton->setStyleSheet("QPushButton { background-color : green;}");
     ui->brakeButton->setStyleSheet("QPushButton { background-color : red;}");
     
     //set up a new timer 
     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(heartBeat()));
     
     timerDelay = 3000; //in milliseconds,  1000ms = 1s
     

     joystick = new Joystick();

     connect (joystick,SIGNAL(buttonPress(int)), this, SLOT(buttonPress(int)));
     connect (joystick,SIGNAL(buttonRelease(int)), this, SLOT(buttonRelease(int)));
     connect (joystick,SIGNAL(axisEvent(int,int)), this, SLOT(axisEvent(int,int)));
     
     
     connect(ui->ignitionOnButton,SIGNAL(clicked()), this, SLOT(ignitionOn()));
     connect(ui->ignitionOffButton,SIGNAL(clicked()), this, SLOT(ignitionOff()));
     
     ui->ignitionOnButton->setEnabled(false);
     ui->ignitionOffButton->setEnabled(false);
     
     
    //make shortcuts
//     ui->rightButton->setShortcut(Qt::Key_D);
//     ui->goButton->setShortcut(Qt::Key_J);
//     ui->stopButton->setShortcut(Qt::Key_L);
    
//     QAction *test = new QAction(this);
//     test->setShortcut(Qt::Key_A);
//     connect(test,SIGNAL(triggered()), this, SLOT(leftButtonPressed()));
//     this->addAction(test);
    
    //connect the buttons
    connect(ui->leftButton,SIGNAL(pressed()), this, SLOT(leftButtonPressed()));
    connect(ui->rightButton,SIGNAL(pressed()), this, SLOT(rightButtonPressed()));
    connect(ui->goButton,SIGNAL(pressed()), this, SLOT(goButtonPressed()));
    connect(ui->brakeButton,SIGNAL(pressed()), this, SLOT(stopButtonPressed()));
    
    connect(ui->leftButton,SIGNAL(released()), this, SLOT(leftButtonReleased()));
    connect(ui->rightButton,SIGNAL(released()), this, SLOT(rightButtonReleased()));
    connect(ui->goButton,SIGNAL(released()), this, SLOT(goButtonReleased()));
    connect(ui->brakeButton,SIGNAL(released()), this, SLOT(stopButtonReleased()));
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serverConnect()
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
                    ip = d.getIp();
                    port = d.getPort();
                    timer->stop();
               }
               else if(socket->state() == QAbstractSocket::ConnectedState)
               {
                    socket->disconnectFromHost();
                    socket->connectToHost(d.getIp(), d.getPort().toInt());
                    ip = d.getIp();
                    port = d.getPort();
               }
          }
     }

}

void MainWindow::serverDisconnect()
{
     if(socket->state() == QAbstractSocket::ConnectedState)
     {
          socket->disconnectFromHost();
          ui->statusBar->showMessage("Not connected");
          timer->stop();
          ui->ignitionOnButton->setEnabled(false);
          ui->ignitionOffButton->setEnabled(false);
     }
}


void MainWindow::connectionSuccess()
{
     ui->statusBar->showMessage("Connected to: " + ip +":" +port);
     qInfo()<<"start the timer";
     timer->start(timerDelay);        //in milliseconds,  1000ms = 1s
     ui->ignitionOnButton->setEnabled(true);
}

void MainWindow::displayError(QAbstractSocket::SocketError error)
{
     qInfo()<<"Failed to make a network connection!" << error;
     QString t = QString::number(error);
     ui->statusBar->showMessage("failed:"+t);
}

void MainWindow::heartBeat()
{
     QTextStream out(socket);
     out << HEART_BEAT;
     out << "\n";
}

void MainWindow::getStuff()
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
     ui->textBrowser->append(temp);
     QStringList pieces = temp.split(",");
     if (pieces.size() == 5)
     {
          ui->heading->setText(pieces[1]);
          ui->ticks->setText(pieces[2]);
          ui->revolutions->setText(pieces[3]);
     }
}

void MainWindow::ignitionOn()
{
     QTextStream out(socket);
     out << START_IGNITION;
     out << "\n";
     //disable this button and enable the ignition off
     ui->ignitionOnButton->setEnabled(false);
     ui->ignitionOffButton->setEnabled(true);
}

void MainWindow::ignitionOff()
{
     QTextStream out(socket);
     out << STOP_IGNITION;
     out << "\n";
     ui->ignitionOnButton->setEnabled(true);
     ui->ignitionOffButton->setEnabled(false);
}

/*!
 * red = 0
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


void MainWindow::buttonPress(int button)
{
     switch(button)
     {
          case 0:
               //qInfo()<<"go forward";
               startForward();
               ui->goButton->setDown(true);
          break;
          case 1:
               //qInfo()<<"start the brakes";
               startBrakes();
               ui->brakeButton->setDown(true);
          break;
     }
}

void MainWindow::buttonRelease(int button)
{
     switch(button)
     {
          case 0:
               //qInfo()<<"stop forward";
               stopForward();
               ui->goButton->setDown(false);
          break;
          case 1:
               //qInfo()<<"stop the brakes";
               stopBrakes();
               ui->brakeButton->setDown(false);
          break;
     }
}

void MainWindow::axisEvent(int axis, int value)
{
     //part of the code that deals with the x-axis
     if (axis == 0 && value == -32768)
     {
          //qDebug()<<"left";
          goLeft();
          ui->leftButton->setDown(true);
          startleft = 1;
     }
     if (axis == 0 && value == 32767)
     {
          //qDebug()<<"right";
          goRight();
          ui->rightButton->setDown(true);
          startright = 1;
     }
     if (axis == 0 && value == 0)
     {
          if (startleft == 1)
          {
               //qDebug()<<"stop left";
               stopLeft();
               ui->leftButton->setDown(false);
               startleft = 0;
          }
          if(startright == 1)
          {
               stopRight();
               startright = 0;
               ui->rightButton->setDown(false);
          }
     }
}

void MainWindow::leftButtonPressed()
{
     //qInfo()<<"left button";
     goLeft();
     //ui->textBrowser->setText("some text here");
}

void MainWindow::rightButtonPressed()
{
     //qInfo()<<"right button";
     goRight();
}

void MainWindow::goButtonPressed()
{
     //qInfo()<<"go button";
     startForward();
}

void MainWindow::stopButtonPressed()
{
     //qInfo()<<"stop";
     startBrakes();
}

void MainWindow::leftButtonReleased()
{
     stopLeft();
}

void MainWindow::rightButtonReleased()
{
     stopRight();
}

void MainWindow::goButtonReleased()
{
     stopForward();
}

void MainWindow::stopButtonReleased()
{
     stopBrakes();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
     if (!event->isAutoRepeat())
     {
          //qInfo()<<event->key();
          switch(event->key())
          {
               case Qt::Key_A:
                    ui->leftButton->setDown(true);
                    goLeft();
               break;
               case Qt::Key_D:
                    ui->rightButton->setDown(true);
                    goRight();
               break;
               case Qt::Key_J:
                    ui->goButton->setDown(true);
                    startForward();
               break;
               case Qt::Key_L:
                    ui->brakeButton->setDown(true);
                    startBrakes();
               default:
                    //don't care about any of the other keys
                    QWidget::keyPressEvent(event);
          }
     }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
     if (!event->isAutoRepeat())
     {
          switch(event->key())
          {
               case Qt::Key_A:
                    ui->leftButton->setDown(false);
                    stopLeft();
               break;
               case Qt::Key_D:
                    ui->rightButton->setDown(false);
                    stopRight();
               break;
               case Qt::Key_J:
                    ui->goButton->setDown(false);
                    stopForward();
               break;
               case Qt::Key_L:
                    ui->brakeButton->setDown(false);
                    stopBrakes();               
               default:
                    QWidget::keyPressEvent(event);
          }
     }
}


void MainWindow::goLeft()
{
     //qInfo()<<"going left";
     QTextStream out(socket);
     out << START_VEHICLE_LEFT;
     out << "\n";
}
void MainWindow::stopLeft()
{
//      //qInfo()<<"stop left";
     QTextStream out(socket);
     out << STOP_VEHICLE_LEFT;
     out << "\n";
}

void MainWindow::goRight()
{
     QTextStream out(socket);
     out << START_VEHICLE_RIGHT;
     out << "\n";
}
void MainWindow::stopRight()
{
     QTextStream out(socket);
     out << STOP_VEHICLE_RIGHT;
     out << "\n";
}

void MainWindow::startForward()
{
     QTextStream out(socket);
     out << START_VEHICLE_FORWARD;
     out << "\n";

}
void MainWindow::stopForward()
{
     QTextStream out(socket);
     out << STOP_VEHICLE_FORWARD;
     out << "\n";
}

void MainWindow::startBrakes()
{
     QTextStream out(socket);
     out << START_BRAKES;
     out << "\n";
}

void MainWindow::stopBrakes()
{
     QTextStream out(socket);
     out << STOP_BRAKES;
     out << "\n";
}
