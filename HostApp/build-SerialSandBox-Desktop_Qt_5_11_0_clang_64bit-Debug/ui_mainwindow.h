/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *RefreshPortList_Button;
    QComboBox *PortList_ComboBox;
    QComboBox *BaudRate_ComboBox;
    QLabel *label;
    QSpinBox *TimeOut_spinBox;
    QHBoxLayout *horizontalLayout_9;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QComboBox *GalvoTask_ComboBox;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *Xaxis_CheckBox;
    QLineEdit *Xaxis_LineEdit;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *Yaxis_CheckBox;
    QLineEdit *Yaxis_LineEdit;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *GalvoSpeed_CheckBox;
    QLineEdit *GalvoSpeed_LineEdit;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *LaserTask_ComboBox;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *LaserPower_CheckBox;
    QLineEdit *LaserPower_LineEdit;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_7;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_8;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout;
    QLineEdit *CommandInput_LineEdit;
    QPushButton *ClearTerminal_Button;
    QPushButton *SendCommand_Button;
    QSplitter *splitter;
    QTextBrowser *Reply_textBrowser;
    QTextBrowser *Error_textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(590, 632);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        RefreshPortList_Button = new QPushButton(centralWidget);
        RefreshPortList_Button->setObjectName(QStringLiteral("RefreshPortList_Button"));

        horizontalLayout_2->addWidget(RefreshPortList_Button);

        PortList_ComboBox = new QComboBox(centralWidget);
        PortList_ComboBox->addItem(QString());
        PortList_ComboBox->setObjectName(QStringLiteral("PortList_ComboBox"));

        horizontalLayout_2->addWidget(PortList_ComboBox);

        BaudRate_ComboBox = new QComboBox(centralWidget);
        BaudRate_ComboBox->addItem(QString());
        BaudRate_ComboBox->setObjectName(QStringLiteral("BaudRate_ComboBox"));

        horizontalLayout_2->addWidget(BaudRate_ComboBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        TimeOut_spinBox = new QSpinBox(centralWidget);
        TimeOut_spinBox->setObjectName(QStringLiteral("TimeOut_spinBox"));
        TimeOut_spinBox->setMinimum(100);
        TimeOut_spinBox->setMaximum(2000);

        horizontalLayout_2->addWidget(TimeOut_spinBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        GalvoTask_ComboBox = new QComboBox(frame);
        GalvoTask_ComboBox->addItem(QString());
        GalvoTask_ComboBox->addItem(QString());
        GalvoTask_ComboBox->addItem(QString());
        GalvoTask_ComboBox->addItem(QString());
        GalvoTask_ComboBox->setObjectName(QStringLiteral("GalvoTask_ComboBox"));

        verticalLayout->addWidget(GalvoTask_ComboBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        Xaxis_CheckBox = new QCheckBox(frame);
        Xaxis_CheckBox->setObjectName(QStringLiteral("Xaxis_CheckBox"));

        horizontalLayout_7->addWidget(Xaxis_CheckBox);

        Xaxis_LineEdit = new QLineEdit(frame);
        Xaxis_LineEdit->setObjectName(QStringLiteral("Xaxis_LineEdit"));

        horizontalLayout_7->addWidget(Xaxis_LineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        Yaxis_CheckBox = new QCheckBox(frame);
        Yaxis_CheckBox->setObjectName(QStringLiteral("Yaxis_CheckBox"));

        horizontalLayout_8->addWidget(Yaxis_CheckBox);

        Yaxis_LineEdit = new QLineEdit(frame);
        Yaxis_LineEdit->setObjectName(QStringLiteral("Yaxis_LineEdit"));

        horizontalLayout_8->addWidget(Yaxis_LineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        GalvoSpeed_CheckBox = new QCheckBox(frame);
        GalvoSpeed_CheckBox->setObjectName(QStringLiteral("GalvoSpeed_CheckBox"));

        horizontalLayout_3->addWidget(GalvoSpeed_CheckBox);

        GalvoSpeed_LineEdit = new QLineEdit(frame);
        GalvoSpeed_LineEdit->setObjectName(QStringLiteral("GalvoSpeed_LineEdit"));

        horizontalLayout_3->addWidget(GalvoSpeed_LineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_9->addWidget(frame);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LaserTask_ComboBox = new QComboBox(frame_2);
        LaserTask_ComboBox->addItem(QString());
        LaserTask_ComboBox->addItem(QString());
        LaserTask_ComboBox->addItem(QString());
        LaserTask_ComboBox->setObjectName(QStringLiteral("LaserTask_ComboBox"));

        verticalLayout_2->addWidget(LaserTask_ComboBox);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        LaserPower_CheckBox = new QCheckBox(frame_2);
        LaserPower_CheckBox->setObjectName(QStringLiteral("LaserPower_CheckBox"));

        horizontalLayout_11->addWidget(LaserPower_CheckBox);

        LaserPower_LineEdit = new QLineEdit(frame_2);
        LaserPower_LineEdit->setObjectName(QStringLiteral("LaserPower_LineEdit"));

        horizontalLayout_11->addWidget(LaserPower_LineEdit);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        checkBox_7 = new QCheckBox(frame_2);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout_12->addWidget(checkBox_7);

        lineEdit_7 = new QLineEdit(frame_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_12->addWidget(lineEdit_7);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        checkBox_8 = new QCheckBox(frame_2);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        horizontalLayout_13->addWidget(checkBox_8);

        lineEdit_8 = new QLineEdit(frame_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_13->addWidget(lineEdit_8);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout_9->addWidget(frame_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CommandInput_LineEdit = new QLineEdit(centralWidget);
        CommandInput_LineEdit->setObjectName(QStringLiteral("CommandInput_LineEdit"));

        horizontalLayout->addWidget(CommandInput_LineEdit);

        ClearTerminal_Button = new QPushButton(centralWidget);
        ClearTerminal_Button->setObjectName(QStringLiteral("ClearTerminal_Button"));

        horizontalLayout->addWidget(ClearTerminal_Button);

        SendCommand_Button = new QPushButton(centralWidget);
        SendCommand_Button->setObjectName(QStringLiteral("SendCommand_Button"));

        horizontalLayout->addWidget(SendCommand_Button);


        verticalLayout_3->addLayout(horizontalLayout);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        Reply_textBrowser = new QTextBrowser(splitter);
        Reply_textBrowser->setObjectName(QStringLiteral("Reply_textBrowser"));
        splitter->addWidget(Reply_textBrowser);
        Error_textBrowser = new QTextBrowser(splitter);
        Error_textBrowser->setObjectName(QStringLiteral("Error_textBrowser"));
        splitter->addWidget(Error_textBrowser);

        verticalLayout_3->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 590, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(RefreshPortList_Button, BaudRate_ComboBox);
        QWidget::setTabOrder(BaudRate_ComboBox, PortList_ComboBox);
        QWidget::setTabOrder(PortList_ComboBox, TimeOut_spinBox);
        QWidget::setTabOrder(TimeOut_spinBox, CommandInput_LineEdit);
        QWidget::setTabOrder(CommandInput_LineEdit, SendCommand_Button);
        QWidget::setTabOrder(SendCommand_Button, Reply_textBrowser);
        QWidget::setTabOrder(Reply_textBrowser, Error_textBrowser);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        RefreshPortList_Button->setText(QApplication::translate("MainWindow", "Refresh Port List", nullptr));
        PortList_ComboBox->setItemText(0, QApplication::translate("MainWindow", "Ports", nullptr));

        BaudRate_ComboBox->setItemText(0, QApplication::translate("MainWindow", "Baud Rate", nullptr));

        label->setText(QApplication::translate("MainWindow", "Timeout: [ms]", nullptr));
        GalvoTask_ComboBox->setItemText(0, QApplication::translate("MainWindow", "Disable", nullptr));
        GalvoTask_ComboBox->setItemText(1, QApplication::translate("MainWindow", "Enable", nullptr));
        GalvoTask_ComboBox->setItemText(2, QApplication::translate("MainWindow", "Absolute Move", nullptr));
        GalvoTask_ComboBox->setItemText(3, QApplication::translate("MainWindow", "Relative Move", nullptr));

        Xaxis_CheckBox->setText(QApplication::translate("MainWindow", "X Axis", nullptr));
        Xaxis_LineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        Yaxis_CheckBox->setText(QApplication::translate("MainWindow", "Y Axis", nullptr));
        Yaxis_LineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        GalvoSpeed_CheckBox->setText(QApplication::translate("MainWindow", "Speed", nullptr));
        GalvoSpeed_LineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        LaserTask_ComboBox->setItemText(0, QApplication::translate("MainWindow", "Disable", nullptr));
        LaserTask_ComboBox->setItemText(1, QApplication::translate("MainWindow", "Enable", nullptr));
        LaserTask_ComboBox->setItemText(2, QApplication::translate("MainWindow", "Option", nullptr));

        LaserPower_CheckBox->setText(QApplication::translate("MainWindow", "Power", nullptr));
        LaserPower_LineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        checkBox_7->setText(QApplication::translate("MainWindow", "Option", nullptr));
        lineEdit_7->setText(QApplication::translate("MainWindow", "0", nullptr));
        checkBox_8->setText(QApplication::translate("MainWindow", "Option", nullptr));
        lineEdit_8->setText(QApplication::translate("MainWindow", "0", nullptr));
        CommandInput_LineEdit->setText(QString());
        ClearTerminal_Button->setText(QApplication::translate("MainWindow", "Clear Terminal", nullptr));
        SendCommand_Button->setText(QApplication::translate("MainWindow", "Send", nullptr));
        Reply_textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Error_textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
