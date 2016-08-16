
--------------------------------------------------------------------------

#ifndef SERIAL_H

#define SERIAL_H

#include <QObject>

#include <QtSerialPort/QSerialPort>

class Serial : public QObject

{

    Q_OBJECT

public:

    explicit Serial(QObject *parent = 0);

    ~Serial(void);

    QSerialPort *port;



signals:



public slots:

    void readData(void);

    void threadStarted(void);

    void threadFinished(void);



};

#endif // SERIAL_H

--------------------------------------------------------------------------




--------------------------------------------------------------------------

#include "serial.h"

#include <QMessageBox>

#include <QDebug>

#include <QThread>

Serial::Serial(QObject *parent) :

    QObject(parent)

{

    port = new QSerialPort();

    port->setPortName("COM1");

    if(!port->open(QSerialPort::ReadWrite))

    {

        QMessageBox WrrMsg;

        WrrMsg.setInformativeText("无法打开该串口");

        WrrMsg.show();

        WrrMsg.exec();

    }

    port->setBaudRate(QSerialPort::Baud19200,QSerialPort::AllDirections);   // 19200,N,8,1

    port->setDataBits(QSerialPort::Data8);

    port->setStopBits(QSerialPort::OneStop);

    port->setParity(QSerialPort::NoParity);

    port->setFlowControl(QSerialPort::NoFlowControl);

    connect(port, SIGNAL(readyRead()), this, SLOT(readData()), Qt::DirectConnection);   // 注意，真正执行时 port 与 Serial 在同一个线程中，因此使用 Qt::DirectConnection。

}

Serial::~Serial(void)

{

}

void Serial::readData(void)

{

    qDebug()<< "Reading Data...ID is:" << QThread::currentThreadId();

    port->clear(QSerialPort::AllDirections);

}

void Serial::threadStarted(void)

{

    qDebug()<< "Thread has started...ID is:" << QThread::currentThreadId();

}

void Serial::threadFinished(void)

{

    qDebug()<< "Closing COM port...ID is:" << QThread::currentThreadId();

    if(port->isOpen())

    {

        port->close();      // 关闭串口。

    }

}









--------------------------------------------------------------------------

#ifndef UIWINDOW_H

#define UIWINDOW_H

#include <QMainWindow>

#include <QThread>

#include "serial.h"

namespace Ui {

class UIWindow;

}

class UIWindow : public QMainWindow

{

    Q_OBJECT



public:

    explicit UIWindow(QWidget *parent = 0);

    ~UIWindow();

private:

    Ui::UIWindow *ui;

    QThread serialThread;

    Serial *serial;

};

#endif // UIWINDOW_H




#include "uiwindow.h"

#include "ui_uiwindow.h"

#include <QDebug>

UIWindow::UIWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::UIWindow)

{

    ui->setupUi(this);

    qDebug()<< "UI thread ID is:" << QThread::currentThreadId();

    serial = new Serial();

    connect(&serialThread, SIGNAL(started()), serial, SLOT(threadStarted()), Qt::QueuedConnection);     // 注意，serialThread 与 serial 并不在同一个线程中，因此使用 Qt::QueuedConnection。

    connect(&serialThread, SIGNAL(finished()), serial, SLOT(threadFinished()), Qt::DirectConnection);   // serialThread 的 finished() 信号是在新线程中执行的，因此此处要使用 Qt::DirectConnection。

    serialThread.start(QThread::HighestPriority);   // 开启线程，串口接收线程的优先级较高。

    serial->moveToThread(&serialThread);            // 将串口接受对象移动到新线程中。

    serial->port->moveToThread(&serialThread);      // 用于接收的 port 一并移入新线程中。

}

UIWindow::~UIWindow()

{

    if(serialThread.isRunning())

    {

serialThread.exit();                // 结束该线程。

        serialThread.wait();

        /*while(!serialThread.isFinished())

        {

            ;

        }*/

    }

    delete ui;

}
