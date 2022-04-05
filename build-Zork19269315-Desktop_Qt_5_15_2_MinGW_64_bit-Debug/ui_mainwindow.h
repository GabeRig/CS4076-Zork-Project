/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *upButton;
    QTextEdit *textEdit;
    QPushButton *bButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *aButton;
    QPushButton *selectButton;
    QPushButton *startButton;
    QLabel *Background;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QListWidget *listWidget;
    QPushButton *xButton;
    QPushButton *yButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(430, 570);
        MainWindow->setMinimumSize(QSize(430, 570));
        MainWindow->setMaximumSize(QSize(430, 570));
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        upButton = new QPushButton(centralwidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(87, 313, 34, 27));
        upButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(89, 71, 171, 136));
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(103, 151, 72);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
""));
        textEdit->setReadOnly(true);
        bButton = new QPushButton(centralwidget);
        bButton->setObjectName(QString::fromUtf8("bButton"));
        bButton->setGeometry(QRect(220, 276, 65, 53));
        bButton->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        bButton->setIconSize(QSize(16, 16));
        downButton = new QPushButton(centralwidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(87, 364, 35, 27));
        downButton->setAutoFillBackground(false);
        downButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        leftButton = new QPushButton(centralwidget);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setGeometry(QRect(58, 338, 30, 28));
        leftButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        rightButton = new QPushButton(centralwidget);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setGeometry(QRect(119, 338, 32, 28));
        rightButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        aButton = new QPushButton(centralwidget);
        aButton->setObjectName(QString::fromUtf8("aButton"));
        aButton->setGeometry(QRect(309, 252, 65, 53));
        aButton->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(186, 186, 186);\n"
"border: none;\n"
""));
        selectButton = new QPushButton(centralwidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(102, 448, 32, 27));
        selectButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 119, 119);\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(165, 447, 33, 27));
        startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 119, 119);\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        Background = new QLabel(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setEnabled(true);
        Background->setGeometry(QRect(0, 0, 431, 571));
        Background->setStyleSheet(QString::fromUtf8(""));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/res/background.png")));
        Background->setScaledContents(true);
        Background->setTextInteractionFlags(Qt::NoTextInteraction);
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(260, 71, 82, 36));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(103, 151, 72);\n"
"color: rgb(0, 0, 0);\n"
"border: none;\n"
""));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(260, 106, 82, 36));
        textEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(103, 151, 72);\n"
"color: rgb(0, 0, 0);\n"
"border: none;"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(260, 140, 82, 67));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(103, 151, 72);\n"
"color: rgb(0, 0, 0);\n"
"border: none;"));
        xButton = new QPushButton(centralwidget);
        xButton->setObjectName(QString::fromUtf8("xButton"));
        xButton->setGeometry(QRect(220, 349, 65, 53));
        xButton->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        yButton = new QPushButton(centralwidget);
        yButton->setObjectName(QString::fromUtf8("yButton"));
        yButton->setGeometry(QRect(309, 325, 65, 53));
        yButton->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(186, 186, 186);\n"
"border: none;"));
        MainWindow->setCentralWidget(centralwidget);
        Background->raise();
        upButton->raise();
        textEdit->raise();
        downButton->raise();
        leftButton->raise();
        rightButton->raise();
        aButton->raise();
        selectButton->raise();
        startButton->raise();
        bButton->raise();
        textEdit_2->raise();
        textEdit_3->raise();
        listWidget->raise();
        xButton->raise();
        yButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        bButton->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        downButton->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        aButton->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        selectButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        Background->setText(QString());
        xButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        yButton->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
