#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "Joystick.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void keyPressEvent(QKeyEvent *event);
    
    void keyReleaseEvent(QKeyEvent *event);
    
    void goLeft();
    void stopLeft();
    
    void goRight();
    void stopRight();
    
    void startForward();
    void stopForward();
    
    void startBrakes();
    void stopBrakes();
    
public slots:
     
     void connectionSuccess();
     void displayError(QAbstractSocket::SocketError);
     
     void serverConnect();
     void serverDisconnect();
     
     void getStuff();
     
     void heartBeat();
     
     void ignitionOn();
     void ignitionOff();     
     
     void leftButtonPressed();
     void rightButtonPressed();
     void goButtonPressed();
     void stopButtonPressed();
     
     void leftButtonReleased();
     void rightButtonReleased();
     void goButtonReleased();
     void stopButtonReleased();
     
     void buttonPress(int button);
     void buttonRelease(int button);
     void axisEvent(int axis, int value);
     
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    
    QString ip;
    QString port;
    
     QTimer *timer;
     int timerDelay;
     
     Joystick *joystick;
     
     int startleft;
     int startright;
     
    
};

#endif // MAINWINDOW_H
