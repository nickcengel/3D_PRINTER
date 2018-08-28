/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QTreeView *MenuTree;
    QStackedWidget *stackedWidget;
    QWidget *aboutPage;
    QWidget *helpPage;
    QWidget *settingsPage;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *settings_button_resetToDefault;
    QPushButton *settings_button_openFile;
    QPushButton *settings_buttons_saveFile;
    QPushButton *settings_button_apply;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QTreeView *settings_view;
    QSpacerItem *horizontalSpacer_8;
    QWidget *portPage;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *settings_button_refreshPorts;
    QSpacerItem *horizontalSpacer_4;
    QTreeView *port_view;
    QWidget *printToolsPage;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_7;
    QPushButton *settings_button_openFile_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *settings_button_apply_2;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout;
    QTableView *PartInfoView;
    QTableView *PartInfoView_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *label;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_8;
    QPushButton *settings_buttons_saveFile_2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *dashboardPage;
    QWidget *widget;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_22;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_41;
    QLabel *label_42;
    QFrame *frame_23;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_44;
    QLabel *label_45;
    QFrame *frame_24;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_47;
    QLabel *label_48;
    QFrame *frame_25;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_50;
    QLabel *label_51;
    QFrame *frame_26;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_53;
    QLabel *label_54;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1080, 640);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QLatin1String("background:rgb(22, 22, 22);\n"
""));
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Widget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setStyleSheet(QStringLiteral(""));
        splitter->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(210, 16777215));
        frame_2->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 30), stop:1 rgba(212, 215, 217, 40));\n"
"\n"
"\n"
"border-radius: 8;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        MenuTree = new QTreeView(frame_2);
        MenuTree->setObjectName(QStringLiteral("MenuTree"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MenuTree->sizePolicy().hasHeightForWidth());
        MenuTree->setSizePolicy(sizePolicy1);
        MenuTree->setMinimumSize(QSize(150, 0));
        MenuTree->setMaximumSize(QSize(300, 16777215));
        MenuTree->setStyleSheet(QLatin1String("background:rgba(0,0,0,0);\n"
"color:white;\n"
""));
        MenuTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        MenuTree->setProperty("showDropIndicator", QVariant(false));
        MenuTree->setAnimated(true);
        MenuTree->setHeaderHidden(true);
        MenuTree->header()->setDefaultSectionSize(150);
        MenuTree->header()->setMinimumSectionSize(150);

        verticalLayout->addWidget(MenuTree);

        splitter->addWidget(frame_2);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setStyleSheet(QLatin1String("border-radius: 8;\n"
""));
        stackedWidget->setFrameShape(QFrame::Box);
        aboutPage = new QWidget();
        aboutPage->setObjectName(QStringLiteral("aboutPage"));
        aboutPage->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(aboutPage);
        helpPage = new QWidget();
        helpPage->setObjectName(QStringLiteral("helpPage"));
        helpPage->setStyleSheet(QStringLiteral(""));
        stackedWidget->addWidget(helpPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName(QStringLiteral("settingsPage"));
        settingsPage->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(settingsPage);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        frame = new QFrame(settingsPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(640, 56));
        frame->setMaximumSize(QSize(16777215, 56));
        QFont font;
        font.setPointSize(14);
        frame->setFont(font);
        frame->setStyleSheet(QLatin1String("background:\n"
"rgba(0,0,0,0);\n"
"\n"
"border-radius: 8;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        settings_button_resetToDefault = new QPushButton(frame);
        settings_button_resetToDefault->setObjectName(QStringLiteral("settings_button_resetToDefault"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(settings_button_resetToDefault->sizePolicy().hasHeightForWidth());
        settings_button_resetToDefault->setSizePolicy(sizePolicy3);
        settings_button_resetToDefault->setMinimumSize(QSize(32, 32));
        settings_button_resetToDefault->setFont(font);
        settings_button_resetToDefault->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/iosUndoOutline.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_resetToDefault->setIcon(icon);
        settings_button_resetToDefault->setIconSize(QSize(30, 30));
        settings_button_resetToDefault->setFlat(true);

        horizontalLayout_4->addWidget(settings_button_resetToDefault);

        settings_button_openFile = new QPushButton(frame);
        settings_button_openFile->setObjectName(QStringLiteral("settings_button_openFile"));
        sizePolicy3.setHeightForWidth(settings_button_openFile->sizePolicy().hasHeightForWidth());
        settings_button_openFile->setSizePolicy(sizePolicy3);
        settings_button_openFile->setMinimumSize(QSize(32, 32));
        settings_button_openFile->setBaseSize(QSize(270, 484));
        settings_button_openFile->setFont(font);
        settings_button_openFile->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/iosDownload.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_openFile->setIcon(icon1);
        settings_button_openFile->setIconSize(QSize(30, 30));
        settings_button_openFile->setFlat(true);

        horizontalLayout_4->addWidget(settings_button_openFile);

        settings_buttons_saveFile = new QPushButton(frame);
        settings_buttons_saveFile->setObjectName(QStringLiteral("settings_buttons_saveFile"));
        sizePolicy3.setHeightForWidth(settings_buttons_saveFile->sizePolicy().hasHeightForWidth());
        settings_buttons_saveFile->setSizePolicy(sizePolicy3);
        settings_buttons_saveFile->setMinimumSize(QSize(32, 32));
        settings_buttons_saveFile->setBaseSize(QSize(270, 484));
        settings_buttons_saveFile->setFont(font);
        settings_buttons_saveFile->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/iosUpload.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_buttons_saveFile->setIcon(icon2);
        settings_buttons_saveFile->setIconSize(QSize(30, 30));
        settings_buttons_saveFile->setFlat(true);

        horizontalLayout_4->addWidget(settings_buttons_saveFile);

        settings_button_apply = new QPushButton(frame);
        settings_button_apply->setObjectName(QStringLiteral("settings_button_apply"));
        sizePolicy3.setHeightForWidth(settings_button_apply->sizePolicy().hasHeightForWidth());
        settings_button_apply->setSizePolicy(sizePolicy3);
        settings_button_apply->setMinimumSize(QSize(32, 32));
        settings_button_apply->setFont(font);
        settings_button_apply->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/iosRedo.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_apply->setIcon(icon3);
        settings_button_apply->setIconSize(QSize(30, 30));
        settings_button_apply->setFlat(true);

        horizontalLayout_4->addWidget(settings_button_apply);


        verticalLayout_2->addWidget(frame);

        frame_3 = new QFrame(settingsPage);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy4);
        frame_3->setMinimumSize(QSize(512, 256));
        frame_3->setMaximumSize(QSize(16777215, 16777215));
        frame_3->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 12), stop:1 rgba(128, 128, 128, 35));\n"
"\n"
"\n"
"\n"
"border-radius: 8;\n"
"color: rgb(212,215,217);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame_3);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalSpacer_5 = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(64, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        settings_view = new QTreeView(frame_3);
        settings_view->setObjectName(QStringLiteral("settings_view"));
        sizePolicy4.setHeightForWidth(settings_view->sizePolicy().hasHeightForWidth());
        settings_view->setSizePolicy(sizePolicy4);
        settings_view->setMinimumSize(QSize(512, 256));
        settings_view->setMaximumSize(QSize(512, 16777215));
        settings_view->setFont(font);
        settings_view->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"\n"
"\n"
"border-radius: 8;\n"
"color: rgba(212,215,217,210);"));
        settings_view->setFrameShape(QFrame::NoFrame);
        settings_view->setFrameShadow(QFrame::Plain);
        settings_view->setSelectionBehavior(QAbstractItemView::SelectItems);
        settings_view->setHeaderHidden(true);
        settings_view->header()->setVisible(false);
        settings_view->header()->setCascadingSectionResizes(false);
        settings_view->header()->setDefaultSectionSize(250);
        settings_view->header()->setMinimumSectionSize(200);
        settings_view->header()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(settings_view);

        horizontalSpacer_8 = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout_13->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(frame_3);


        horizontalLayout_3->addLayout(verticalLayout_2);

        stackedWidget->addWidget(settingsPage);
        portPage = new QWidget();
        portPage->setObjectName(QStringLiteral("portPage"));
        horizontalLayout_6 = new QHBoxLayout(portPage);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        frame_4 = new QFrame(portPage);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        settings_button_refreshPorts = new QPushButton(frame_4);
        settings_button_refreshPorts->setObjectName(QStringLiteral("settings_button_refreshPorts"));
        sizePolicy3.setHeightForWidth(settings_button_refreshPorts->sizePolicy().hasHeightForWidth());
        settings_button_refreshPorts->setSizePolicy(sizePolicy3);
        settings_button_refreshPorts->setMinimumSize(QSize(32, 32));
        settings_button_refreshPorts->setBaseSize(QSize(270, 484));
        settings_button_refreshPorts->setFont(font);
        settings_button_refreshPorts->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/icon_w_spin1.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_refreshPorts->setIcon(icon4);
        settings_button_refreshPorts->setIconSize(QSize(30, 30));
        settings_button_refreshPorts->setFlat(true);

        horizontalLayout_5->addWidget(settings_button_refreshPorts);

        horizontalSpacer_4 = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(frame_4);

        port_view = new QTreeView(portPage);
        port_view->setObjectName(QStringLiteral("port_view"));
        port_view->setMaximumSize(QSize(2160, 2160));
        port_view->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 12), stop:1 rgba(128, 128, 128, 35));\n"
"\n"
"\n"
"\n"
"border-radius: 8;\n"
"color: rgb(212,215,217);"));
        port_view->setFrameShape(QFrame::NoFrame);
        port_view->setFrameShadow(QFrame::Plain);
        port_view->setHeaderHidden(true);
        port_view->header()->setDefaultSectionSize(125);
        port_view->header()->setMinimumSectionSize(125);

        verticalLayout_3->addWidget(port_view);


        horizontalLayout_6->addLayout(verticalLayout_3);

        stackedWidget->addWidget(portPage);
        printToolsPage = new QWidget();
        printToolsPage->setObjectName(QStringLiteral("printToolsPage"));
        printToolsPage->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(printToolsPage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame_6 = new QFrame(printToolsPage);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        sizePolicy4.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy4);
        frame_6->setMinimumSize(QSize(512, 256));
        frame_6->setMaximumSize(QSize(16777215, 16777215));
        frame_6->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 12), stop:1 rgba(128, 128, 128, 35));\n"
"\n"
"\n"
"\n"
"border-radius: 8;\n"
"color: rgb(212,215,217);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_6);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMaximumSize(QSize(16777215, 235));
        frame_5->setStyleSheet(QStringLiteral("background:rgb(22, 22, 22,);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        settings_button_openFile_2 = new QPushButton(frame_5);
        settings_button_openFile_2->setObjectName(QStringLiteral("settings_button_openFile_2"));
        sizePolicy3.setHeightForWidth(settings_button_openFile_2->sizePolicy().hasHeightForWidth());
        settings_button_openFile_2->setSizePolicy(sizePolicy3);
        settings_button_openFile_2->setMinimumSize(QSize(32, 32));
        settings_button_openFile_2->setBaseSize(QSize(270, 484));
        settings_button_openFile_2->setFont(font);
        settings_button_openFile_2->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        settings_button_openFile_2->setIcon(icon1);
        settings_button_openFile_2->setIconSize(QSize(30, 30));
        settings_button_openFile_2->setFlat(true);

        verticalLayout_7->addWidget(settings_button_openFile_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(25);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        radioButton_2 = new QRadioButton(frame_5);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setAutoExclusive(false);

        verticalLayout_6->addWidget(radioButton_2);

        radioButton = new QRadioButton(frame_5);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setAutoExclusive(false);

        verticalLayout_6->addWidget(radioButton);

        radioButton_3 = new QRadioButton(frame_5);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setAutoExclusive(false);

        verticalLayout_6->addWidget(radioButton_3);


        horizontalLayout_8->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_8);

        settings_button_apply_2 = new QPushButton(frame_5);
        settings_button_apply_2->setObjectName(QStringLiteral("settings_button_apply_2"));
        sizePolicy3.setHeightForWidth(settings_button_apply_2->sizePolicy().hasHeightForWidth());
        settings_button_apply_2->setSizePolicy(sizePolicy3);
        settings_button_apply_2->setMinimumSize(QSize(32, 32));
        settings_button_apply_2->setFont(font);
        settings_button_apply_2->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/iosTrash.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_apply_2->setIcon(icon5);
        settings_button_apply_2->setIconSize(QSize(30, 30));
        settings_button_apply_2->setFlat(true);

        verticalLayout_7->addWidget(settings_button_apply_2);


        horizontalLayout_7->addWidget(frame_5);

        frame_7 = new QFrame(frame_6);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setMaximumSize(QSize(512, 235));
        frame_7->setStyleSheet(QLatin1String("background:rgba(22, 22, 22);\n"
"border-radius: 8;\n"
""));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_7);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PartInfoView = new QTableView(frame_7);
        PartInfoView->setObjectName(QStringLiteral("PartInfoView"));
        PartInfoView->setMinimumSize(QSize(0, 200));
        PartInfoView->setMaximumSize(QSize(16777215, 200));
        PartInfoView->setStyleSheet(QLatin1String("background:rgb(22, 22, 22);\n"
"border-radius: 0;\n"
""));
        PartInfoView->setShowGrid(false);
        PartInfoView->horizontalHeader()->setVisible(false);
        PartInfoView->horizontalHeader()->setHighlightSections(false);
        PartInfoView->verticalHeader()->setVisible(false);
        PartInfoView->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(PartInfoView);

        PartInfoView_2 = new QTableView(frame_7);
        PartInfoView_2->setObjectName(QStringLiteral("PartInfoView_2"));
        PartInfoView_2->setMinimumSize(QSize(0, 200));
        PartInfoView_2->setMaximumSize(QSize(16777215, 200));
        PartInfoView_2->setStyleSheet(QLatin1String("background:rgb(22, 22, 22);\n"
"border-radius: 0;\n"
""));
        PartInfoView_2->setShowGrid(false);
        PartInfoView_2->horizontalHeader()->setVisible(false);
        PartInfoView_2->horizontalHeader()->setHighlightSections(false);
        PartInfoView_2->verticalHeader()->setVisible(false);
        PartInfoView_2->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(PartInfoView_2);


        horizontalLayout_7->addWidget(frame_7);


        verticalLayout_10->addLayout(horizontalLayout_7);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label = new QLabel(frame_6);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("background: rgba(0,0,0,0)"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label);

        textBrowser = new QTextBrowser(frame_6);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setStyleSheet(QStringLiteral("background: rgb(22,22,22);"));

        verticalLayout_12->addWidget(textBrowser);


        verticalLayout_10->addLayout(verticalLayout_12);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        frame_8 = new QFrame(frame_6);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setMinimumSize(QSize(5, 0));
        frame_8->setMaximumSize(QSize(191, 56));
        frame_8->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 45), stop:1 rgba(212, 215, 217, 60));"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_8);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        settings_buttons_saveFile_2 = new QPushButton(frame_8);
        settings_buttons_saveFile_2->setObjectName(QStringLiteral("settings_buttons_saveFile_2"));
        sizePolicy3.setHeightForWidth(settings_buttons_saveFile_2->sizePolicy().hasHeightForWidth());
        settings_buttons_saveFile_2->setSizePolicy(sizePolicy3);
        settings_buttons_saveFile_2->setMinimumSize(QSize(32, 32));
        settings_buttons_saveFile_2->setBaseSize(QSize(270, 484));
        settings_buttons_saveFile_2->setFont(font);
        settings_buttons_saveFile_2->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/iosPlus.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_buttons_saveFile_2->setIcon(icon6);
        settings_buttons_saveFile_2->setIconSize(QSize(30, 30));
        settings_buttons_saveFile_2->setFlat(true);

        verticalLayout_8->addWidget(settings_buttons_saveFile_2);


        horizontalLayout_9->addWidget(frame_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout_5->addWidget(frame_6);

        stackedWidget->addWidget(printToolsPage);
        dashboardPage = new QWidget();
        dashboardPage->setObjectName(QStringLiteral("dashboardPage"));
        dashboardPage->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(dashboardPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(410, 30, 351, 461));
        verticalLayout_11 = new QVBoxLayout(widget);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        frame_22 = new QFrame(widget);
        frame_22->setObjectName(QStringLiteral("frame_22"));
        frame_22->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        horizontalLayout_22 = new QHBoxLayout(frame_22);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(6, 6, 6, 6);
        label_41 = new QLabel(frame_22);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setMaximumSize(QSize(66, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral(".SF NS Display Condensed"));
        font1.setPointSize(56);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_41->setFont(font1);
        label_41->setStyleSheet(QLatin1String("background: rgba(212,215,217,36);\n"
"color: rgba(141,158,198,180)"));
        label_41->setAlignment(Qt::AlignCenter);
        label_41->setMargin(-1);

        horizontalLayout_22->addWidget(label_41);

        label_42 = new QLabel(frame_22);
        label_42->setObjectName(QStringLiteral("label_42"));
        QFont font2;
        font2.setFamily(QStringLiteral(".SF NS Display Condensed"));
        font2.setPointSize(56);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_42->setFont(font2);
        label_42->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        label_42->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_42);


        verticalLayout_11->addWidget(frame_22);

        frame_23 = new QFrame(widget);
        frame_23->setObjectName(QStringLiteral("frame_23"));
        frame_23->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        frame_23->setFrameShape(QFrame::StyledPanel);
        frame_23->setFrameShadow(QFrame::Raised);
        horizontalLayout_23 = new QHBoxLayout(frame_23);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(6, 6, 6, 6);
        label_44 = new QLabel(frame_23);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setMaximumSize(QSize(66, 16777215));
        label_44->setFont(font1);
        label_44->setStyleSheet(QLatin1String("background: rgba(212,215,217,36);\n"
"color: rgba(141,158,198,180)"));
        label_44->setAlignment(Qt::AlignCenter);
        label_44->setMargin(-1);

        horizontalLayout_23->addWidget(label_44);

        label_45 = new QLabel(frame_23);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setFont(font2);
        label_45->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        label_45->setAlignment(Qt::AlignCenter);

        horizontalLayout_23->addWidget(label_45);


        verticalLayout_11->addWidget(frame_23);

        frame_24 = new QFrame(widget);
        frame_24->setObjectName(QStringLiteral("frame_24"));
        frame_24->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        frame_24->setFrameShape(QFrame::StyledPanel);
        frame_24->setFrameShadow(QFrame::Raised);
        horizontalLayout_24 = new QHBoxLayout(frame_24);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(6, 6, 6, 6);
        label_47 = new QLabel(frame_24);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setMaximumSize(QSize(66, 16777215));
        label_47->setFont(font1);
        label_47->setStyleSheet(QLatin1String("background: rgba(212,215,217,36);\n"
"color: rgba(141,158,198,180)"));
        label_47->setAlignment(Qt::AlignCenter);
        label_47->setMargin(-1);

        horizontalLayout_24->addWidget(label_47);

        label_48 = new QLabel(frame_24);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setFont(font2);
        label_48->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        label_48->setAlignment(Qt::AlignCenter);

        horizontalLayout_24->addWidget(label_48);


        verticalLayout_11->addWidget(frame_24);

        frame_25 = new QFrame(widget);
        frame_25->setObjectName(QStringLiteral("frame_25"));
        frame_25->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        frame_25->setFrameShape(QFrame::StyledPanel);
        frame_25->setFrameShadow(QFrame::Raised);
        horizontalLayout_25 = new QHBoxLayout(frame_25);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(6, 6, 6, 6);
        label_50 = new QLabel(frame_25);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setMaximumSize(QSize(66, 16777215));
        label_50->setFont(font1);
        label_50->setStyleSheet(QLatin1String("background: rgba(212,215,217,36);\n"
"color: rgba(141,158,198,180)"));
        label_50->setAlignment(Qt::AlignCenter);
        label_50->setMargin(-1);

        horizontalLayout_25->addWidget(label_50);

        label_51 = new QLabel(frame_25);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setFont(font2);
        label_51->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        label_51->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(label_51);


        verticalLayout_11->addWidget(frame_25);

        frame_26 = new QFrame(widget);
        frame_26->setObjectName(QStringLiteral("frame_26"));
        frame_26->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        frame_26->setFrameShape(QFrame::StyledPanel);
        frame_26->setFrameShadow(QFrame::Raised);
        horizontalLayout_26 = new QHBoxLayout(frame_26);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(6, 6, 6, 6);
        label_53 = new QLabel(frame_26);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setMinimumSize(QSize(68, 0));
        label_53->setMaximumSize(QSize(66, 16777215));
        label_53->setFont(font1);
        label_53->setStyleSheet(QLatin1String("background: rgba(212,215,217,36);\n"
"color: rgba(141,158,198,180)"));
        label_53->setAlignment(Qt::AlignCenter);
        label_53->setMargin(-1);

        horizontalLayout_26->addWidget(label_53);

        label_54 = new QLabel(frame_26);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setFont(font2);
        label_54->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        label_54->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(label_54);


        verticalLayout_11->addWidget(frame_26);

        stackedWidget->addWidget(dashboardPage);
        splitter->addWidget(stackedWidget);

        verticalLayout_4->addWidget(splitter);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
#ifndef QT_NO_TOOLTIP
        settings_button_resetToDefault->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        settings_button_resetToDefault->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        settings_button_resetToDefault->setText(QApplication::translate("Widget", " Reset", nullptr));
        settings_button_openFile->setText(QApplication::translate("Widget", " Import Configuration", nullptr));
        settings_buttons_saveFile->setText(QApplication::translate("Widget", " Export Configuration", nullptr));
        settings_button_apply->setText(QApplication::translate("Widget", " Apply", nullptr));
        settings_button_refreshPorts->setText(QApplication::translate("Widget", "Rescan Ports", nullptr));
        settings_button_openFile_2->setText(QApplication::translate("Widget", "Open G-Code File", nullptr));
        radioButton_2->setText(QApplication::translate("Widget", "Display Command Strings", nullptr));
        radioButton->setText(QApplication::translate("Widget", "Display Comments", nullptr));
        radioButton_3->setText(QApplication::translate("Widget", "Ignore Errors", nullptr));
        settings_button_apply_2->setText(QApplication::translate("Widget", "Clear Part", nullptr));
        label->setText(QApplication::translate("Widget", "Process Output", nullptr));
        settings_buttons_saveFile_2->setText(QApplication::translate("Widget", "Add Part To Job List", nullptr));
        label_41->setText(QApplication::translate("Widget", "X", nullptr));
        label_42->setText(QApplication::translate("Widget", "420.690", nullptr));
        label_44->setText(QApplication::translate("Widget", "Y", nullptr));
        label_45->setText(QApplication::translate("Widget", "420.690", nullptr));
        label_47->setText(QApplication::translate("Widget", "Z", nullptr));
        label_48->setText(QApplication::translate("Widget", "420.690", nullptr));
        label_50->setText(QApplication::translate("Widget", "H", nullptr));
        label_51->setText(QApplication::translate("Widget", "420.690", nullptr));
        label_53->setText(QApplication::translate("Widget", "S", nullptr));
        label_54->setText(QApplication::translate("Widget", "420.690", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
