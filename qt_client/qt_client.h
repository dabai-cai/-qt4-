#ifndef QT_CLIENT_H
#define QT_CLIENT_H

#include <QtGui/QWidget>
#include "ui_qt_client.h"
#include "recv_thd.h"
class qt_client : public QWidget
{
    Q_OBJECT

public:
    qt_client(QWidget *parent = 0);
    ~qt_client();

private:
    Ui::qt_clientClass ui;
    recv_thd thd;
private slots:
	void send_msg();
    void conn();
public slots:
    void update_msg(QString s);
	void err_msg_update(QString);
};

#endif // QT_CLIENT_H
