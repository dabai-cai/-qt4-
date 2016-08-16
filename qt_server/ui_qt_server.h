/********************************************************************************
** Form generated from reading UI file 'qt_server.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SERVER_H
#define UI_QT_SERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_serverClass
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QWidget *qt_serverClass)
    {
        if (qt_serverClass->objectName().isEmpty())
            qt_serverClass->setObjectName(QString::fromUtf8("qt_serverClass"));
        qt_serverClass->resize(665, 473);
        pushButton = new QPushButton(qt_serverClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 410, 80, 27));
        lineEdit = new QLineEdit(qt_serverClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 350, 391, 121));
        textEdit = new QTextEdit(qt_serverClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 581, 311));
        textEdit->setReadOnly(true);

        retranslateUi(qt_serverClass);

        QMetaObject::connectSlotsByName(qt_serverClass);
    } // setupUi

    void retranslateUi(QWidget *qt_serverClass)
    {
        qt_serverClass->setWindowTitle(QApplication::translate("qt_serverClass", "qt_server", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("qt_serverClass", "send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qt_serverClass: public Ui_qt_serverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_H
