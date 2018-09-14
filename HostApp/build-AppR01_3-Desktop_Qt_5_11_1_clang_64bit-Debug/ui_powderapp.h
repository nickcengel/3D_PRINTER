/********************************************************************************
** Form generated from reading UI file 'powderapp.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWDERAPP_H
#define UI_POWDERAPP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowderApp
{
public:
    QHBoxLayout *horizontalLayout_14;
    QSplitter *Menu_Page_Splitter;
    QFrame *MenuFrame;
    QVBoxLayout *verticalLayout;
    QTreeView *MenuTree;
    QFrame *PortManagerDisplay_frame;
    QVBoxLayout *verticalLayout_12;
    QFrame *PortManagerTitle_frame;
    QVBoxLayout *verticalLayout_15;
    QLabel *PortManagerDisplay_title;
    QComboBox *PortManager_options_box;
    QFrame *LaserGalvoPort_frame;
    QVBoxLayout *verticalLayout_23;
    QLabel *LaserGalvoPort_title;
    QHBoxLayout *LaserGalvoPort_layout;
    QPushButton *LaserGalvoPortStatus_indicator;
    QLabel *LaserGalvoPortStatus_field;
    QFrame *MaterialDeliveryPort_frame;
    QVBoxLayout *verticalLayout_24;
    QLabel *MaterialDeliveryPort_title;
    QHBoxLayout *MaterialDeliveryPort_layout;
    QPushButton *MaterialDeliveryPortStatus_indicator;
    QLabel *MaterialDeliveryPortStatus_field;
    QFrame *EnvironmentPort_frame;
    QVBoxLayout *verticalLayout_28;
    QLabel *EnvironmentPortStatus_title;
    QHBoxLayout *EnvironmentPort_layout;
    QPushButton *EnvironmentPortStatus_indicator;
    QLabel *EnvironmentPortStatus_field;
    QTextBrowser *PortManagerInfo_browser;
    QStackedWidget *AppPages;
    QWidget *HomePage;
    QHBoxLayout *horizontalLayout_49;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *HomeLayout;
    QSpacerItem *verticalSpacer_6;
    QFrame *HomeFrame;
    QVBoxLayout *verticalLayout_41;
    QPushButton *Main_Button_Home;
    QFrame *MainPortFrame;
    QVBoxLayout *verticalLayout_36;
    QPushButton *Main_Button_PortPage;
    QFrame *MainConfigureFrame;
    QVBoxLayout *verticalLayout_37;
    QPushButton *Main_Button_ConfigurationPage;
    QFrame *MainGcodeFrame;
    QVBoxLayout *verticalLayout_38;
    QPushButton *Main_Button_GCodePage;
    QFrame *MainControllerFrame;
    QVBoxLayout *verticalLayout_39;
    QPushButton *Main_Button_ControllerPage;
    QFrame *MainHelpFrame;
    QVBoxLayout *verticalLayout_40;
    QPushButton *Main_Button_HelpPage;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_14;
    QWidget *settingsPage;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *settings_page_layout;
    QSpacerItem *verticalSpacer_2;
    QFrame *settings_page_button_frame;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *settings_button_resetToDefault;
    QPushButton *settings_button_openFile;
    QPushButton *settings_buttons_saveFile;
    QPushButton *settings_button_apply;
    QFrame *settings_page_view_frame;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *settings_view_layout;
    QSpacerItem *horizontalSpacer_7;
    QTreeView *settings_view;
    QSpacerItem *horizontalSpacer_8;
    QWidget *portPage;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *portPage_layout;
    QSpacerItem *verticalSpacer_3;
    QFrame *portPage_button_frame;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *settings_button_refreshPorts;
    QSpacerItem *horizontalSpacer_4;
    QTreeView *port_view;
    QWidget *printToolsPage;
    QVBoxLayout *verticalLayout_5;
    QFrame *printToolsPage_Frame;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *printToolsPage_upper_layout;
    QFrame *printTools_button_frame;
    QVBoxLayout *verticalLayout_7;
    QPushButton *gcode_tool_button_openFile;
    QHBoxLayout *printTools_radio_button_frame;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *printTools_button_frame_layout;
    QRadioButton *printTools_display_commands_button;
    QRadioButton *printTools_displayComments_button;
    QRadioButton *printTools_ignoreErrors_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *gcode_tool_button_clearPart;
    QFrame *partInfoView_frame;
    QHBoxLayout *horizontalLayout;
    QTableView *PartInfoView;
    QTableView *PartInfoViewData;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *printTools_outputBrowser_title;
    QTextBrowser *printTools_gCodeBrowser;
    QVBoxLayout *verticalLayout_3;
    QLabel *printTools_outputBrowser_title_2;
    QTextBrowser *printTools_outputBrowser;
    QVBoxLayout *verticalLayout_6;
    QLabel *printTools_outputBrowser_title_3;
    QTextBrowser *printTools_errorBrowser;
    QHBoxLayout *printTools_page_acceptPart_button_layou;
    QSpacerItem *horizontalSpacer_5;
    QFrame *printTools_page_acceptPart_button_frame;
    QVBoxLayout *verticalLayout_8;
    QPushButton *printTools_page_acceptPart_button;
    QSpacerItem *horizontalSpacer_6;
    QWidget *dashboardPage;
    QHBoxLayout *horizontalLayout_7;
    QSplitter *PrintControl_splitter;
    QFrame *printManager_frame;
    QVBoxLayout *verticalLayout_14;
    QFrame *PrintManagerTitle_frame;
    QHBoxLayout *horizontalLayout_35;
    QPushButton *PrintManagerEnable_button;
    QLabel *label_47;
    QFrame *printManagerInfo_frame;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *printManagerStatus_layout;
    QPushButton *printManagerStatus_indicator;
    QLabel *printManagerStatus_title;
    QLabel *printManager_status_field;
    QHBoxLayout *printManagerFile_layout;
    QLabel *activeFile_titleLabel;
    QLabel *printManager_file_field;
    QComboBox *printManager_options_box;
    QFrame *printManagerControls_frame;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *printManager_stop_button;
    QPushButton *printManager_pause_button;
    QPushButton *printManager_stepThrough_button;
    QPushButton *printManager_start_button;
    QTextBrowser *printManager_textBrowser;
    QFrame *blockProgress_frame;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *blockProgress_layout;
    QSpacerItem *horizontalSpacer_11;
    QLabel *blockTitle_label;
    QLabel *currentBlock_field;
    QLabel *blockOf_label;
    QLabel *totalBlocks_field;
    QSpacerItem *horizontalSpacer_10;
    QProgressBar *printManager_block_bar;
    QFrame *layerProgress_frame;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *LayerProgress_layout;
    QSpacerItem *horizontalSpacer_12;
    QLabel *layerTitle_label;
    QLabel *currentLayer_field;
    QLabel *layerOf_label;
    QLabel *totalLayers_field;
    QSpacerItem *horizontalSpacer_13;
    QProgressBar *printManager_layer_bar;
    QFrame *ManualControl_Frame;
    QVBoxLayout *verticalLayout_34;
    QFrame *ManualControlTitle_frame;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *ManualControlEnable_button;
    QLabel *label_46;
    QFrame *ManualControlHome_frame;
    QHBoxLayout *horizontalLayout_42;
    QPushButton *ManualControlHome_button;
    QComboBox *ManualControlHome_options_box;
    QFrame *ManualControlTop_frame;
    QHBoxLayout *horizontalLayout_44;
    QFrame *JogDistanceFrame;
    QVBoxLayout *verticalLayout_35;
    QLabel *jogDistance_title;
    QFrame *jogDistanceSubFrame;
    QHBoxLayout *horizontalLayout_45;
    QDoubleSpinBox *printManager_JogDistance_Input;
    QLabel *jog_units_label;
    QFrame *GalvoJog_frame;
    QVBoxLayout *verticalLayout_26;
    QLabel *galvo_jog_control_title;
    QHBoxLayout *GalvoJog_layout;
    QPushButton *jogXminus_button;
    QVBoxLayout *yJogLayout;
    QPushButton *jogYplus_button;
    QPushButton *jogYminus_button;
    QPushButton *jogXplus_button;
    QFrame *materialDeliveryControl_frame;
    QVBoxLayout *verticalLayout_31;
    QHBoxLayout *jogControl_titleLayout;
    QLabel *build_jog_control_title;
    QLabel *hopper_jog_control_title;
    QLabel *spreader_jog_control_title;
    QHBoxLayout *materialDeliveryJog_layout;
    QVBoxLayout *zJog_layout;
    QPushButton *jogZplus_button;
    QPushButton *jogZminus_button;
    QVBoxLayout *hJog_layout;
    QPushButton *jogHplus_button;
    QPushButton *jogHminus_button;
    QHBoxLayout *sJog_layout;
    QPushButton *jogSminus_button;
    QPushButton *jogSplus_button;
    QVBoxLayout *DeviceDisplay_Layout;
    QFrame *laserDisplay_frame;
    QHBoxLayout *horizontalLayout_24;
    QFrame *LaserDisplayInfo_frame;
    QVBoxLayout *verticalLayout_4;
    QFrame *laserDisplaTitle_frame;
    QHBoxLayout *horizontalLayout_37;
    QPushButton *laserDisplayEnable_button;
    QLabel *laserDispla_title;
    QHBoxLayout *LaserDisplayStatus_layout;
    QPushButton *LaserDisplayStatus_indicator;
    QLabel *LaserDisplayStatus_title;
    QLabel *LaserDisplayStatus_field;
    QHBoxLayout *LaserDisplayPower_layout;
    QLabel *LaserDisplayPower_title;
    QTextEdit *LaserDisplayPower_field;
    QLabel *LaserDisplayPower_units;
    QComboBox *Laser_options_box;
    QFrame *LaserDisplayField_frame;
    QVBoxLayout *verticalLayout_11;
    QLabel *laserDisplay_EnableState_field;
    QFrame *galvoDisplay_frame;
    QHBoxLayout *horizontalLayout_22;
    QFrame *galvoDisplayInfo_frame;
    QVBoxLayout *verticalLayout_29;
    QFrame *galvoDisplayTitle_frame;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *galvoDisplayEnable_button;
    QLabel *galvoDisplay_title;
    QHBoxLayout *galvoStatus_layout;
    QPushButton *galvoDisplayStatus_indicator;
    QLabel *galvoStatus_title;
    QLabel *galvoStatus_field;
    QHBoxLayout *galvoSpeed_layout;
    QLabel *galvoSpeed_title;
    QTextEdit *galvoSpeed_field;
    QLabel *galvoSpeed_units;
    QComboBox *galvoOptions_box;
    QVBoxLayout *GalvoDisplayField_vertLayout;
    QFrame *xDisplayField_frame;
    QHBoxLayout *horizontalLayout_29;
    QLabel *xPosition_title;
    QLabel *xPositionDisplay_field;
    QFrame *yDisplayField_frame;
    QHBoxLayout *horizontalLayout_30;
    QLabel *yPosition_title;
    QLabel *yPositionDisplay_field;
    QFrame *buildPlateDisplay_frame;
    QHBoxLayout *horizontalLayout_20;
    QFrame *buildPlateDisplayInfo_Frame;
    QVBoxLayout *verticalLayout_25;
    QFrame *buildPlateTitle_frame;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *buildPlateEnable_button;
    QLabel *buildPlate_title;
    QHBoxLayout *buildPlateDisplayStatus_layout;
    QPushButton *buildPlateDisplayStatus_indicator;
    QLabel *buildPlateDisplayStatus_title;
    QLabel *buildPlateDisplayStatus_field;
    QComboBox *buildPlate_options_box;
    QFrame *BuildPlateDisplayField_frame;
    QHBoxLayout *horizontalLayout_27;
    QLabel *buildPlateDisplayField_title;
    QLabel *zPositionDisplay_field;
    QFrame *materialDeliveryDisplay_frame;
    QHBoxLayout *horizontalLayout_19;
    QFrame *materialDeliveryDisplayInfo_frame;
    QVBoxLayout *verticalLayout_27;
    QFrame *materialDeliveryDisplayTitle_frame;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *materialDeliveryDisplayEnable_button;
    QLabel *materialDeliveryDisplay_title;
    QHBoxLayout *materialDeliveryDisplayStatus_layout;
    QPushButton *materialDeliveryDisplayStatus_indicator;
    QLabel *materialDeliveryDisplayStatus_title;
    QLabel *materialDeliveryDisplayStatus_field;
    QSpacerItem *verticalSpacer_4;
    QComboBox *materialDelivery_options_box;
    QVBoxLayout *materialDeliveryDisplayField_frame;
    QFrame *HdisplayField_frame;
    QHBoxLayout *horizontalLayout_25;
    QLabel *hPositionDisplay_title;
    QLabel *hPositionDisplay_field;
    QFrame *SdisplayField_frame;
    QHBoxLayout *horizontalLayout_26;
    QLabel *sPositionDisplay_title;
    QLabel *sPositionDisplay_field;
    QFrame *enviroDisplay_frame;
    QHBoxLayout *horizontalLayout_33;
    QFrame *enviroDisplayInfo_frame;
    QVBoxLayout *verticalLayout_19;
    QFrame *enviroDisplayTitleFrame;
    QHBoxLayout *horizontalLayout_34;
    QPushButton *enviroDisplayEnable_button;
    QLabel *enviroDisplay_title;
    QVBoxLayout *enviroDisplayInfo_layout;
    QHBoxLayout *enviroDisplayStatus_layout;
    QPushButton *enviroDisplayStatus_indicator;
    QLabel *enviroDisplayStatus_title;
    QLabel *enviroDisplayStatus_field;
    QPushButton *enviroDisplayDoorState_icon;
    QLabel *enviroDisplayDoorState_field;
    QComboBox *enviro_options_box;
    QFrame *enviroDisplayData_frame;
    QGridLayout *gridLayout_2;
    QFrame *enviroDisplayPressure_frame;
    QVBoxLayout *verticalLayout_22;
    QLabel *enviroDisplayPressure_title;
    QLabel *enviroDisplayPressure_field;
    QFrame *enviroDisplayBuildTemperature_frame;
    QVBoxLayout *verticalLayout_17;
    QLabel *enviroDisplayBuildTemperature_title;
    QLabel *enviroDisplayBuildTemperature_field;
    QFrame *enviroDisplayOxygen_frame;
    QVBoxLayout *verticalLayout_21;
    QLabel *enviroDisplayOxygen_title;
    QLabel *enviroDisplayOxygen_field;
    QFrame *enviroDisplayTemperature_frame;
    QVBoxLayout *verticalLayout_18;
    QLabel *enviroDisplayTemperature_title;
    QLabel *enviroDisplayTemperature_field;
    QWidget *HelpPage;

    void setupUi(QWidget *PowderApp)
    {
        if (PowderApp->objectName().isEmpty())
            PowderApp->setObjectName(QStringLiteral("PowderApp"));
        PowderApp->resize(1037, 750);
        PowderApp->setMinimumSize(QSize(325, 700));
        PowderApp->setAutoFillBackground(false);
        PowderApp->setStyleSheet(QLatin1String("background:rgb(22, 22, 22);\n"
""));
        horizontalLayout_14 = new QHBoxLayout(PowderApp);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        Menu_Page_Splitter = new QSplitter(PowderApp);
        Menu_Page_Splitter->setObjectName(QStringLiteral("Menu_Page_Splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu_Page_Splitter->sizePolicy().hasHeightForWidth());
        Menu_Page_Splitter->setSizePolicy(sizePolicy);
        Menu_Page_Splitter->setStyleSheet(QStringLiteral(""));
        Menu_Page_Splitter->setOrientation(Qt::Horizontal);
        Menu_Page_Splitter->setHandleWidth(8);
        MenuFrame = new QFrame(Menu_Page_Splitter);
        MenuFrame->setObjectName(QStringLiteral("MenuFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MenuFrame->sizePolicy().hasHeightForWidth());
        MenuFrame->setSizePolicy(sizePolicy1);
        MenuFrame->setMinimumSize(QSize(0, 0));
        MenuFrame->setMaximumSize(QSize(210, 16777215));
        MenuFrame->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 45), stop:1 rgba(212, 215, 217, 65));\n"
"\n"
"\n"
"border-radius: 8;"));
        MenuFrame->setFrameShape(QFrame::StyledPanel);
        MenuFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(MenuFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        MenuTree = new QTreeView(MenuFrame);
        MenuTree->setObjectName(QStringLiteral("MenuTree"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MenuTree->sizePolicy().hasHeightForWidth());
        MenuTree->setSizePolicy(sizePolicy2);
        MenuTree->setMinimumSize(QSize(150, 350));
        MenuTree->setMaximumSize(QSize(300, 450));
        MenuTree->setStyleSheet(QLatin1String("background:rgba(0,0,0,0);\n"
"color:white;\n"
""));
        MenuTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        MenuTree->setProperty("showDropIndicator", QVariant(false));
        MenuTree->setAnimated(true);
        MenuTree->setHeaderHidden(true);
        MenuTree->header()->setDefaultSectionSize(150);
        MenuTree->header()->setMinimumSectionSize(150);

        verticalLayout->addWidget(MenuTree, 0, Qt::AlignTop);

        PortManagerDisplay_frame = new QFrame(MenuFrame);
        PortManagerDisplay_frame->setObjectName(QStringLiteral("PortManagerDisplay_frame"));
        PortManagerDisplay_frame->setMinimumSize(QSize(175, 0));
        PortManagerDisplay_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,16)"));
        PortManagerDisplay_frame->setFrameShape(QFrame::StyledPanel);
        PortManagerDisplay_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(PortManagerDisplay_frame);
        verticalLayout_12->setSpacing(4);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(4, 4, 4, 4);
        PortManagerTitle_frame = new QFrame(PortManagerDisplay_frame);
        PortManagerTitle_frame->setObjectName(QStringLiteral("PortManagerTitle_frame"));
        PortManagerTitle_frame->setMinimumSize(QSize(0, 70));
        PortManagerTitle_frame->setMaximumSize(QSize(16777215, 80));
        PortManagerTitle_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,16)"));
        PortManagerTitle_frame->setFrameShape(QFrame::StyledPanel);
        PortManagerTitle_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(PortManagerTitle_frame);
        verticalLayout_15->setSpacing(4);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(4, 4, 4, 4);
        PortManagerDisplay_title = new QLabel(PortManagerTitle_frame);
        PortManagerDisplay_title->setObjectName(QStringLiteral("PortManagerDisplay_title"));
        PortManagerDisplay_title->setMinimumSize(QSize(0, 24));
        PortManagerDisplay_title->setMaximumSize(QSize(1000, 16777215));
        PortManagerDisplay_title->setBaseSize(QSize(0, 24));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        PortManagerDisplay_title->setFont(font);
        PortManagerDisplay_title->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        PortManagerDisplay_title->setInputMethodHints(Qt::ImhNoEditMenu);
        PortManagerDisplay_title->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(PortManagerDisplay_title);

        PortManager_options_box = new QComboBox(PortManagerTitle_frame);
        PortManager_options_box->addItem(QString());
        PortManager_options_box->addItem(QString());
        PortManager_options_box->addItem(QString());
        PortManager_options_box->setObjectName(QStringLiteral("PortManager_options_box"));
        PortManager_options_box->setMinimumSize(QSize(170, 24));
        PortManager_options_box->setStyleSheet(QLatin1String("background:rgb(55, 55, 58);\n"
"color:rgba(212,215,217,200)"));

        verticalLayout_15->addWidget(PortManager_options_box, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_12->addWidget(PortManagerTitle_frame);

        LaserGalvoPort_frame = new QFrame(PortManagerDisplay_frame);
        LaserGalvoPort_frame->setObjectName(QStringLiteral("LaserGalvoPort_frame"));
        LaserGalvoPort_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,12)"));
        LaserGalvoPort_frame->setFrameShape(QFrame::StyledPanel);
        LaserGalvoPort_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_23 = new QVBoxLayout(LaserGalvoPort_frame);
        verticalLayout_23->setSpacing(4);
        verticalLayout_23->setContentsMargins(11, 11, 11, 11);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        verticalLayout_23->setContentsMargins(4, 4, 4, 4);
        LaserGalvoPort_title = new QLabel(LaserGalvoPort_frame);
        LaserGalvoPort_title->setObjectName(QStringLiteral("LaserGalvoPort_title"));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        LaserGalvoPort_title->setFont(font1);
        LaserGalvoPort_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        LaserGalvoPort_title->setAlignment(Qt::AlignCenter);

        verticalLayout_23->addWidget(LaserGalvoPort_title);

        LaserGalvoPort_layout = new QHBoxLayout();
        LaserGalvoPort_layout->setSpacing(6);
        LaserGalvoPort_layout->setObjectName(QStringLiteral("LaserGalvoPort_layout"));
        LaserGalvoPortStatus_indicator = new QPushButton(LaserGalvoPort_frame);
        LaserGalvoPortStatus_indicator->setObjectName(QStringLiteral("LaserGalvoPortStatus_indicator"));
        LaserGalvoPortStatus_indicator->setMaximumSize(QSize(20, 16777215));
        LaserGalvoPortStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/redbutton.png"), QSize(), QIcon::Normal, QIcon::Off);
        LaserGalvoPortStatus_indicator->setIcon(icon);
        LaserGalvoPortStatus_indicator->setFlat(true);

        LaserGalvoPort_layout->addWidget(LaserGalvoPortStatus_indicator);

        LaserGalvoPortStatus_field = new QLabel(LaserGalvoPort_frame);
        LaserGalvoPortStatus_field->setObjectName(QStringLiteral("LaserGalvoPortStatus_field"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        LaserGalvoPortStatus_field->setFont(font2);
        LaserGalvoPortStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LaserGalvoPort_layout->addWidget(LaserGalvoPortStatus_field);


        verticalLayout_23->addLayout(LaserGalvoPort_layout);


        verticalLayout_12->addWidget(LaserGalvoPort_frame);

        MaterialDeliveryPort_frame = new QFrame(PortManagerDisplay_frame);
        MaterialDeliveryPort_frame->setObjectName(QStringLiteral("MaterialDeliveryPort_frame"));
        MaterialDeliveryPort_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,12)"));
        MaterialDeliveryPort_frame->setFrameShape(QFrame::StyledPanel);
        MaterialDeliveryPort_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_24 = new QVBoxLayout(MaterialDeliveryPort_frame);
        verticalLayout_24->setSpacing(4);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(4, 4, 4, 4);
        MaterialDeliveryPort_title = new QLabel(MaterialDeliveryPort_frame);
        MaterialDeliveryPort_title->setObjectName(QStringLiteral("MaterialDeliveryPort_title"));
        MaterialDeliveryPort_title->setFont(font1);
        MaterialDeliveryPort_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        MaterialDeliveryPort_title->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(MaterialDeliveryPort_title);

        MaterialDeliveryPort_layout = new QHBoxLayout();
        MaterialDeliveryPort_layout->setSpacing(6);
        MaterialDeliveryPort_layout->setObjectName(QStringLiteral("MaterialDeliveryPort_layout"));
        MaterialDeliveryPortStatus_indicator = new QPushButton(MaterialDeliveryPort_frame);
        MaterialDeliveryPortStatus_indicator->setObjectName(QStringLiteral("MaterialDeliveryPortStatus_indicator"));
        MaterialDeliveryPortStatus_indicator->setMaximumSize(QSize(20, 16777215));
        MaterialDeliveryPortStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        MaterialDeliveryPortStatus_indicator->setIcon(icon);
        MaterialDeliveryPortStatus_indicator->setFlat(true);

        MaterialDeliveryPort_layout->addWidget(MaterialDeliveryPortStatus_indicator);

        MaterialDeliveryPortStatus_field = new QLabel(MaterialDeliveryPort_frame);
        MaterialDeliveryPortStatus_field->setObjectName(QStringLiteral("MaterialDeliveryPortStatus_field"));
        MaterialDeliveryPortStatus_field->setFont(font2);
        MaterialDeliveryPortStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        MaterialDeliveryPort_layout->addWidget(MaterialDeliveryPortStatus_field);


        verticalLayout_24->addLayout(MaterialDeliveryPort_layout);


        verticalLayout_12->addWidget(MaterialDeliveryPort_frame);

        EnvironmentPort_frame = new QFrame(PortManagerDisplay_frame);
        EnvironmentPort_frame->setObjectName(QStringLiteral("EnvironmentPort_frame"));
        EnvironmentPort_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,12)"));
        EnvironmentPort_frame->setFrameShape(QFrame::StyledPanel);
        EnvironmentPort_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_28 = new QVBoxLayout(EnvironmentPort_frame);
        verticalLayout_28->setSpacing(4);
        verticalLayout_28->setContentsMargins(11, 11, 11, 11);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        verticalLayout_28->setContentsMargins(4, 4, 4, 4);
        EnvironmentPortStatus_title = new QLabel(EnvironmentPort_frame);
        EnvironmentPortStatus_title->setObjectName(QStringLiteral("EnvironmentPortStatus_title"));
        EnvironmentPortStatus_title->setFont(font1);
        EnvironmentPortStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        EnvironmentPortStatus_title->setAlignment(Qt::AlignCenter);

        verticalLayout_28->addWidget(EnvironmentPortStatus_title);

        EnvironmentPort_layout = new QHBoxLayout();
        EnvironmentPort_layout->setSpacing(6);
        EnvironmentPort_layout->setObjectName(QStringLiteral("EnvironmentPort_layout"));
        EnvironmentPortStatus_indicator = new QPushButton(EnvironmentPort_frame);
        EnvironmentPortStatus_indicator->setObjectName(QStringLiteral("EnvironmentPortStatus_indicator"));
        EnvironmentPortStatus_indicator->setMaximumSize(QSize(20, 16777215));
        EnvironmentPortStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        EnvironmentPortStatus_indicator->setIcon(icon);
        EnvironmentPortStatus_indicator->setFlat(true);

        EnvironmentPort_layout->addWidget(EnvironmentPortStatus_indicator);

        EnvironmentPortStatus_field = new QLabel(EnvironmentPort_frame);
        EnvironmentPortStatus_field->setObjectName(QStringLiteral("EnvironmentPortStatus_field"));
        EnvironmentPortStatus_field->setFont(font2);
        EnvironmentPortStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        EnvironmentPort_layout->addWidget(EnvironmentPortStatus_field);


        verticalLayout_28->addLayout(EnvironmentPort_layout);


        verticalLayout_12->addWidget(EnvironmentPort_frame);

        PortManagerInfo_browser = new QTextBrowser(PortManagerDisplay_frame);
        PortManagerInfo_browser->setObjectName(QStringLiteral("PortManagerInfo_browser"));
        PortManagerInfo_browser->setMaximumSize(QSize(16777215, 100));

        verticalLayout_12->addWidget(PortManagerInfo_browser);


        verticalLayout->addWidget(PortManagerDisplay_frame);

        Menu_Page_Splitter->addWidget(MenuFrame);
        AppPages = new QStackedWidget(Menu_Page_Splitter);
        AppPages->setObjectName(QStringLiteral("AppPages"));
        sizePolicy.setHeightForWidth(AppPages->sizePolicy().hasHeightForWidth());
        AppPages->setSizePolicy(sizePolicy);
        AppPages->setMinimumSize(QSize(0, 0));
        AppPages->setFont(font2);
        AppPages->setStyleSheet(QLatin1String("border-radius: 5;\n"
""));
        AppPages->setFrameShape(QFrame::Box);
        HomePage = new QWidget();
        HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->setStyleSheet(QStringLiteral(""));
        horizontalLayout_49 = new QHBoxLayout(HomePage);
        horizontalLayout_49->setSpacing(6);
        horizontalLayout_49->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_49->setObjectName(QStringLiteral("horizontalLayout_49"));
        horizontalSpacer_9 = new QSpacerItem(258, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_49->addItem(horizontalSpacer_9);

        HomeLayout = new QVBoxLayout();
        HomeLayout->setSpacing(6);
        HomeLayout->setObjectName(QStringLiteral("HomeLayout"));
        verticalSpacer_6 = new QSpacerItem(183, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        HomeLayout->addItem(verticalSpacer_6);

        HomeFrame = new QFrame(HomePage);
        HomeFrame->setObjectName(QStringLiteral("HomeFrame"));
        HomeFrame->setMinimumSize(QSize(295, 660));
        HomeFrame->setStyleSheet(QLatin1String("background: rgba(212,215,217,15);\n"
"border-radius:12"));
        HomeFrame->setFrameShape(QFrame::StyledPanel);
        HomeFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_41 = new QVBoxLayout(HomeFrame);
        verticalLayout_41->setSpacing(6);
        verticalLayout_41->setContentsMargins(11, 11, 11, 11);
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        Main_Button_Home = new QPushButton(HomeFrame);
        Main_Button_Home->setObjectName(QStringLiteral("Main_Button_Home"));
        Main_Button_Home->setMinimumSize(QSize(180, 180));
        Main_Button_Home->setMaximumSize(QSize(16777215, 180));
        Main_Button_Home->setBaseSize(QSize(180, 180));
        Main_Button_Home->setStyleSheet(QStringLiteral("background:none"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/cube.png"), QSize(), QIcon::Normal, QIcon::On);
        Main_Button_Home->setIcon(icon1);
        Main_Button_Home->setIconSize(QSize(180, 180));

        verticalLayout_41->addWidget(Main_Button_Home);

        MainPortFrame = new QFrame(HomeFrame);
        MainPortFrame->setObjectName(QStringLiteral("MainPortFrame"));
        MainPortFrame->setMinimumSize(QSize(271, 80));
        MainPortFrame->setMaximumSize(QSize(500, 80));
        MainPortFrame->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 20), stop:1 rgba(212, 215, 217, 35));\n"
"\n"
""));
        MainPortFrame->setFrameShape(QFrame::StyledPanel);
        MainPortFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_36 = new QVBoxLayout(MainPortFrame);
        verticalLayout_36->setSpacing(6);
        verticalLayout_36->setContentsMargins(11, 11, 11, 11);
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        Main_Button_PortPage = new QPushButton(MainPortFrame);
        Main_Button_PortPage->setObjectName(QStringLiteral("Main_Button_PortPage"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Main_Button_PortPage->sizePolicy().hasHeightForWidth());
        Main_Button_PortPage->setSizePolicy(sizePolicy3);
        Main_Button_PortPage->setMinimumSize(QSize(32, 32));
        Main_Button_PortPage->setBaseSize(QSize(270, 484));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        Main_Button_PortPage->setFont(font3);
        Main_Button_PortPage->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/Icon-eto-flow-cascade.png"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Button_PortPage->setIcon(icon2);
        Main_Button_PortPage->setIconSize(QSize(33, 52));
        Main_Button_PortPage->setFlat(true);

        verticalLayout_36->addWidget(Main_Button_PortPage, 0, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout_41->addWidget(MainPortFrame);

        MainConfigureFrame = new QFrame(HomeFrame);
        MainConfigureFrame->setObjectName(QStringLiteral("MainConfigureFrame"));
        MainConfigureFrame->setMinimumSize(QSize(271, 80));
        MainConfigureFrame->setMaximumSize(QSize(500, 80));
        MainConfigureFrame->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 20), stop:1 rgba(212, 215, 217, 35));\n"
"\n"
""));
        MainConfigureFrame->setFrameShape(QFrame::StyledPanel);
        MainConfigureFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_37 = new QVBoxLayout(MainConfigureFrame);
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setContentsMargins(11, 11, 11, 11);
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        Main_Button_ConfigurationPage = new QPushButton(MainConfigureFrame);
        Main_Button_ConfigurationPage->setObjectName(QStringLiteral("Main_Button_ConfigurationPage"));
        sizePolicy3.setHeightForWidth(Main_Button_ConfigurationPage->sizePolicy().hasHeightForWidth());
        Main_Button_ConfigurationPage->setSizePolicy(sizePolicy3);
        Main_Button_ConfigurationPage->setMinimumSize(QSize(32, 32));
        Main_Button_ConfigurationPage->setBaseSize(QSize(270, 484));
        Main_Button_ConfigurationPage->setFont(font3);
        Main_Button_ConfigurationPage->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/iosSettingsStrong.png"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Button_ConfigurationPage->setIcon(icon3);
        Main_Button_ConfigurationPage->setIconSize(QSize(44, 50));
        Main_Button_ConfigurationPage->setFlat(true);

        verticalLayout_37->addWidget(Main_Button_ConfigurationPage, 0, Qt::AlignLeft);


        verticalLayout_41->addWidget(MainConfigureFrame);

        MainGcodeFrame = new QFrame(HomeFrame);
        MainGcodeFrame->setObjectName(QStringLiteral("MainGcodeFrame"));
        MainGcodeFrame->setMinimumSize(QSize(271, 80));
        MainGcodeFrame->setMaximumSize(QSize(500, 80));
        MainGcodeFrame->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 20), stop:1 rgba(212, 215, 217, 35));\n"
"\n"
""));
        MainGcodeFrame->setFrameShape(QFrame::StyledPanel);
        MainGcodeFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_38 = new QVBoxLayout(MainGcodeFrame);
        verticalLayout_38->setSpacing(6);
        verticalLayout_38->setContentsMargins(11, 11, 11, 11);
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        Main_Button_GCodePage = new QPushButton(MainGcodeFrame);
        Main_Button_GCodePage->setObjectName(QStringLiteral("Main_Button_GCodePage"));
        sizePolicy3.setHeightForWidth(Main_Button_GCodePage->sizePolicy().hasHeightForWidth());
        Main_Button_GCodePage->setSizePolicy(sizePolicy3);
        Main_Button_GCodePage->setMinimumSize(QSize(32, 32));
        Main_Button_GCodePage->setBaseSize(QSize(270, 484));
        Main_Button_GCodePage->setFont(font3);
        Main_Button_GCodePage->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/angle-double-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Button_GCodePage->setIcon(icon4);
        Main_Button_GCodePage->setIconSize(QSize(29, 62));
        Main_Button_GCodePage->setFlat(true);

        verticalLayout_38->addWidget(Main_Button_GCodePage, 0, Qt::AlignLeft);


        verticalLayout_41->addWidget(MainGcodeFrame);

        MainControllerFrame = new QFrame(HomeFrame);
        MainControllerFrame->setObjectName(QStringLiteral("MainControllerFrame"));
        MainControllerFrame->setMinimumSize(QSize(271, 80));
        MainControllerFrame->setMaximumSize(QSize(500, 80));
        MainControllerFrame->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 20), stop:1 rgba(212, 215, 217, 35));\n"
"\n"
""));
        MainControllerFrame->setFrameShape(QFrame::StyledPanel);
        MainControllerFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_39 = new QVBoxLayout(MainControllerFrame);
        verticalLayout_39->setSpacing(6);
        verticalLayout_39->setContentsMargins(11, 11, 11, 11);
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        Main_Button_ControllerPage = new QPushButton(MainControllerFrame);
        Main_Button_ControllerPage->setObjectName(QStringLiteral("Main_Button_ControllerPage"));
        sizePolicy3.setHeightForWidth(Main_Button_ControllerPage->sizePolicy().hasHeightForWidth());
        Main_Button_ControllerPage->setSizePolicy(sizePolicy3);
        Main_Button_ControllerPage->setMinimumSize(QSize(32, 32));
        Main_Button_ControllerPage->setBaseSize(QSize(270, 484));
        Main_Button_ControllerPage->setFont(font3);
        Main_Button_ControllerPage->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/Icon-eto-tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Button_ControllerPage->setIcon(icon5);
        Main_Button_ControllerPage->setIconSize(QSize(48, 48));
        Main_Button_ControllerPage->setFlat(true);

        verticalLayout_39->addWidget(Main_Button_ControllerPage);


        verticalLayout_41->addWidget(MainControllerFrame);

        MainHelpFrame = new QFrame(HomeFrame);
        MainHelpFrame->setObjectName(QStringLiteral("MainHelpFrame"));
        MainHelpFrame->setMinimumSize(QSize(271, 80));
        MainHelpFrame->setMaximumSize(QSize(500, 80));
        MainHelpFrame->setStyleSheet(QLatin1String("background: qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 20), stop:1 rgba(212, 215, 217, 35));\n"
"\n"
""));
        MainHelpFrame->setFrameShape(QFrame::StyledPanel);
        MainHelpFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_40 = new QVBoxLayout(MainHelpFrame);
        verticalLayout_40->setSpacing(6);
        verticalLayout_40->setContentsMargins(11, 11, 11, 11);
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        Main_Button_HelpPage = new QPushButton(MainHelpFrame);
        Main_Button_HelpPage->setObjectName(QStringLiteral("Main_Button_HelpPage"));
        sizePolicy3.setHeightForWidth(Main_Button_HelpPage->sizePolicy().hasHeightForWidth());
        Main_Button_HelpPage->setSizePolicy(sizePolicy3);
        Main_Button_HelpPage->setMinimumSize(QSize(32, 32));
        Main_Button_HelpPage->setBaseSize(QSize(270, 484));
        Main_Button_HelpPage->setFont(font3);
        Main_Button_HelpPage->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/Icon-eto-help-circled.png"), QSize(), QIcon::Normal, QIcon::Off);
        Main_Button_HelpPage->setIcon(icon6);
        Main_Button_HelpPage->setIconSize(QSize(42, 47));
        Main_Button_HelpPage->setFlat(true);

        verticalLayout_40->addWidget(Main_Button_HelpPage);


        verticalLayout_41->addWidget(MainHelpFrame);


        HomeLayout->addWidget(HomeFrame);

        verticalSpacer_7 = new QSpacerItem(183, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        HomeLayout->addItem(verticalSpacer_7);


        horizontalLayout_49->addLayout(HomeLayout);

        horizontalSpacer_14 = new QSpacerItem(257, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_49->addItem(horizontalSpacer_14);

        AppPages->addWidget(HomePage);
        settingsPage = new QWidget();
        settingsPage->setObjectName(QStringLiteral("settingsPage"));
        settingsPage->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(settingsPage);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        settings_page_layout = new QVBoxLayout();
        settings_page_layout->setSpacing(2);
        settings_page_layout->setObjectName(QStringLiteral("settings_page_layout"));
        verticalSpacer_2 = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        settings_page_layout->addItem(verticalSpacer_2);

        settings_page_button_frame = new QFrame(settingsPage);
        settings_page_button_frame->setObjectName(QStringLiteral("settings_page_button_frame"));
        settings_page_button_frame->setMinimumSize(QSize(640, 56));
        settings_page_button_frame->setMaximumSize(QSize(16777215, 56));
        QFont font4;
        font4.setPointSize(14);
        settings_page_button_frame->setFont(font4);
        settings_page_button_frame->setStyleSheet(QLatin1String("background:\n"
"rgba(0,0,0,0);\n"
"\n"
"border-radius: 8;"));
        settings_page_button_frame->setFrameShape(QFrame::StyledPanel);
        settings_page_button_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(settings_page_button_frame);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        settings_button_resetToDefault = new QPushButton(settings_page_button_frame);
        settings_button_resetToDefault->setObjectName(QStringLiteral("settings_button_resetToDefault"));
        sizePolicy3.setHeightForWidth(settings_button_resetToDefault->sizePolicy().hasHeightForWidth());
        settings_button_resetToDefault->setSizePolicy(sizePolicy3);
        settings_button_resetToDefault->setMinimumSize(QSize(32, 32));
        settings_button_resetToDefault->setFont(font4);
        settings_button_resetToDefault->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/iosUndoOutline.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_resetToDefault->setIcon(icon7);
        settings_button_resetToDefault->setIconSize(QSize(30, 30));
        settings_button_resetToDefault->setFlat(true);

        horizontalLayout_4->addWidget(settings_button_resetToDefault);

        settings_button_openFile = new QPushButton(settings_page_button_frame);
        settings_button_openFile->setObjectName(QStringLiteral("settings_button_openFile"));
        sizePolicy3.setHeightForWidth(settings_button_openFile->sizePolicy().hasHeightForWidth());
        settings_button_openFile->setSizePolicy(sizePolicy3);
        settings_button_openFile->setMinimumSize(QSize(32, 32));
        settings_button_openFile->setBaseSize(QSize(270, 484));
        settings_button_openFile->setFont(font4);
        settings_button_openFile->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/iosDownload.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_openFile->setIcon(icon8);
        settings_button_openFile->setIconSize(QSize(30, 30));
        settings_button_openFile->setFlat(true);

        horizontalLayout_4->addWidget(settings_button_openFile);

        settings_buttons_saveFile = new QPushButton(settings_page_button_frame);
        settings_buttons_saveFile->setObjectName(QStringLiteral("settings_buttons_saveFile"));
        sizePolicy3.setHeightForWidth(settings_buttons_saveFile->sizePolicy().hasHeightForWidth());
        settings_buttons_saveFile->setSizePolicy(sizePolicy3);
        settings_buttons_saveFile->setMinimumSize(QSize(32, 32));
        settings_buttons_saveFile->setBaseSize(QSize(270, 484));
        settings_buttons_saveFile->setFont(font4);
        settings_buttons_saveFile->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/icons/iosUpload.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_buttons_saveFile->setIcon(icon9);
        settings_buttons_saveFile->setIconSize(QSize(30, 30));
        settings_buttons_saveFile->setFlat(true);

        horizontalLayout_4->addWidget(settings_buttons_saveFile);

        settings_button_apply = new QPushButton(settings_page_button_frame);
        settings_button_apply->setObjectName(QStringLiteral("settings_button_apply"));
        sizePolicy3.setHeightForWidth(settings_button_apply->sizePolicy().hasHeightForWidth());
        settings_button_apply->setSizePolicy(sizePolicy3);
        settings_button_apply->setMinimumSize(QSize(32, 32));
        settings_button_apply->setFont(font4);
        settings_button_apply->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/icons/iosRedo.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_apply->setIcon(icon10);
        settings_button_apply->setIconSize(QSize(30, 30));
        settings_button_apply->setFlat(true);

        horizontalLayout_4->addWidget(settings_button_apply);


        settings_page_layout->addWidget(settings_page_button_frame);

        settings_page_view_frame = new QFrame(settingsPage);
        settings_page_view_frame->setObjectName(QStringLiteral("settings_page_view_frame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(settings_page_view_frame->sizePolicy().hasHeightForWidth());
        settings_page_view_frame->setSizePolicy(sizePolicy4);
        settings_page_view_frame->setMinimumSize(QSize(512, 256));
        settings_page_view_frame->setMaximumSize(QSize(16777215, 16777215));
        settings_page_view_frame->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 12), stop:1 rgba(128, 128, 128, 35));\n"
"\n"
"\n"
"\n"
"border-radius: 8;\n"
"color: rgb(212,215,217);"));
        settings_page_view_frame->setFrameShape(QFrame::StyledPanel);
        settings_page_view_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(settings_page_view_frame);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalSpacer_5 = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_5);

        settings_view_layout = new QHBoxLayout();
        settings_view_layout->setSpacing(6);
        settings_view_layout->setObjectName(QStringLiteral("settings_view_layout"));
        horizontalSpacer_7 = new QSpacerItem(64, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        settings_view_layout->addItem(horizontalSpacer_7);

        settings_view = new QTreeView(settings_page_view_frame);
        settings_view->setObjectName(QStringLiteral("settings_view"));
        sizePolicy4.setHeightForWidth(settings_view->sizePolicy().hasHeightForWidth());
        settings_view->setSizePolicy(sizePolicy4);
        settings_view->setMinimumSize(QSize(512, 256));
        settings_view->setMaximumSize(QSize(512, 16777215));
        settings_view->setFont(font4);
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

        settings_view_layout->addWidget(settings_view);

        horizontalSpacer_8 = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        settings_view_layout->addItem(horizontalSpacer_8);


        verticalLayout_13->addLayout(settings_view_layout);


        settings_page_layout->addWidget(settings_page_view_frame);


        horizontalLayout_3->addLayout(settings_page_layout);

        AppPages->addWidget(settingsPage);
        portPage = new QWidget();
        portPage->setObjectName(QStringLiteral("portPage"));
        horizontalLayout_6 = new QHBoxLayout(portPage);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        portPage_layout = new QVBoxLayout();
        portPage_layout->setSpacing(6);
        portPage_layout->setObjectName(QStringLiteral("portPage_layout"));
        verticalSpacer_3 = new QSpacerItem(183, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        portPage_layout->addItem(verticalSpacer_3);

        portPage_button_frame = new QFrame(portPage);
        portPage_button_frame->setObjectName(QStringLiteral("portPage_button_frame"));
        portPage_button_frame->setFrameShape(QFrame::StyledPanel);
        portPage_button_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(portPage_button_frame);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        settings_button_refreshPorts = new QPushButton(portPage_button_frame);
        settings_button_refreshPorts->setObjectName(QStringLiteral("settings_button_refreshPorts"));
        sizePolicy.setHeightForWidth(settings_button_refreshPorts->sizePolicy().hasHeightForWidth());
        settings_button_refreshPorts->setSizePolicy(sizePolicy);
        settings_button_refreshPorts->setMinimumSize(QSize(150, 32));
        settings_button_refreshPorts->setBaseSize(QSize(270, 484));
        settings_button_refreshPorts->setFont(font4);
        settings_button_refreshPorts->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/icons/icon_w_spin1.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_button_refreshPorts->setIcon(icon11);
        settings_button_refreshPorts->setIconSize(QSize(30, 30));
        settings_button_refreshPorts->setFlat(true);

        horizontalLayout_5->addWidget(settings_button_refreshPorts);

        horizontalSpacer_4 = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        portPage_layout->addWidget(portPage_button_frame);

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

        portPage_layout->addWidget(port_view);


        horizontalLayout_6->addLayout(portPage_layout);

        AppPages->addWidget(portPage);
        printToolsPage = new QWidget();
        printToolsPage->setObjectName(QStringLiteral("printToolsPage"));
        printToolsPage->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(printToolsPage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        printToolsPage_Frame = new QFrame(printToolsPage);
        printToolsPage_Frame->setObjectName(QStringLiteral("printToolsPage_Frame"));
        sizePolicy4.setHeightForWidth(printToolsPage_Frame->sizePolicy().hasHeightForWidth());
        printToolsPage_Frame->setSizePolicy(sizePolicy4);
        printToolsPage_Frame->setMinimumSize(QSize(512, 256));
        printToolsPage_Frame->setMaximumSize(QSize(16777215, 16777215));
        printToolsPage_Frame->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 12), stop:1 rgba(128, 128, 128, 35));\n"
"\n"
"\n"
"\n"
"border-radius: 8;\n"
"color: rgb(212,215,217);"));
        printToolsPage_Frame->setFrameShape(QFrame::StyledPanel);
        printToolsPage_Frame->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(printToolsPage_Frame);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        printToolsPage_upper_layout = new QHBoxLayout();
        printToolsPage_upper_layout->setSpacing(6);
        printToolsPage_upper_layout->setObjectName(QStringLiteral("printToolsPage_upper_layout"));
        printTools_button_frame = new QFrame(printToolsPage_Frame);
        printTools_button_frame->setObjectName(QStringLiteral("printTools_button_frame"));
        printTools_button_frame->setMaximumSize(QSize(16777215, 235));
        printTools_button_frame->setStyleSheet(QStringLiteral("background:rgb(22, 22, 22,);"));
        printTools_button_frame->setFrameShape(QFrame::StyledPanel);
        printTools_button_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(printTools_button_frame);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gcode_tool_button_openFile = new QPushButton(printTools_button_frame);
        gcode_tool_button_openFile->setObjectName(QStringLiteral("gcode_tool_button_openFile"));
        sizePolicy3.setHeightForWidth(gcode_tool_button_openFile->sizePolicy().hasHeightForWidth());
        gcode_tool_button_openFile->setSizePolicy(sizePolicy3);
        gcode_tool_button_openFile->setMinimumSize(QSize(32, 32));
        gcode_tool_button_openFile->setBaseSize(QSize(270, 484));
        gcode_tool_button_openFile->setFont(font4);
        gcode_tool_button_openFile->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        gcode_tool_button_openFile->setIcon(icon8);
        gcode_tool_button_openFile->setIconSize(QSize(30, 30));
        gcode_tool_button_openFile->setFlat(true);

        verticalLayout_7->addWidget(gcode_tool_button_openFile);

        printTools_radio_button_frame = new QHBoxLayout();
        printTools_radio_button_frame->setSpacing(6);
        printTools_radio_button_frame->setObjectName(QStringLiteral("printTools_radio_button_frame"));
        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        printTools_radio_button_frame->addItem(horizontalSpacer);

        printTools_button_frame_layout = new QVBoxLayout();
        printTools_button_frame_layout->setSpacing(25);
        printTools_button_frame_layout->setObjectName(QStringLiteral("printTools_button_frame_layout"));
        printTools_display_commands_button = new QRadioButton(printTools_button_frame);
        printTools_display_commands_button->setObjectName(QStringLiteral("printTools_display_commands_button"));
        printTools_display_commands_button->setAutoExclusive(false);

        printTools_button_frame_layout->addWidget(printTools_display_commands_button);

        printTools_displayComments_button = new QRadioButton(printTools_button_frame);
        printTools_displayComments_button->setObjectName(QStringLiteral("printTools_displayComments_button"));
        printTools_displayComments_button->setAutoExclusive(false);

        printTools_button_frame_layout->addWidget(printTools_displayComments_button);

        printTools_ignoreErrors_button = new QRadioButton(printTools_button_frame);
        printTools_ignoreErrors_button->setObjectName(QStringLiteral("printTools_ignoreErrors_button"));
        printTools_ignoreErrors_button->setAutoExclusive(false);

        printTools_button_frame_layout->addWidget(printTools_ignoreErrors_button);


        printTools_radio_button_frame->addLayout(printTools_button_frame_layout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        printTools_radio_button_frame->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(printTools_radio_button_frame);

        gcode_tool_button_clearPart = new QPushButton(printTools_button_frame);
        gcode_tool_button_clearPart->setObjectName(QStringLiteral("gcode_tool_button_clearPart"));
        sizePolicy3.setHeightForWidth(gcode_tool_button_clearPart->sizePolicy().hasHeightForWidth());
        gcode_tool_button_clearPart->setSizePolicy(sizePolicy3);
        gcode_tool_button_clearPart->setMinimumSize(QSize(32, 32));
        gcode_tool_button_clearPart->setFont(font4);
        gcode_tool_button_clearPart->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/icons/iosTrash.png"), QSize(), QIcon::Normal, QIcon::Off);
        gcode_tool_button_clearPart->setIcon(icon12);
        gcode_tool_button_clearPart->setIconSize(QSize(30, 30));
        gcode_tool_button_clearPart->setFlat(true);

        verticalLayout_7->addWidget(gcode_tool_button_clearPart);


        printToolsPage_upper_layout->addWidget(printTools_button_frame);

        partInfoView_frame = new QFrame(printToolsPage_Frame);
        partInfoView_frame->setObjectName(QStringLiteral("partInfoView_frame"));
        partInfoView_frame->setMaximumSize(QSize(512, 235));
        partInfoView_frame->setStyleSheet(QLatin1String("background:rgba(22, 22, 22);\n"
"border-radius: 8;\n"
""));
        partInfoView_frame->setFrameShape(QFrame::StyledPanel);
        partInfoView_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(partInfoView_frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PartInfoView = new QTableView(partInfoView_frame);
        PartInfoView->setObjectName(QStringLiteral("PartInfoView"));
        PartInfoView->setMinimumSize(QSize(0, 200));
        PartInfoView->setMaximumSize(QSize(150, 200));
        PartInfoView->setStyleSheet(QLatin1String("background:rgb(22, 22, 22);\n"
"border-radius: 0;\n"
""));
        PartInfoView->setShowGrid(false);
        PartInfoView->horizontalHeader()->setVisible(false);
        PartInfoView->horizontalHeader()->setHighlightSections(false);
        PartInfoView->verticalHeader()->setVisible(false);
        PartInfoView->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(PartInfoView);

        PartInfoViewData = new QTableView(partInfoView_frame);
        PartInfoViewData->setObjectName(QStringLiteral("PartInfoViewData"));
        PartInfoViewData->setMinimumSize(QSize(0, 200));
        PartInfoViewData->setMaximumSize(QSize(16777215, 200));
        PartInfoViewData->setStyleSheet(QLatin1String("background:rgb(22, 22, 22);\n"
"border-radius: 0;\n"
""));
        PartInfoViewData->setShowGrid(false);
        PartInfoViewData->horizontalHeader()->setVisible(false);
        PartInfoViewData->horizontalHeader()->setHighlightSections(false);
        PartInfoViewData->horizontalHeader()->setStretchLastSection(true);
        PartInfoViewData->verticalHeader()->setVisible(false);
        PartInfoViewData->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(PartInfoViewData);


        printToolsPage_upper_layout->addWidget(partInfoView_frame);


        verticalLayout_10->addLayout(printToolsPage_upper_layout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        printTools_outputBrowser_title = new QLabel(printToolsPage_Frame);
        printTools_outputBrowser_title->setObjectName(QStringLiteral("printTools_outputBrowser_title"));
        QFont font5;
        font5.setPointSize(16);
        printTools_outputBrowser_title->setFont(font5);
        printTools_outputBrowser_title->setStyleSheet(QStringLiteral("background: rgba(0,0,0,0)"));
        printTools_outputBrowser_title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(printTools_outputBrowser_title);

        printTools_gCodeBrowser = new QTextBrowser(printToolsPage_Frame);
        printTools_gCodeBrowser->setObjectName(QStringLiteral("printTools_gCodeBrowser"));
        printTools_gCodeBrowser->setStyleSheet(QStringLiteral("background: rgb(22,22,22);"));

        verticalLayout_2->addWidget(printTools_gCodeBrowser);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        printTools_outputBrowser_title_2 = new QLabel(printToolsPage_Frame);
        printTools_outputBrowser_title_2->setObjectName(QStringLiteral("printTools_outputBrowser_title_2"));
        printTools_outputBrowser_title_2->setFont(font5);
        printTools_outputBrowser_title_2->setStyleSheet(QStringLiteral("background: rgba(0,0,0,0)"));
        printTools_outputBrowser_title_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(printTools_outputBrowser_title_2);

        printTools_outputBrowser = new QTextBrowser(printToolsPage_Frame);
        printTools_outputBrowser->setObjectName(QStringLiteral("printTools_outputBrowser"));
        printTools_outputBrowser->setStyleSheet(QStringLiteral("background: rgb(22,22,22);"));

        verticalLayout_3->addWidget(printTools_outputBrowser);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        printTools_outputBrowser_title_3 = new QLabel(printToolsPage_Frame);
        printTools_outputBrowser_title_3->setObjectName(QStringLiteral("printTools_outputBrowser_title_3"));
        printTools_outputBrowser_title_3->setFont(font5);
        printTools_outputBrowser_title_3->setStyleSheet(QStringLiteral("background: rgba(0,0,0,0)"));
        printTools_outputBrowser_title_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(printTools_outputBrowser_title_3);

        printTools_errorBrowser = new QTextBrowser(printToolsPage_Frame);
        printTools_errorBrowser->setObjectName(QStringLiteral("printTools_errorBrowser"));
        printTools_errorBrowser->setStyleSheet(QStringLiteral("background: rgb(22,22,22);"));

        verticalLayout_6->addWidget(printTools_errorBrowser);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_10->addLayout(horizontalLayout_2);

        printTools_page_acceptPart_button_layou = new QHBoxLayout();
        printTools_page_acceptPart_button_layou->setSpacing(6);
        printTools_page_acceptPart_button_layou->setObjectName(QStringLiteral("printTools_page_acceptPart_button_layou"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        printTools_page_acceptPart_button_layou->addItem(horizontalSpacer_5);

        printTools_page_acceptPart_button_frame = new QFrame(printToolsPage_Frame);
        printTools_page_acceptPart_button_frame->setObjectName(QStringLiteral("printTools_page_acceptPart_button_frame"));
        printTools_page_acceptPart_button_frame->setMinimumSize(QSize(5, 0));
        printTools_page_acceptPart_button_frame->setMaximumSize(QSize(191, 56));
        printTools_page_acceptPart_button_frame->setStyleSheet(QLatin1String("background:\n"
"\n"
"qlineargradient(spread:pad, x1:0.527, y1:1, x2:0.516852, y2:0, stop:0 rgba(89, 84, 91, 45), stop:1 rgba(212, 215, 217, 60));"));
        printTools_page_acceptPart_button_frame->setFrameShape(QFrame::StyledPanel);
        printTools_page_acceptPart_button_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(printTools_page_acceptPart_button_frame);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        printTools_page_acceptPart_button = new QPushButton(printTools_page_acceptPart_button_frame);
        printTools_page_acceptPart_button->setObjectName(QStringLiteral("printTools_page_acceptPart_button"));
        sizePolicy3.setHeightForWidth(printTools_page_acceptPart_button->sizePolicy().hasHeightForWidth());
        printTools_page_acceptPart_button->setSizePolicy(sizePolicy3);
        printTools_page_acceptPart_button->setMinimumSize(QSize(32, 32));
        printTools_page_acceptPart_button->setBaseSize(QSize(270, 484));
        printTools_page_acceptPart_button->setFont(font4);
        printTools_page_acceptPart_button->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/icons/iosPlus.png"), QSize(), QIcon::Normal, QIcon::Off);
        printTools_page_acceptPart_button->setIcon(icon13);
        printTools_page_acceptPart_button->setIconSize(QSize(30, 30));
        printTools_page_acceptPart_button->setFlat(true);

        verticalLayout_8->addWidget(printTools_page_acceptPart_button);


        printTools_page_acceptPart_button_layou->addWidget(printTools_page_acceptPart_button_frame);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        printTools_page_acceptPart_button_layou->addItem(horizontalSpacer_6);


        verticalLayout_10->addLayout(printTools_page_acceptPart_button_layou);


        verticalLayout_5->addWidget(printToolsPage_Frame);

        AppPages->addWidget(printToolsPage);
        dashboardPage = new QWidget();
        dashboardPage->setObjectName(QStringLiteral("dashboardPage"));
        dashboardPage->setStyleSheet(QStringLiteral(""));
        horizontalLayout_7 = new QHBoxLayout(dashboardPage);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        PrintControl_splitter = new QSplitter(dashboardPage);
        PrintControl_splitter->setObjectName(QStringLiteral("PrintControl_splitter"));
        PrintControl_splitter->setMaximumSize(QSize(16777215, 16777215));
        PrintControl_splitter->setOrientation(Qt::Vertical);
        printManager_frame = new QFrame(PrintControl_splitter);
        printManager_frame->setObjectName(QStringLiteral("printManager_frame"));
        printManager_frame->setMinimumSize(QSize(0, 360));
        printManager_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,30);\n"
""));
        printManager_frame->setFrameShape(QFrame::StyledPanel);
        printManager_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(printManager_frame);
        verticalLayout_14->setSpacing(4);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(6, 6, 6, 6);
        PrintManagerTitle_frame = new QFrame(printManager_frame);
        PrintManagerTitle_frame->setObjectName(QStringLiteral("PrintManagerTitle_frame"));
        PrintManagerTitle_frame->setMinimumSize(QSize(286, 0));
        PrintManagerTitle_frame->setMaximumSize(QSize(16777215, 40));
        PrintManagerTitle_frame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        PrintManagerTitle_frame->setFrameShape(QFrame::StyledPanel);
        PrintManagerTitle_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_35 = new QHBoxLayout(PrintManagerTitle_frame);
        horizontalLayout_35->setSpacing(4);
        horizontalLayout_35->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        horizontalLayout_35->setContentsMargins(4, 4, 4, 4);
        PrintManagerEnable_button = new QPushButton(PrintManagerTitle_frame);
        PrintManagerEnable_button->setObjectName(QStringLiteral("PrintManagerEnable_button"));
        sizePolicy.setHeightForWidth(PrintManagerEnable_button->sizePolicy().hasHeightForWidth());
        PrintManagerEnable_button->setSizePolicy(sizePolicy);
        PrintManagerEnable_button->setMinimumSize(QSize(28, 32));
        PrintManagerEnable_button->setBaseSize(QSize(32, 32));
        PrintManagerEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/icons/toggle-off1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon14.addFile(QStringLiteral(":/icons/icons/toggle-on1.png"), QSize(), QIcon::Normal, QIcon::On);
        PrintManagerEnable_button->setIcon(icon14);
        PrintManagerEnable_button->setIconSize(QSize(34, 22));
        PrintManagerEnable_button->setCheckable(true);
        PrintManagerEnable_button->setFlat(true);

        horizontalLayout_35->addWidget(PrintManagerEnable_button, 0, Qt::AlignLeft);

        label_47 = new QLabel(PrintManagerTitle_frame);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setMinimumSize(QSize(225, 32));
        label_47->setMaximumSize(QSize(1000, 16777215));
        label_47->setFont(font);
        label_47->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        label_47->setInputMethodHints(Qt::ImhNoEditMenu);
        label_47->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_35->addWidget(label_47);


        verticalLayout_14->addWidget(PrintManagerTitle_frame);

        printManagerInfo_frame = new QFrame(printManager_frame);
        printManagerInfo_frame->setObjectName(QStringLiteral("printManagerInfo_frame"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(printManagerInfo_frame->sizePolicy().hasHeightForWidth());
        printManagerInfo_frame->setSizePolicy(sizePolicy5);
        printManagerInfo_frame->setMinimumSize(QSize(0, 80));
        printManagerInfo_frame->setMaximumSize(QSize(16777215, 100));
        printManagerInfo_frame->setBaseSize(QSize(0, 70));
        printManagerInfo_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,40)"));
        printManagerInfo_frame->setFrameShape(QFrame::StyledPanel);
        printManagerInfo_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(printManagerInfo_frame);
        verticalLayout_9->setSpacing(4);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(6, 6, 6, 6);
        printManagerStatus_layout = new QHBoxLayout();
        printManagerStatus_layout->setSpacing(0);
        printManagerStatus_layout->setObjectName(QStringLiteral("printManagerStatus_layout"));
        printManagerStatus_indicator = new QPushButton(printManagerInfo_frame);
        printManagerStatus_indicator->setObjectName(QStringLiteral("printManagerStatus_indicator"));
        printManagerStatus_indicator->setMaximumSize(QSize(20, 16777215));
        printManagerStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        printManagerStatus_indicator->setIcon(icon);
        printManagerStatus_indicator->setFlat(true);

        printManagerStatus_layout->addWidget(printManagerStatus_indicator);

        printManagerStatus_title = new QLabel(printManagerInfo_frame);
        printManagerStatus_title->setObjectName(QStringLiteral("printManagerStatus_title"));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        printManagerStatus_title->setFont(font6);
        printManagerStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        printManagerStatus_layout->addWidget(printManagerStatus_title);

        printManager_status_field = new QLabel(printManagerInfo_frame);
        printManager_status_field->setObjectName(QStringLiteral("printManager_status_field"));
        printManager_status_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        printManagerStatus_layout->addWidget(printManager_status_field);


        verticalLayout_9->addLayout(printManagerStatus_layout);

        printManagerFile_layout = new QHBoxLayout();
        printManagerFile_layout->setSpacing(6);
        printManagerFile_layout->setObjectName(QStringLiteral("printManagerFile_layout"));
        activeFile_titleLabel = new QLabel(printManagerInfo_frame);
        activeFile_titleLabel->setObjectName(QStringLiteral("activeFile_titleLabel"));
        activeFile_titleLabel->setFont(font6);
        activeFile_titleLabel->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        printManagerFile_layout->addWidget(activeFile_titleLabel);

        printManager_file_field = new QLabel(printManagerInfo_frame);
        printManager_file_field->setObjectName(QStringLiteral("printManager_file_field"));
        printManager_file_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        printManagerFile_layout->addWidget(printManager_file_field);


        verticalLayout_9->addLayout(printManagerFile_layout);

        printManager_options_box = new QComboBox(printManagerInfo_frame);
        printManager_options_box->addItem(QString());
        printManager_options_box->setObjectName(QStringLiteral("printManager_options_box"));
        printManager_options_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        verticalLayout_9->addWidget(printManager_options_box);


        verticalLayout_14->addWidget(printManagerInfo_frame);

        printManagerControls_frame = new QFrame(printManager_frame);
        printManagerControls_frame->setObjectName(QStringLiteral("printManagerControls_frame"));
        printManagerControls_frame->setMinimumSize(QSize(0, 50));
        printManagerControls_frame->setMaximumSize(QSize(16777215, 65));
        printManagerControls_frame->setStyleSheet(QStringLiteral("background: rgba(212,215,217,35)"));
        printManagerControls_frame->setFrameShape(QFrame::StyledPanel);
        printManagerControls_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(printManagerControls_frame);
        horizontalLayout_10->setSpacing(4);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(6, 6, 6, 6);
        printManager_stop_button = new QPushButton(printManagerControls_frame);
        printManager_stop_button->setObjectName(QStringLiteral("printManager_stop_button"));
        sizePolicy3.setHeightForWidth(printManager_stop_button->sizePolicy().hasHeightForWidth());
        printManager_stop_button->setSizePolicy(sizePolicy3);
        printManager_stop_button->setMinimumSize(QSize(32, 32));
        printManager_stop_button->setFont(font4);
        printManager_stop_button->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        printManager_stop_button->setIcon(icon15);
        printManager_stop_button->setIconSize(QSize(21, 36));
        printManager_stop_button->setFlat(true);

        horizontalLayout_10->addWidget(printManager_stop_button);

        printManager_pause_button = new QPushButton(printManagerControls_frame);
        printManager_pause_button->setObjectName(QStringLiteral("printManager_pause_button"));
        sizePolicy3.setHeightForWidth(printManager_pause_button->sizePolicy().hasHeightForWidth());
        printManager_pause_button->setSizePolicy(sizePolicy3);
        printManager_pause_button->setMinimumSize(QSize(32, 32));
        printManager_pause_button->setFont(font4);
        printManager_pause_button->setStyleSheet(QLatin1String("background: none;\n"
"color: rgb(212,215,217);"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/icons/iosPause.png"), QSize(), QIcon::Normal, QIcon::Off);
        printManager_pause_button->setIcon(icon16);
        printManager_pause_button->setIconSize(QSize(21, 36));
        printManager_pause_button->setFlat(true);

        horizontalLayout_10->addWidget(printManager_pause_button);

        printManager_stepThrough_button = new QPushButton(printManagerControls_frame);
        printManager_stepThrough_button->setObjectName(QStringLiteral("printManager_stepThrough_button"));
        sizePolicy3.setHeightForWidth(printManager_stepThrough_button->sizePolicy().hasHeightForWidth());
        printManager_stepThrough_button->setSizePolicy(sizePolicy3);
        printManager_stepThrough_button->setMinimumSize(QSize(32, 32));
        printManager_stepThrough_button->setFont(font4);
        printManager_stepThrough_button->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/icons/icons/iosSkipforward.png"), QSize(), QIcon::Normal, QIcon::Off);
        printManager_stepThrough_button->setIcon(icon17);
        printManager_stepThrough_button->setIconSize(QSize(23, 36));
        printManager_stepThrough_button->setFlat(true);

        horizontalLayout_10->addWidget(printManager_stepThrough_button);

        printManager_start_button = new QPushButton(printManagerControls_frame);
        printManager_start_button->setObjectName(QStringLiteral("printManager_start_button"));
        sizePolicy3.setHeightForWidth(printManager_start_button->sizePolicy().hasHeightForWidth());
        printManager_start_button->setSizePolicy(sizePolicy3);
        printManager_start_button->setMinimumSize(QSize(32, 32));
        printManager_start_button->setFont(font4);
        printManager_start_button->setStyleSheet(QLatin1String("background: rgba(0,0,0,0);\n"
"color: rgb(212,215,217);"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/icons/icons/iosPlay.png"), QSize(), QIcon::Normal, QIcon::Off);
        printManager_start_button->setIcon(icon18);
        printManager_start_button->setIconSize(QSize(18, 36));
        printManager_start_button->setFlat(true);

        horizontalLayout_10->addWidget(printManager_start_button);


        verticalLayout_14->addWidget(printManagerControls_frame);

        printManager_textBrowser = new QTextBrowser(printManager_frame);
        printManager_textBrowser->setObjectName(QStringLiteral("printManager_textBrowser"));
        sizePolicy.setHeightForWidth(printManager_textBrowser->sizePolicy().hasHeightForWidth());
        printManager_textBrowser->setSizePolicy(sizePolicy);
        printManager_textBrowser->setMaximumSize(QSize(16777215, 500));

        verticalLayout_14->addWidget(printManager_textBrowser);

        blockProgress_frame = new QFrame(printManager_frame);
        blockProgress_frame->setObjectName(QStringLiteral("blockProgress_frame"));
        blockProgress_frame->setMinimumSize(QSize(0, 0));
        blockProgress_frame->setMaximumSize(QSize(16777215, 40));
        blockProgress_frame->setBaseSize(QSize(0, 41));
        blockProgress_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,40);\n"
""));
        blockProgress_frame->setFrameShape(QFrame::StyledPanel);
        blockProgress_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_16 = new QVBoxLayout(blockProgress_frame);
        verticalLayout_16->setSpacing(4);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(6, 6, 6, 6);
        blockProgress_layout = new QHBoxLayout();
        blockProgress_layout->setSpacing(6);
        blockProgress_layout->setObjectName(QStringLiteral("blockProgress_layout"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        blockProgress_layout->addItem(horizontalSpacer_11);

        blockTitle_label = new QLabel(blockProgress_frame);
        blockTitle_label->setObjectName(QStringLiteral("blockTitle_label"));
        blockTitle_label->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        blockProgress_layout->addWidget(blockTitle_label);

        currentBlock_field = new QLabel(blockProgress_frame);
        currentBlock_field->setObjectName(QStringLiteral("currentBlock_field"));
        currentBlock_field->setMinimumSize(QSize(12, 0));
        currentBlock_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        blockProgress_layout->addWidget(currentBlock_field);

        blockOf_label = new QLabel(blockProgress_frame);
        blockOf_label->setObjectName(QStringLiteral("blockOf_label"));
        blockOf_label->setMaximumSize(QSize(12, 16777215));
        blockOf_label->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        blockProgress_layout->addWidget(blockOf_label);

        totalBlocks_field = new QLabel(blockProgress_frame);
        totalBlocks_field->setObjectName(QStringLiteral("totalBlocks_field"));
        totalBlocks_field->setMinimumSize(QSize(12, 0));
        totalBlocks_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        blockProgress_layout->addWidget(totalBlocks_field);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        blockProgress_layout->addItem(horizontalSpacer_10);


        verticalLayout_16->addLayout(blockProgress_layout);

        printManager_block_bar = new QProgressBar(blockProgress_frame);
        printManager_block_bar->setObjectName(QStringLiteral("printManager_block_bar"));
        printManager_block_bar->setStyleSheet(QStringLiteral("background: rgba(0,0,0,0)"));
        printManager_block_bar->setValue(24);

        verticalLayout_16->addWidget(printManager_block_bar);


        verticalLayout_14->addWidget(blockProgress_frame);

        layerProgress_frame = new QFrame(printManager_frame);
        layerProgress_frame->setObjectName(QStringLiteral("layerProgress_frame"));
        layerProgress_frame->setMinimumSize(QSize(0, 0));
        layerProgress_frame->setMaximumSize(QSize(16777215, 40));
        layerProgress_frame->setBaseSize(QSize(0, 41));
        layerProgress_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,40);\n"
""));
        layerProgress_frame->setFrameShape(QFrame::StyledPanel);
        layerProgress_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_20 = new QVBoxLayout(layerProgress_frame);
        verticalLayout_20->setSpacing(4);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(6, 6, 6, 6);
        LayerProgress_layout = new QHBoxLayout();
        LayerProgress_layout->setSpacing(6);
        LayerProgress_layout->setObjectName(QStringLiteral("LayerProgress_layout"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        LayerProgress_layout->addItem(horizontalSpacer_12);

        layerTitle_label = new QLabel(layerProgress_frame);
        layerTitle_label->setObjectName(QStringLiteral("layerTitle_label"));
        layerTitle_label->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LayerProgress_layout->addWidget(layerTitle_label);

        currentLayer_field = new QLabel(layerProgress_frame);
        currentLayer_field->setObjectName(QStringLiteral("currentLayer_field"));
        currentLayer_field->setMinimumSize(QSize(12, 0));
        currentLayer_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LayerProgress_layout->addWidget(currentLayer_field);

        layerOf_label = new QLabel(layerProgress_frame);
        layerOf_label->setObjectName(QStringLiteral("layerOf_label"));
        layerOf_label->setMaximumSize(QSize(12, 16777215));
        layerOf_label->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LayerProgress_layout->addWidget(layerOf_label);

        totalLayers_field = new QLabel(layerProgress_frame);
        totalLayers_field->setObjectName(QStringLiteral("totalLayers_field"));
        totalLayers_field->setMinimumSize(QSize(12, 0));
        totalLayers_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LayerProgress_layout->addWidget(totalLayers_field);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        LayerProgress_layout->addItem(horizontalSpacer_13);


        verticalLayout_20->addLayout(LayerProgress_layout);

        printManager_layer_bar = new QProgressBar(layerProgress_frame);
        printManager_layer_bar->setObjectName(QStringLiteral("printManager_layer_bar"));
        printManager_layer_bar->setStyleSheet(QStringLiteral("background: rgba(0,0,0,0)"));
        printManager_layer_bar->setValue(24);

        verticalLayout_20->addWidget(printManager_layer_bar);


        verticalLayout_14->addWidget(layerProgress_frame);

        PrintControl_splitter->addWidget(printManager_frame);
        ManualControl_Frame = new QFrame(PrintControl_splitter);
        ManualControl_Frame->setObjectName(QStringLiteral("ManualControl_Frame"));
        ManualControl_Frame->setMinimumSize(QSize(0, 350));
        ManualControl_Frame->setMaximumSize(QSize(16777215, 400));
        ManualControl_Frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,30);\n"
""));
        ManualControl_Frame->setFrameShape(QFrame::StyledPanel);
        ManualControl_Frame->setFrameShadow(QFrame::Raised);
        verticalLayout_34 = new QVBoxLayout(ManualControl_Frame);
        verticalLayout_34->setSpacing(4);
        verticalLayout_34->setContentsMargins(11, 11, 11, 11);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        verticalLayout_34->setContentsMargins(6, 6, 6, 6);
        ManualControlTitle_frame = new QFrame(ManualControl_Frame);
        ManualControlTitle_frame->setObjectName(QStringLiteral("ManualControlTitle_frame"));
        ManualControlTitle_frame->setMinimumSize(QSize(286, 0));
        ManualControlTitle_frame->setMaximumSize(QSize(16777215, 40));
        ManualControlTitle_frame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        ManualControlTitle_frame->setFrameShape(QFrame::StyledPanel);
        ManualControlTitle_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_32 = new QHBoxLayout(ManualControlTitle_frame);
        horizontalLayout_32->setSpacing(4);
        horizontalLayout_32->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalLayout_32->setContentsMargins(4, 4, 4, 4);
        ManualControlEnable_button = new QPushButton(ManualControlTitle_frame);
        ManualControlEnable_button->setObjectName(QStringLiteral("ManualControlEnable_button"));
        sizePolicy.setHeightForWidth(ManualControlEnable_button->sizePolicy().hasHeightForWidth());
        ManualControlEnable_button->setSizePolicy(sizePolicy);
        ManualControlEnable_button->setMinimumSize(QSize(28, 32));
        ManualControlEnable_button->setBaseSize(QSize(32, 32));
        ManualControlEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        ManualControlEnable_button->setIcon(icon14);
        ManualControlEnable_button->setIconSize(QSize(34, 22));
        ManualControlEnable_button->setCheckable(true);
        ManualControlEnable_button->setFlat(true);

        horizontalLayout_32->addWidget(ManualControlEnable_button, 0, Qt::AlignLeft);

        label_46 = new QLabel(ManualControlTitle_frame);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setMinimumSize(QSize(225, 32));
        label_46->setMaximumSize(QSize(1000, 16777215));
        label_46->setFont(font);
        label_46->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        label_46->setInputMethodHints(Qt::ImhNoEditMenu);
        label_46->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_32->addWidget(label_46, 0, Qt::AlignHCenter);


        verticalLayout_34->addWidget(ManualControlTitle_frame);

        ManualControlHome_frame = new QFrame(ManualControl_Frame);
        ManualControlHome_frame->setObjectName(QStringLiteral("ManualControlHome_frame"));
        sizePolicy.setHeightForWidth(ManualControlHome_frame->sizePolicy().hasHeightForWidth());
        ManualControlHome_frame->setSizePolicy(sizePolicy);
        ManualControlHome_frame->setMinimumSize(QSize(286, 0));
        ManualControlHome_frame->setMaximumSize(QSize(320, 50));
        ManualControlHome_frame->setFrameShape(QFrame::StyledPanel);
        ManualControlHome_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_42 = new QHBoxLayout(ManualControlHome_frame);
        horizontalLayout_42->setSpacing(4);
        horizontalLayout_42->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        horizontalLayout_42->setContentsMargins(4, 4, 4, 4);
        ManualControlHome_button = new QPushButton(ManualControlHome_frame);
        ManualControlHome_button->setObjectName(QStringLiteral("ManualControlHome_button"));
        sizePolicy3.setHeightForWidth(ManualControlHome_button->sizePolicy().hasHeightForWidth());
        ManualControlHome_button->setSizePolicy(sizePolicy3);
        ManualControlHome_button->setMinimumSize(QSize(100, 32));
        ManualControlHome_button->setFont(font4);
        ManualControlHome_button->setLayoutDirection(Qt::LeftToRight);
        ManualControlHome_button->setStyleSheet(QLatin1String("background: none;\n"
"color: rgb(143, 143, 143);"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/icons/icons/Homing.png"), QSize(), QIcon::Normal, QIcon::Off);
        ManualControlHome_button->setIcon(icon19);
        ManualControlHome_button->setIconSize(QSize(27, 36));
        ManualControlHome_button->setFlat(true);

        horizontalLayout_42->addWidget(ManualControlHome_button);

        ManualControlHome_options_box = new QComboBox(ManualControlHome_frame);
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->addItem(QString());
        ManualControlHome_options_box->setObjectName(QStringLiteral("ManualControlHome_options_box"));
        ManualControlHome_options_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        horizontalLayout_42->addWidget(ManualControlHome_options_box, 0, Qt::AlignVCenter);


        verticalLayout_34->addWidget(ManualControlHome_frame, 0, Qt::AlignHCenter);

        ManualControlTop_frame = new QFrame(ManualControl_Frame);
        ManualControlTop_frame->setObjectName(QStringLiteral("ManualControlTop_frame"));
        ManualControlTop_frame->setMinimumSize(QSize(286, 0));
        ManualControlTop_frame->setMaximumSize(QSize(320, 16777215));
        ManualControlTop_frame->setFrameShape(QFrame::StyledPanel);
        ManualControlTop_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_44 = new QHBoxLayout(ManualControlTop_frame);
        horizontalLayout_44->setSpacing(4);
        horizontalLayout_44->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_44->setObjectName(QStringLiteral("horizontalLayout_44"));
        horizontalLayout_44->setContentsMargins(4, 4, 4, 4);
        JogDistanceFrame = new QFrame(ManualControlTop_frame);
        JogDistanceFrame->setObjectName(QStringLiteral("JogDistanceFrame"));
        JogDistanceFrame->setStyleSheet(QStringLiteral("color: rgba(212,215,217,150);"));
        JogDistanceFrame->setFrameShape(QFrame::StyledPanel);
        JogDistanceFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_35 = new QVBoxLayout(JogDistanceFrame);
        verticalLayout_35->setSpacing(4);
        verticalLayout_35->setContentsMargins(11, 11, 11, 11);
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        verticalLayout_35->setContentsMargins(4, 4, 4, 4);
        jogDistance_title = new QLabel(JogDistanceFrame);
        jogDistance_title->setObjectName(QStringLiteral("jogDistance_title"));
        sizePolicy.setHeightForWidth(jogDistance_title->sizePolicy().hasHeightForWidth());
        jogDistance_title->setSizePolicy(sizePolicy);
        jogDistance_title->setMinimumSize(QSize(0, 18));
        jogDistance_title->setMaximumSize(QSize(200, 24));
        QFont font7;
        font7.setPointSize(14);
        font7.setBold(false);
        font7.setWeight(50);
        jogDistance_title->setFont(font7);
        jogDistance_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,150);"));
        jogDistance_title->setAlignment(Qt::AlignCenter);

        verticalLayout_35->addWidget(jogDistance_title);

        jogDistanceSubFrame = new QFrame(JogDistanceFrame);
        jogDistanceSubFrame->setObjectName(QStringLiteral("jogDistanceSubFrame"));
        jogDistanceSubFrame->setMinimumSize(QSize(0, 68));
        jogDistanceSubFrame->setFrameShape(QFrame::StyledPanel);
        jogDistanceSubFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_45 = new QHBoxLayout(jogDistanceSubFrame);
        horizontalLayout_45->setSpacing(4);
        horizontalLayout_45->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_45->setObjectName(QStringLiteral("horizontalLayout_45"));
        horizontalLayout_45->setContentsMargins(4, 4, 4, 4);
        printManager_JogDistance_Input = new QDoubleSpinBox(jogDistanceSubFrame);
        printManager_JogDistance_Input->setObjectName(QStringLiteral("printManager_JogDistance_Input"));

        horizontalLayout_45->addWidget(printManager_JogDistance_Input);

        jog_units_label = new QLabel(jogDistanceSubFrame);
        jog_units_label->setObjectName(QStringLiteral("jog_units_label"));
        jog_units_label->setMinimumSize(QSize(35, 24));
        jog_units_label->setMaximumSize(QSize(40, 24));
        QFont font8;
        font8.setPointSize(12);
        jog_units_label->setFont(font8);
        jog_units_label->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        jog_units_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_45->addWidget(jog_units_label);


        verticalLayout_35->addWidget(jogDistanceSubFrame);


        horizontalLayout_44->addWidget(JogDistanceFrame);

        GalvoJog_frame = new QFrame(ManualControlTop_frame);
        GalvoJog_frame->setObjectName(QStringLiteral("GalvoJog_frame"));
        GalvoJog_frame->setMaximumSize(QSize(16777215, 128));
        GalvoJog_frame->setFrameShape(QFrame::StyledPanel);
        GalvoJog_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_26 = new QVBoxLayout(GalvoJog_frame);
        verticalLayout_26->setSpacing(4);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_26->setContentsMargins(4, 4, 4, 4);
        galvo_jog_control_title = new QLabel(GalvoJog_frame);
        galvo_jog_control_title->setObjectName(QStringLiteral("galvo_jog_control_title"));
        galvo_jog_control_title->setMinimumSize(QSize(100, 24));
        galvo_jog_control_title->setMaximumSize(QSize(300, 24));
        QFont font9;
        font9.setPointSize(15);
        font9.setBold(false);
        font9.setWeight(50);
        galvo_jog_control_title->setFont(font9);
        galvo_jog_control_title->setStyleSheet(QLatin1String("background: rgba(0,0,0,50);\n"
"color: rgba(212,215,217,150);"));
        galvo_jog_control_title->setInputMethodHints(Qt::ImhNoEditMenu);
        galvo_jog_control_title->setAlignment(Qt::AlignCenter);

        verticalLayout_26->addWidget(galvo_jog_control_title);

        GalvoJog_layout = new QHBoxLayout();
        GalvoJog_layout->setSpacing(4);
        GalvoJog_layout->setObjectName(QStringLiteral("GalvoJog_layout"));
        jogXminus_button = new QPushButton(GalvoJog_frame);
        jogXminus_button->setObjectName(QStringLiteral("jogXminus_button"));
        jogXminus_button->setMinimumSize(QSize(40, 68));
        QFont font10;
        font10.setPointSize(19);
        font10.setBold(true);
        font10.setWeight(75);
        jogXminus_button->setFont(font10);
        jogXminus_button->setLayoutDirection(Qt::LeftToRight);
        jogXminus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/icons/icons/iosArrowLeft.png"), QSize(), QIcon::Normal, QIcon::Off);
        jogXminus_button->setIcon(icon20);
        jogXminus_button->setIconSize(QSize(14, 24));
        jogXminus_button->setAutoDefault(false);

        GalvoJog_layout->addWidget(jogXminus_button);

        yJogLayout = new QVBoxLayout();
        yJogLayout->setSpacing(4);
        yJogLayout->setObjectName(QStringLiteral("yJogLayout"));
        jogYplus_button = new QPushButton(GalvoJog_frame);
        jogYplus_button->setObjectName(QStringLiteral("jogYplus_button"));
        jogYplus_button->setMinimumSize(QSize(0, 32));
        jogYplus_button->setFont(font10);
        jogYplus_button->setLayoutDirection(Qt::RightToLeft);
        jogYplus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/icons/icons/iosArrowForward.png"), QSize(), QIcon::Normal, QIcon::Off);
        jogYplus_button->setIcon(icon21);
        jogYplus_button->setIconSize(QSize(24, 14));
        jogYplus_button->setAutoDefault(false);

        yJogLayout->addWidget(jogYplus_button);

        jogYminus_button = new QPushButton(GalvoJog_frame);
        jogYminus_button->setObjectName(QStringLiteral("jogYminus_button"));
        jogYminus_button->setMinimumSize(QSize(64, 32));
        jogYminus_button->setFont(font10);
        jogYminus_button->setLayoutDirection(Qt::RightToLeft);
        jogYminus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/icons/icons/iosArrowDown.png"), QSize(), QIcon::Normal, QIcon::Off);
        jogYminus_button->setIcon(icon22);
        jogYminus_button->setIconSize(QSize(24, 14));
        jogYminus_button->setAutoDefault(false);

        yJogLayout->addWidget(jogYminus_button);


        GalvoJog_layout->addLayout(yJogLayout);

        jogXplus_button = new QPushButton(GalvoJog_frame);
        jogXplus_button->setObjectName(QStringLiteral("jogXplus_button"));
        jogXplus_button->setMinimumSize(QSize(40, 68));
        jogXplus_button->setFont(font10);
        jogXplus_button->setLayoutDirection(Qt::RightToLeft);
        jogXplus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/icons/icons/iosArrowRight copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        jogXplus_button->setIcon(icon23);
        jogXplus_button->setIconSize(QSize(14, 24));
        jogXplus_button->setAutoDefault(false);

        GalvoJog_layout->addWidget(jogXplus_button);


        verticalLayout_26->addLayout(GalvoJog_layout);


        horizontalLayout_44->addWidget(GalvoJog_frame);


        verticalLayout_34->addWidget(ManualControlTop_frame, 0, Qt::AlignHCenter);

        materialDeliveryControl_frame = new QFrame(ManualControl_Frame);
        materialDeliveryControl_frame->setObjectName(QStringLiteral("materialDeliveryControl_frame"));
        materialDeliveryControl_frame->setMinimumSize(QSize(286, 128));
        materialDeliveryControl_frame->setMaximumSize(QSize(320, 16777215));
        materialDeliveryControl_frame->setFrameShape(QFrame::StyledPanel);
        materialDeliveryControl_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_31 = new QVBoxLayout(materialDeliveryControl_frame);
        verticalLayout_31->setSpacing(4);
        verticalLayout_31->setContentsMargins(11, 11, 11, 11);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        verticalLayout_31->setContentsMargins(4, 0, 4, 4);
        jogControl_titleLayout = new QHBoxLayout();
        jogControl_titleLayout->setSpacing(4);
        jogControl_titleLayout->setObjectName(QStringLiteral("jogControl_titleLayout"));
        build_jog_control_title = new QLabel(materialDeliveryControl_frame);
        build_jog_control_title->setObjectName(QStringLiteral("build_jog_control_title"));
        build_jog_control_title->setMinimumSize(QSize(85, 28));
        build_jog_control_title->setMaximumSize(QSize(90, 24));
        build_jog_control_title->setFont(font9);
        build_jog_control_title->setStyleSheet(QLatin1String("background: rgba(0,0,0,50);\n"
"color: rgba(212,215,217,150);"));
        build_jog_control_title->setInputMethodHints(Qt::ImhNoEditMenu);
        build_jog_control_title->setAlignment(Qt::AlignCenter);

        jogControl_titleLayout->addWidget(build_jog_control_title);

        hopper_jog_control_title = new QLabel(materialDeliveryControl_frame);
        hopper_jog_control_title->setObjectName(QStringLiteral("hopper_jog_control_title"));
        hopper_jog_control_title->setMinimumSize(QSize(85, 28));
        hopper_jog_control_title->setMaximumSize(QSize(90, 24));
        hopper_jog_control_title->setFont(font9);
        hopper_jog_control_title->setStyleSheet(QLatin1String("background: rgba(0,0,0,50);\n"
"color: rgba(212,215,217,150);"));
        hopper_jog_control_title->setInputMethodHints(Qt::ImhNoEditMenu);
        hopper_jog_control_title->setAlignment(Qt::AlignCenter);

        jogControl_titleLayout->addWidget(hopper_jog_control_title);

        spreader_jog_control_title = new QLabel(materialDeliveryControl_frame);
        spreader_jog_control_title->setObjectName(QStringLiteral("spreader_jog_control_title"));
        spreader_jog_control_title->setMinimumSize(QSize(85, 28));
        spreader_jog_control_title->setMaximumSize(QSize(90, 24));
        spreader_jog_control_title->setFont(font9);
        spreader_jog_control_title->setStyleSheet(QLatin1String("background: rgba(0,0,0,50);\n"
"color: rgba(212,215,217,150);"));
        spreader_jog_control_title->setInputMethodHints(Qt::ImhNoEditMenu);
        spreader_jog_control_title->setAlignment(Qt::AlignCenter);

        jogControl_titleLayout->addWidget(spreader_jog_control_title);


        verticalLayout_31->addLayout(jogControl_titleLayout);

        materialDeliveryJog_layout = new QHBoxLayout();
        materialDeliveryJog_layout->setSpacing(0);
        materialDeliveryJog_layout->setObjectName(QStringLiteral("materialDeliveryJog_layout"));
        zJog_layout = new QVBoxLayout();
        zJog_layout->setSpacing(4);
        zJog_layout->setObjectName(QStringLiteral("zJog_layout"));
        jogZplus_button = new QPushButton(materialDeliveryControl_frame);
        jogZplus_button->setObjectName(QStringLiteral("jogZplus_button"));
        jogZplus_button->setMinimumSize(QSize(80, 32));
        jogZplus_button->setMaximumSize(QSize(85, 16777215));
        jogZplus_button->setFont(font10);
        jogZplus_button->setLayoutDirection(Qt::RightToLeft);
        jogZplus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        jogZplus_button->setIcon(icon21);
        jogZplus_button->setIconSize(QSize(24, 14));
        jogZplus_button->setAutoDefault(false);

        zJog_layout->addWidget(jogZplus_button, 0, Qt::AlignHCenter);

        jogZminus_button = new QPushButton(materialDeliveryControl_frame);
        jogZminus_button->setObjectName(QStringLiteral("jogZminus_button"));
        jogZminus_button->setMinimumSize(QSize(80, 32));
        jogZminus_button->setMaximumSize(QSize(85, 16777215));
        jogZminus_button->setFont(font10);
        jogZminus_button->setLayoutDirection(Qt::RightToLeft);
        jogZminus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        jogZminus_button->setIcon(icon22);
        jogZminus_button->setIconSize(QSize(24, 14));
        jogZminus_button->setAutoDefault(false);

        zJog_layout->addWidget(jogZminus_button, 0, Qt::AlignHCenter);


        materialDeliveryJog_layout->addLayout(zJog_layout);

        hJog_layout = new QVBoxLayout();
        hJog_layout->setSpacing(4);
        hJog_layout->setObjectName(QStringLiteral("hJog_layout"));
        jogHplus_button = new QPushButton(materialDeliveryControl_frame);
        jogHplus_button->setObjectName(QStringLiteral("jogHplus_button"));
        jogHplus_button->setMinimumSize(QSize(80, 32));
        jogHplus_button->setMaximumSize(QSize(85, 16777215));
        jogHplus_button->setFont(font10);
        jogHplus_button->setLayoutDirection(Qt::RightToLeft);
        jogHplus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        jogHplus_button->setIcon(icon21);
        jogHplus_button->setIconSize(QSize(24, 14));
        jogHplus_button->setAutoDefault(false);

        hJog_layout->addWidget(jogHplus_button, 0, Qt::AlignHCenter);

        jogHminus_button = new QPushButton(materialDeliveryControl_frame);
        jogHminus_button->setObjectName(QStringLiteral("jogHminus_button"));
        jogHminus_button->setMinimumSize(QSize(80, 32));
        jogHminus_button->setMaximumSize(QSize(85, 16777215));
        jogHminus_button->setFont(font10);
        jogHminus_button->setLayoutDirection(Qt::RightToLeft);
        jogHminus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        jogHminus_button->setIcon(icon22);
        jogHminus_button->setIconSize(QSize(24, 14));
        jogHminus_button->setAutoDefault(false);

        hJog_layout->addWidget(jogHminus_button, 0, Qt::AlignHCenter);


        materialDeliveryJog_layout->addLayout(hJog_layout);

        sJog_layout = new QHBoxLayout();
        sJog_layout->setSpacing(2);
        sJog_layout->setObjectName(QStringLiteral("sJog_layout"));
        jogSminus_button = new QPushButton(materialDeliveryControl_frame);
        jogSminus_button->setObjectName(QStringLiteral("jogSminus_button"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(jogSminus_button->sizePolicy().hasHeightForWidth());
        jogSminus_button->setSizePolicy(sizePolicy6);
        jogSminus_button->setMinimumSize(QSize(40, 32));
        jogSminus_button->setMaximumSize(QSize(50, 64));
        jogSminus_button->setFont(font10);
        jogSminus_button->setLayoutDirection(Qt::LeftToRight);
        jogSminus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        jogSminus_button->setIcon(icon20);
        jogSminus_button->setIconSize(QSize(14, 24));
        jogSminus_button->setAutoDefault(false);

        sJog_layout->addWidget(jogSminus_button, 0, Qt::AlignHCenter);

        jogSplus_button = new QPushButton(materialDeliveryControl_frame);
        jogSplus_button->setObjectName(QStringLiteral("jogSplus_button"));
        sizePolicy.setHeightForWidth(jogSplus_button->sizePolicy().hasHeightForWidth());
        jogSplus_button->setSizePolicy(sizePolicy);
        jogSplus_button->setMinimumSize(QSize(40, 32));
        jogSplus_button->setMaximumSize(QSize(50, 64));
        jogSplus_button->setFont(font10);
        jogSplus_button->setLayoutDirection(Qt::RightToLeft);
        jogSplus_button->setStyleSheet(QStringLiteral("color: rgb(143, 143, 143);"));
        jogSplus_button->setIcon(icon23);
        jogSplus_button->setIconSize(QSize(14, 24));
        jogSplus_button->setAutoDefault(false);

        sJog_layout->addWidget(jogSplus_button, 0, Qt::AlignHCenter);


        materialDeliveryJog_layout->addLayout(sJog_layout);


        verticalLayout_31->addLayout(materialDeliveryJog_layout);


        verticalLayout_34->addWidget(materialDeliveryControl_frame, 0, Qt::AlignHCenter);

        PrintControl_splitter->addWidget(ManualControl_Frame);

        horizontalLayout_7->addWidget(PrintControl_splitter);

        DeviceDisplay_Layout = new QVBoxLayout();
        DeviceDisplay_Layout->setSpacing(6);
        DeviceDisplay_Layout->setObjectName(QStringLiteral("DeviceDisplay_Layout"));
        laserDisplay_frame = new QFrame(dashboardPage);
        laserDisplay_frame->setObjectName(QStringLiteral("laserDisplay_frame"));
        laserDisplay_frame->setMinimumSize(QSize(0, 135));
        laserDisplay_frame->setMaximumSize(QSize(530, 145));
        laserDisplay_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,24);\n"
""));
        laserDisplay_frame->setFrameShape(QFrame::StyledPanel);
        laserDisplay_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_24 = new QHBoxLayout(laserDisplay_frame);
        horizontalLayout_24->setSpacing(4);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(6, 6, 6, 6);
        LaserDisplayInfo_frame = new QFrame(laserDisplay_frame);
        LaserDisplayInfo_frame->setObjectName(QStringLiteral("LaserDisplayInfo_frame"));
        LaserDisplayInfo_frame->setMinimumSize(QSize(225, 0));
        LaserDisplayInfo_frame->setMaximumSize(QSize(300, 16777215));
        LaserDisplayInfo_frame->setFrameShape(QFrame::StyledPanel);
        LaserDisplayInfo_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(LaserDisplayInfo_frame);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(4, 4, 4, 4);
        laserDisplaTitle_frame = new QFrame(LaserDisplayInfo_frame);
        laserDisplaTitle_frame->setObjectName(QStringLiteral("laserDisplaTitle_frame"));
        laserDisplaTitle_frame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        laserDisplaTitle_frame->setFrameShape(QFrame::StyledPanel);
        laserDisplaTitle_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_37 = new QHBoxLayout(laserDisplaTitle_frame);
        horizontalLayout_37->setSpacing(4);
        horizontalLayout_37->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        horizontalLayout_37->setContentsMargins(4, 4, 4, 4);
        laserDisplayEnable_button = new QPushButton(laserDisplaTitle_frame);
        laserDisplayEnable_button->setObjectName(QStringLiteral("laserDisplayEnable_button"));
        sizePolicy.setHeightForWidth(laserDisplayEnable_button->sizePolicy().hasHeightForWidth());
        laserDisplayEnable_button->setSizePolicy(sizePolicy);
        laserDisplayEnable_button->setMinimumSize(QSize(28, 32));
        laserDisplayEnable_button->setBaseSize(QSize(32, 32));
        laserDisplayEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        laserDisplayEnable_button->setIcon(icon14);
        laserDisplayEnable_button->setIconSize(QSize(34, 22));
        laserDisplayEnable_button->setCheckable(true);
        laserDisplayEnable_button->setFlat(true);

        horizontalLayout_37->addWidget(laserDisplayEnable_button, 0, Qt::AlignLeft);

        laserDispla_title = new QLabel(laserDisplaTitle_frame);
        laserDispla_title->setObjectName(QStringLiteral("laserDispla_title"));
        laserDispla_title->setMinimumSize(QSize(150, 32));
        laserDispla_title->setMaximumSize(QSize(400, 16777215));
        laserDispla_title->setFont(font);
        laserDispla_title->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        laserDispla_title->setInputMethodHints(Qt::ImhNoEditMenu);
        laserDispla_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_37->addWidget(laserDispla_title, 0, Qt::AlignHCenter);


        verticalLayout_4->addWidget(laserDisplaTitle_frame);

        LaserDisplayStatus_layout = new QHBoxLayout();
        LaserDisplayStatus_layout->setSpacing(0);
        LaserDisplayStatus_layout->setObjectName(QStringLiteral("LaserDisplayStatus_layout"));
        LaserDisplayStatus_indicator = new QPushButton(LaserDisplayInfo_frame);
        LaserDisplayStatus_indicator->setObjectName(QStringLiteral("LaserDisplayStatus_indicator"));
        LaserDisplayStatus_indicator->setMaximumSize(QSize(20, 16777215));
        LaserDisplayStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        LaserDisplayStatus_indicator->setIcon(icon);
        LaserDisplayStatus_indicator->setFlat(true);

        LaserDisplayStatus_layout->addWidget(LaserDisplayStatus_indicator);

        LaserDisplayStatus_title = new QLabel(LaserDisplayInfo_frame);
        LaserDisplayStatus_title->setObjectName(QStringLiteral("LaserDisplayStatus_title"));
        LaserDisplayStatus_title->setMinimumSize(QSize(0, 24));
        LaserDisplayStatus_title->setMaximumSize(QSize(64, 24));
        LaserDisplayStatus_title->setFont(font6);
        LaserDisplayStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LaserDisplayStatus_layout->addWidget(LaserDisplayStatus_title);

        LaserDisplayStatus_field = new QLabel(LaserDisplayInfo_frame);
        LaserDisplayStatus_field->setObjectName(QStringLiteral("LaserDisplayStatus_field"));
        LaserDisplayStatus_field->setMinimumSize(QSize(0, 24));
        LaserDisplayStatus_field->setMaximumSize(QSize(16777215, 24));
        QFont font11;
        font11.setBold(false);
        font11.setItalic(true);
        font11.setWeight(50);
        LaserDisplayStatus_field->setFont(font11);
        LaserDisplayStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LaserDisplayStatus_layout->addWidget(LaserDisplayStatus_field);


        verticalLayout_4->addLayout(LaserDisplayStatus_layout);

        LaserDisplayPower_layout = new QHBoxLayout();
        LaserDisplayPower_layout->setSpacing(6);
        LaserDisplayPower_layout->setObjectName(QStringLiteral("LaserDisplayPower_layout"));
        LaserDisplayPower_title = new QLabel(LaserDisplayInfo_frame);
        LaserDisplayPower_title->setObjectName(QStringLiteral("LaserDisplayPower_title"));
        LaserDisplayPower_title->setMinimumSize(QSize(0, 24));
        LaserDisplayPower_title->setMaximumSize(QSize(16777215, 24));
        QFont font12;
        font12.setPointSize(13);
        LaserDisplayPower_title->setFont(font12);
        LaserDisplayPower_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        LaserDisplayPower_layout->addWidget(LaserDisplayPower_title);

        LaserDisplayPower_field = new QTextEdit(LaserDisplayInfo_frame);
        LaserDisplayPower_field->setObjectName(QStringLiteral("LaserDisplayPower_field"));
        LaserDisplayPower_field->setMinimumSize(QSize(0, 20));
        LaserDisplayPower_field->setMaximumSize(QSize(128, 24));
        LaserDisplayPower_field->setStyleSheet(QStringLiteral("color: rgba(212,215,217,200)"));

        LaserDisplayPower_layout->addWidget(LaserDisplayPower_field);

        LaserDisplayPower_units = new QLabel(LaserDisplayInfo_frame);
        LaserDisplayPower_units->setObjectName(QStringLiteral("LaserDisplayPower_units"));
        LaserDisplayPower_units->setMinimumSize(QSize(40, 24));
        LaserDisplayPower_units->setMaximumSize(QSize(16777215, 24));
        LaserDisplayPower_units->setFont(font8);
        LaserDisplayPower_units->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        LaserDisplayPower_units->setAlignment(Qt::AlignCenter);

        LaserDisplayPower_layout->addWidget(LaserDisplayPower_units);


        verticalLayout_4->addLayout(LaserDisplayPower_layout);

        Laser_options_box = new QComboBox(LaserDisplayInfo_frame);
        Laser_options_box->addItem(QString());
        Laser_options_box->setObjectName(QStringLiteral("Laser_options_box"));
        Laser_options_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        verticalLayout_4->addWidget(Laser_options_box);


        horizontalLayout_24->addWidget(LaserDisplayInfo_frame);

        LaserDisplayField_frame = new QFrame(laserDisplay_frame);
        LaserDisplayField_frame->setObjectName(QStringLiteral("LaserDisplayField_frame"));
        LaserDisplayField_frame->setMinimumSize(QSize(280, 0));
        LaserDisplayField_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        LaserDisplayField_frame->setFrameShape(QFrame::StyledPanel);
        LaserDisplayField_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(LaserDisplayField_frame);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(6, 6, 6, 6);
        laserDisplay_EnableState_field = new QLabel(LaserDisplayField_frame);
        laserDisplay_EnableState_field->setObjectName(QStringLiteral("laserDisplay_EnableState_field"));
        laserDisplay_EnableState_field->setMaximumSize(QSize(300, 16777215));
        QFont font13;
        font13.setFamily(QStringLiteral(".SF NS Display Condensed"));
        font13.setPointSize(48);
        font13.setBold(true);
        font13.setItalic(true);
        font13.setWeight(75);
        laserDisplay_EnableState_field->setFont(font13);
        laserDisplay_EnableState_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        laserDisplay_EnableState_field->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(laserDisplay_EnableState_field);


        horizontalLayout_24->addWidget(LaserDisplayField_frame);


        DeviceDisplay_Layout->addWidget(laserDisplay_frame);

        galvoDisplay_frame = new QFrame(dashboardPage);
        galvoDisplay_frame->setObjectName(QStringLiteral("galvoDisplay_frame"));
        galvoDisplay_frame->setMinimumSize(QSize(0, 135));
        galvoDisplay_frame->setMaximumSize(QSize(530, 150));
        galvoDisplay_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,24);\n"
""));
        galvoDisplay_frame->setFrameShape(QFrame::StyledPanel);
        galvoDisplay_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_22 = new QHBoxLayout(galvoDisplay_frame);
        horizontalLayout_22->setSpacing(4);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(6, 6, 6, 6);
        galvoDisplayInfo_frame = new QFrame(galvoDisplay_frame);
        galvoDisplayInfo_frame->setObjectName(QStringLiteral("galvoDisplayInfo_frame"));
        galvoDisplayInfo_frame->setMinimumSize(QSize(225, 0));
        galvoDisplayInfo_frame->setMaximumSize(QSize(300, 16777215));
        galvoDisplayInfo_frame->setFrameShape(QFrame::StyledPanel);
        galvoDisplayInfo_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_29 = new QVBoxLayout(galvoDisplayInfo_frame);
        verticalLayout_29->setSpacing(4);
        verticalLayout_29->setContentsMargins(11, 11, 11, 11);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        verticalLayout_29->setContentsMargins(4, 4, 4, 4);
        galvoDisplayTitle_frame = new QFrame(galvoDisplayInfo_frame);
        galvoDisplayTitle_frame->setObjectName(QStringLiteral("galvoDisplayTitle_frame"));
        galvoDisplayTitle_frame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        galvoDisplayTitle_frame->setFrameShape(QFrame::StyledPanel);
        galvoDisplayTitle_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_23 = new QHBoxLayout(galvoDisplayTitle_frame);
        horizontalLayout_23->setSpacing(4);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(4, 4, 4, 4);
        galvoDisplayEnable_button = new QPushButton(galvoDisplayTitle_frame);
        galvoDisplayEnable_button->setObjectName(QStringLiteral("galvoDisplayEnable_button"));
        sizePolicy.setHeightForWidth(galvoDisplayEnable_button->sizePolicy().hasHeightForWidth());
        galvoDisplayEnable_button->setSizePolicy(sizePolicy);
        galvoDisplayEnable_button->setMinimumSize(QSize(28, 32));
        galvoDisplayEnable_button->setBaseSize(QSize(32, 32));
        galvoDisplayEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        galvoDisplayEnable_button->setIcon(icon14);
        galvoDisplayEnable_button->setIconSize(QSize(34, 22));
        galvoDisplayEnable_button->setCheckable(true);
        galvoDisplayEnable_button->setFlat(true);

        horizontalLayout_23->addWidget(galvoDisplayEnable_button, 0, Qt::AlignLeft);

        galvoDisplay_title = new QLabel(galvoDisplayTitle_frame);
        galvoDisplay_title->setObjectName(QStringLiteral("galvoDisplay_title"));
        galvoDisplay_title->setMinimumSize(QSize(150, 32));
        galvoDisplay_title->setMaximumSize(QSize(400, 16777215));
        galvoDisplay_title->setFont(font);
        galvoDisplay_title->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        galvoDisplay_title->setInputMethodHints(Qt::ImhNoEditMenu);
        galvoDisplay_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_23->addWidget(galvoDisplay_title, 0, Qt::AlignHCenter);


        verticalLayout_29->addWidget(galvoDisplayTitle_frame);

        galvoStatus_layout = new QHBoxLayout();
        galvoStatus_layout->setSpacing(0);
        galvoStatus_layout->setObjectName(QStringLiteral("galvoStatus_layout"));
        galvoDisplayStatus_indicator = new QPushButton(galvoDisplayInfo_frame);
        galvoDisplayStatus_indicator->setObjectName(QStringLiteral("galvoDisplayStatus_indicator"));
        galvoDisplayStatus_indicator->setMaximumSize(QSize(20, 16777215));
        galvoDisplayStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        galvoDisplayStatus_indicator->setIcon(icon);
        galvoDisplayStatus_indicator->setFlat(true);

        galvoStatus_layout->addWidget(galvoDisplayStatus_indicator);

        galvoStatus_title = new QLabel(galvoDisplayInfo_frame);
        galvoStatus_title->setObjectName(QStringLiteral("galvoStatus_title"));
        galvoStatus_title->setMinimumSize(QSize(0, 24));
        galvoStatus_title->setMaximumSize(QSize(64, 24));
        galvoStatus_title->setFont(font6);
        galvoStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        galvoStatus_layout->addWidget(galvoStatus_title);

        galvoStatus_field = new QLabel(galvoDisplayInfo_frame);
        galvoStatus_field->setObjectName(QStringLiteral("galvoStatus_field"));
        galvoStatus_field->setMinimumSize(QSize(0, 24));
        galvoStatus_field->setMaximumSize(QSize(16777215, 24));
        galvoStatus_field->setFont(font11);
        galvoStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        galvoStatus_layout->addWidget(galvoStatus_field);


        verticalLayout_29->addLayout(galvoStatus_layout);

        galvoSpeed_layout = new QHBoxLayout();
        galvoSpeed_layout->setSpacing(6);
        galvoSpeed_layout->setObjectName(QStringLiteral("galvoSpeed_layout"));
        galvoSpeed_title = new QLabel(galvoDisplayInfo_frame);
        galvoSpeed_title->setObjectName(QStringLiteral("galvoSpeed_title"));
        galvoSpeed_title->setMinimumSize(QSize(0, 24));
        galvoSpeed_title->setMaximumSize(QSize(16777215, 24));
        galvoSpeed_title->setFont(font12);
        galvoSpeed_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        galvoSpeed_layout->addWidget(galvoSpeed_title);

        galvoSpeed_field = new QTextEdit(galvoDisplayInfo_frame);
        galvoSpeed_field->setObjectName(QStringLiteral("galvoSpeed_field"));
        galvoSpeed_field->setMinimumSize(QSize(0, 20));
        galvoSpeed_field->setMaximumSize(QSize(128, 24));
        galvoSpeed_field->setStyleSheet(QStringLiteral("color: rgba(212,215,217,200)"));

        galvoSpeed_layout->addWidget(galvoSpeed_field);

        galvoSpeed_units = new QLabel(galvoDisplayInfo_frame);
        galvoSpeed_units->setObjectName(QStringLiteral("galvoSpeed_units"));
        galvoSpeed_units->setMinimumSize(QSize(40, 24));
        galvoSpeed_units->setMaximumSize(QSize(16777215, 24));
        galvoSpeed_units->setFont(font8);
        galvoSpeed_units->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        galvoSpeed_units->setAlignment(Qt::AlignCenter);

        galvoSpeed_layout->addWidget(galvoSpeed_units);


        verticalLayout_29->addLayout(galvoSpeed_layout);

        galvoOptions_box = new QComboBox(galvoDisplayInfo_frame);
        galvoOptions_box->addItem(QString());
        galvoOptions_box->setObjectName(QStringLiteral("galvoOptions_box"));
        galvoOptions_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        verticalLayout_29->addWidget(galvoOptions_box);


        horizontalLayout_22->addWidget(galvoDisplayInfo_frame);

        GalvoDisplayField_vertLayout = new QVBoxLayout();
        GalvoDisplayField_vertLayout->setSpacing(4);
        GalvoDisplayField_vertLayout->setObjectName(QStringLiteral("GalvoDisplayField_vertLayout"));
        xDisplayField_frame = new QFrame(galvoDisplay_frame);
        xDisplayField_frame->setObjectName(QStringLiteral("xDisplayField_frame"));
        xDisplayField_frame->setMinimumSize(QSize(280, 0));
        xDisplayField_frame->setMaximumSize(QSize(500, 16777215));
        xDisplayField_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        xDisplayField_frame->setFrameShape(QFrame::StyledPanel);
        xDisplayField_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_29 = new QHBoxLayout(xDisplayField_frame);
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        horizontalLayout_29->setContentsMargins(6, 6, 6, 6);
        xPosition_title = new QLabel(xDisplayField_frame);
        xPosition_title->setObjectName(QStringLiteral("xPosition_title"));
        xPosition_title->setMaximumSize(QSize(66, 16777215));
        QFont font14;
        font14.setFamily(QStringLiteral(".SF NS Display Condensed"));
        font14.setPointSize(52);
        font14.setBold(true);
        font14.setItalic(false);
        font14.setWeight(75);
        xPosition_title->setFont(font14);
        xPosition_title->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(141,158,198,180)"));
        xPosition_title->setAlignment(Qt::AlignCenter);
        xPosition_title->setMargin(-1);

        horizontalLayout_29->addWidget(xPosition_title);

        xPositionDisplay_field = new QLabel(xDisplayField_frame);
        xPositionDisplay_field->setObjectName(QStringLiteral("xPositionDisplay_field"));
        xPositionDisplay_field->setFont(font13);
        xPositionDisplay_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        xPositionDisplay_field->setAlignment(Qt::AlignCenter);

        horizontalLayout_29->addWidget(xPositionDisplay_field);


        GalvoDisplayField_vertLayout->addWidget(xDisplayField_frame);

        yDisplayField_frame = new QFrame(galvoDisplay_frame);
        yDisplayField_frame->setObjectName(QStringLiteral("yDisplayField_frame"));
        yDisplayField_frame->setMinimumSize(QSize(280, 0));
        yDisplayField_frame->setMaximumSize(QSize(500, 16777215));
        yDisplayField_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        yDisplayField_frame->setFrameShape(QFrame::StyledPanel);
        yDisplayField_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_30 = new QHBoxLayout(yDisplayField_frame);
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        horizontalLayout_30->setContentsMargins(6, 6, 6, 6);
        yPosition_title = new QLabel(yDisplayField_frame);
        yPosition_title->setObjectName(QStringLiteral("yPosition_title"));
        yPosition_title->setMaximumSize(QSize(66, 16777215));
        yPosition_title->setFont(font14);
        yPosition_title->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(141,158,198,180)"));
        yPosition_title->setAlignment(Qt::AlignCenter);
        yPosition_title->setMargin(-1);

        horizontalLayout_30->addWidget(yPosition_title);

        yPositionDisplay_field = new QLabel(yDisplayField_frame);
        yPositionDisplay_field->setObjectName(QStringLiteral("yPositionDisplay_field"));
        yPositionDisplay_field->setFont(font13);
        yPositionDisplay_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        yPositionDisplay_field->setAlignment(Qt::AlignCenter);

        horizontalLayout_30->addWidget(yPositionDisplay_field);


        GalvoDisplayField_vertLayout->addWidget(yDisplayField_frame);


        horizontalLayout_22->addLayout(GalvoDisplayField_vertLayout);


        DeviceDisplay_Layout->addWidget(galvoDisplay_frame);

        buildPlateDisplay_frame = new QFrame(dashboardPage);
        buildPlateDisplay_frame->setObjectName(QStringLiteral("buildPlateDisplay_frame"));
        buildPlateDisplay_frame->setMinimumSize(QSize(0, 110));
        buildPlateDisplay_frame->setMaximumSize(QSize(530, 125));
        buildPlateDisplay_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,24);\n"
""));
        buildPlateDisplay_frame->setFrameShape(QFrame::StyledPanel);
        buildPlateDisplay_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_20 = new QHBoxLayout(buildPlateDisplay_frame);
        horizontalLayout_20->setSpacing(4);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(6, 6, 6, 6);
        buildPlateDisplayInfo_Frame = new QFrame(buildPlateDisplay_frame);
        buildPlateDisplayInfo_Frame->setObjectName(QStringLiteral("buildPlateDisplayInfo_Frame"));
        buildPlateDisplayInfo_Frame->setMinimumSize(QSize(225, 0));
        buildPlateDisplayInfo_Frame->setMaximumSize(QSize(300, 16777215));
        buildPlateDisplayInfo_Frame->setFrameShape(QFrame::StyledPanel);
        buildPlateDisplayInfo_Frame->setFrameShadow(QFrame::Raised);
        verticalLayout_25 = new QVBoxLayout(buildPlateDisplayInfo_Frame);
        verticalLayout_25->setSpacing(4);
        verticalLayout_25->setContentsMargins(11, 11, 11, 11);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_25->setContentsMargins(4, 4, 4, 4);
        buildPlateTitle_frame = new QFrame(buildPlateDisplayInfo_Frame);
        buildPlateTitle_frame->setObjectName(QStringLiteral("buildPlateTitle_frame"));
        buildPlateTitle_frame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        buildPlateTitle_frame->setFrameShape(QFrame::StyledPanel);
        buildPlateTitle_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_21 = new QHBoxLayout(buildPlateTitle_frame);
        horizontalLayout_21->setSpacing(4);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(4, 4, 4, 4);
        buildPlateEnable_button = new QPushButton(buildPlateTitle_frame);
        buildPlateEnable_button->setObjectName(QStringLiteral("buildPlateEnable_button"));
        sizePolicy.setHeightForWidth(buildPlateEnable_button->sizePolicy().hasHeightForWidth());
        buildPlateEnable_button->setSizePolicy(sizePolicy);
        buildPlateEnable_button->setMinimumSize(QSize(28, 32));
        buildPlateEnable_button->setBaseSize(QSize(32, 32));
        buildPlateEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        buildPlateEnable_button->setIcon(icon14);
        buildPlateEnable_button->setIconSize(QSize(34, 22));
        buildPlateEnable_button->setCheckable(true);
        buildPlateEnable_button->setFlat(true);

        horizontalLayout_21->addWidget(buildPlateEnable_button, 0, Qt::AlignLeft);

        buildPlate_title = new QLabel(buildPlateTitle_frame);
        buildPlate_title->setObjectName(QStringLiteral("buildPlate_title"));
        buildPlate_title->setMinimumSize(QSize(150, 32));
        buildPlate_title->setMaximumSize(QSize(16777215, 16777215));
        buildPlate_title->setFont(font);
        buildPlate_title->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        buildPlate_title->setInputMethodHints(Qt::ImhNoEditMenu);
        buildPlate_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_21->addWidget(buildPlate_title, 0, Qt::AlignHCenter);


        verticalLayout_25->addWidget(buildPlateTitle_frame);

        buildPlateDisplayStatus_layout = new QHBoxLayout();
        buildPlateDisplayStatus_layout->setSpacing(0);
        buildPlateDisplayStatus_layout->setObjectName(QStringLiteral("buildPlateDisplayStatus_layout"));
        buildPlateDisplayStatus_indicator = new QPushButton(buildPlateDisplayInfo_Frame);
        buildPlateDisplayStatus_indicator->setObjectName(QStringLiteral("buildPlateDisplayStatus_indicator"));
        buildPlateDisplayStatus_indicator->setMaximumSize(QSize(20, 16777215));
        buildPlateDisplayStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        buildPlateDisplayStatus_indicator->setIcon(icon);
        buildPlateDisplayStatus_indicator->setFlat(true);

        buildPlateDisplayStatus_layout->addWidget(buildPlateDisplayStatus_indicator);

        buildPlateDisplayStatus_title = new QLabel(buildPlateDisplayInfo_Frame);
        buildPlateDisplayStatus_title->setObjectName(QStringLiteral("buildPlateDisplayStatus_title"));
        buildPlateDisplayStatus_title->setMinimumSize(QSize(0, 24));
        buildPlateDisplayStatus_title->setMaximumSize(QSize(64, 24));
        buildPlateDisplayStatus_title->setFont(font6);
        buildPlateDisplayStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        buildPlateDisplayStatus_layout->addWidget(buildPlateDisplayStatus_title);

        buildPlateDisplayStatus_field = new QLabel(buildPlateDisplayInfo_Frame);
        buildPlateDisplayStatus_field->setObjectName(QStringLiteral("buildPlateDisplayStatus_field"));
        buildPlateDisplayStatus_field->setMinimumSize(QSize(0, 24));
        buildPlateDisplayStatus_field->setMaximumSize(QSize(16777215, 24));
        buildPlateDisplayStatus_field->setFont(font11);
        buildPlateDisplayStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        buildPlateDisplayStatus_layout->addWidget(buildPlateDisplayStatus_field);


        verticalLayout_25->addLayout(buildPlateDisplayStatus_layout);

        buildPlate_options_box = new QComboBox(buildPlateDisplayInfo_Frame);
        buildPlate_options_box->addItem(QString());
        buildPlate_options_box->setObjectName(QStringLiteral("buildPlate_options_box"));
        buildPlate_options_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        verticalLayout_25->addWidget(buildPlate_options_box);


        horizontalLayout_20->addWidget(buildPlateDisplayInfo_Frame);

        BuildPlateDisplayField_frame = new QFrame(buildPlateDisplay_frame);
        BuildPlateDisplayField_frame->setObjectName(QStringLiteral("BuildPlateDisplayField_frame"));
        BuildPlateDisplayField_frame->setMinimumSize(QSize(280, 0));
        BuildPlateDisplayField_frame->setMaximumSize(QSize(500, 16777215));
        BuildPlateDisplayField_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        BuildPlateDisplayField_frame->setFrameShape(QFrame::StyledPanel);
        BuildPlateDisplayField_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_27 = new QHBoxLayout(BuildPlateDisplayField_frame);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(6, 6, 6, 6);
        buildPlateDisplayField_title = new QLabel(BuildPlateDisplayField_frame);
        buildPlateDisplayField_title->setObjectName(QStringLiteral("buildPlateDisplayField_title"));
        buildPlateDisplayField_title->setMaximumSize(QSize(66, 16777215));
        buildPlateDisplayField_title->setFont(font14);
        buildPlateDisplayField_title->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(141,158,198,180)"));
        buildPlateDisplayField_title->setAlignment(Qt::AlignCenter);
        buildPlateDisplayField_title->setMargin(-1);

        horizontalLayout_27->addWidget(buildPlateDisplayField_title);

        zPositionDisplay_field = new QLabel(BuildPlateDisplayField_frame);
        zPositionDisplay_field->setObjectName(QStringLiteral("zPositionDisplay_field"));
        zPositionDisplay_field->setFont(font13);
        zPositionDisplay_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        zPositionDisplay_field->setAlignment(Qt::AlignCenter);

        horizontalLayout_27->addWidget(zPositionDisplay_field);


        horizontalLayout_20->addWidget(BuildPlateDisplayField_frame);


        DeviceDisplay_Layout->addWidget(buildPlateDisplay_frame);

        materialDeliveryDisplay_frame = new QFrame(dashboardPage);
        materialDeliveryDisplay_frame->setObjectName(QStringLiteral("materialDeliveryDisplay_frame"));
        materialDeliveryDisplay_frame->setMinimumSize(QSize(0, 150));
        materialDeliveryDisplay_frame->setMaximumSize(QSize(530, 16777215));
        materialDeliveryDisplay_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,24);\n"
""));
        materialDeliveryDisplay_frame->setFrameShape(QFrame::StyledPanel);
        materialDeliveryDisplay_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(materialDeliveryDisplay_frame);
        horizontalLayout_19->setSpacing(4);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(6, 6, 6, 6);
        materialDeliveryDisplayInfo_frame = new QFrame(materialDeliveryDisplay_frame);
        materialDeliveryDisplayInfo_frame->setObjectName(QStringLiteral("materialDeliveryDisplayInfo_frame"));
        materialDeliveryDisplayInfo_frame->setMinimumSize(QSize(225, 0));
        materialDeliveryDisplayInfo_frame->setMaximumSize(QSize(300, 16777215));
        materialDeliveryDisplayInfo_frame->setFrameShape(QFrame::StyledPanel);
        materialDeliveryDisplayInfo_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_27 = new QVBoxLayout(materialDeliveryDisplayInfo_frame);
        verticalLayout_27->setSpacing(4);
        verticalLayout_27->setContentsMargins(11, 11, 11, 11);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        verticalLayout_27->setContentsMargins(4, 4, 4, 4);
        materialDeliveryDisplayTitle_frame = new QFrame(materialDeliveryDisplayInfo_frame);
        materialDeliveryDisplayTitle_frame->setObjectName(QStringLiteral("materialDeliveryDisplayTitle_frame"));
        materialDeliveryDisplayTitle_frame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        materialDeliveryDisplayTitle_frame->setFrameShape(QFrame::StyledPanel);
        materialDeliveryDisplayTitle_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_18 = new QHBoxLayout(materialDeliveryDisplayTitle_frame);
        horizontalLayout_18->setSpacing(4);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(4, 4, 4, 4);
        materialDeliveryDisplayEnable_button = new QPushButton(materialDeliveryDisplayTitle_frame);
        materialDeliveryDisplayEnable_button->setObjectName(QStringLiteral("materialDeliveryDisplayEnable_button"));
        sizePolicy.setHeightForWidth(materialDeliveryDisplayEnable_button->sizePolicy().hasHeightForWidth());
        materialDeliveryDisplayEnable_button->setSizePolicy(sizePolicy);
        materialDeliveryDisplayEnable_button->setMinimumSize(QSize(28, 32));
        materialDeliveryDisplayEnable_button->setBaseSize(QSize(32, 32));
        materialDeliveryDisplayEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        materialDeliveryDisplayEnable_button->setIcon(icon14);
        materialDeliveryDisplayEnable_button->setIconSize(QSize(34, 22));
        materialDeliveryDisplayEnable_button->setCheckable(true);
        materialDeliveryDisplayEnable_button->setFlat(true);

        horizontalLayout_18->addWidget(materialDeliveryDisplayEnable_button, 0, Qt::AlignLeft);

        materialDeliveryDisplay_title = new QLabel(materialDeliveryDisplayTitle_frame);
        materialDeliveryDisplay_title->setObjectName(QStringLiteral("materialDeliveryDisplay_title"));
        materialDeliveryDisplay_title->setMinimumSize(QSize(150, 32));
        materialDeliveryDisplay_title->setMaximumSize(QSize(400, 16777215));
        materialDeliveryDisplay_title->setFont(font);
        materialDeliveryDisplay_title->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        materialDeliveryDisplay_title->setInputMethodHints(Qt::ImhNoEditMenu);
        materialDeliveryDisplay_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(materialDeliveryDisplay_title, 0, Qt::AlignHCenter);


        verticalLayout_27->addWidget(materialDeliveryDisplayTitle_frame);

        materialDeliveryDisplayStatus_layout = new QHBoxLayout();
        materialDeliveryDisplayStatus_layout->setSpacing(0);
        materialDeliveryDisplayStatus_layout->setObjectName(QStringLiteral("materialDeliveryDisplayStatus_layout"));
        materialDeliveryDisplayStatus_indicator = new QPushButton(materialDeliveryDisplayInfo_frame);
        materialDeliveryDisplayStatus_indicator->setObjectName(QStringLiteral("materialDeliveryDisplayStatus_indicator"));
        materialDeliveryDisplayStatus_indicator->setMaximumSize(QSize(20, 16777215));
        materialDeliveryDisplayStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        materialDeliveryDisplayStatus_indicator->setIcon(icon);
        materialDeliveryDisplayStatus_indicator->setFlat(true);

        materialDeliveryDisplayStatus_layout->addWidget(materialDeliveryDisplayStatus_indicator);

        materialDeliveryDisplayStatus_title = new QLabel(materialDeliveryDisplayInfo_frame);
        materialDeliveryDisplayStatus_title->setObjectName(QStringLiteral("materialDeliveryDisplayStatus_title"));
        materialDeliveryDisplayStatus_title->setMinimumSize(QSize(0, 24));
        materialDeliveryDisplayStatus_title->setMaximumSize(QSize(64, 24));
        materialDeliveryDisplayStatus_title->setFont(font6);
        materialDeliveryDisplayStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        materialDeliveryDisplayStatus_layout->addWidget(materialDeliveryDisplayStatus_title);

        materialDeliveryDisplayStatus_field = new QLabel(materialDeliveryDisplayInfo_frame);
        materialDeliveryDisplayStatus_field->setObjectName(QStringLiteral("materialDeliveryDisplayStatus_field"));
        materialDeliveryDisplayStatus_field->setMinimumSize(QSize(0, 24));
        materialDeliveryDisplayStatus_field->setMaximumSize(QSize(16777215, 24));
        materialDeliveryDisplayStatus_field->setFont(font11);
        materialDeliveryDisplayStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        materialDeliveryDisplayStatus_layout->addWidget(materialDeliveryDisplayStatus_field);


        verticalLayout_27->addLayout(materialDeliveryDisplayStatus_layout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_27->addItem(verticalSpacer_4);

        materialDelivery_options_box = new QComboBox(materialDeliveryDisplayInfo_frame);
        materialDelivery_options_box->addItem(QString());
        materialDelivery_options_box->setObjectName(QStringLiteral("materialDelivery_options_box"));
        materialDelivery_options_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        verticalLayout_27->addWidget(materialDelivery_options_box);


        horizontalLayout_19->addWidget(materialDeliveryDisplayInfo_frame);

        materialDeliveryDisplayField_frame = new QVBoxLayout();
        materialDeliveryDisplayField_frame->setSpacing(4);
        materialDeliveryDisplayField_frame->setObjectName(QStringLiteral("materialDeliveryDisplayField_frame"));
        HdisplayField_frame = new QFrame(materialDeliveryDisplay_frame);
        HdisplayField_frame->setObjectName(QStringLiteral("HdisplayField_frame"));
        HdisplayField_frame->setMinimumSize(QSize(280, 0));
        HdisplayField_frame->setMaximumSize(QSize(500, 16777215));
        HdisplayField_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        HdisplayField_frame->setFrameShape(QFrame::StyledPanel);
        HdisplayField_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_25 = new QHBoxLayout(HdisplayField_frame);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(6, 6, 6, 6);
        hPositionDisplay_title = new QLabel(HdisplayField_frame);
        hPositionDisplay_title->setObjectName(QStringLiteral("hPositionDisplay_title"));
        hPositionDisplay_title->setMaximumSize(QSize(66, 16777215));
        hPositionDisplay_title->setFont(font14);
        hPositionDisplay_title->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(141,158,198,180)"));
        hPositionDisplay_title->setAlignment(Qt::AlignCenter);
        hPositionDisplay_title->setMargin(-1);

        horizontalLayout_25->addWidget(hPositionDisplay_title);

        hPositionDisplay_field = new QLabel(HdisplayField_frame);
        hPositionDisplay_field->setObjectName(QStringLiteral("hPositionDisplay_field"));
        hPositionDisplay_field->setFont(font13);
        hPositionDisplay_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        hPositionDisplay_field->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(hPositionDisplay_field);


        materialDeliveryDisplayField_frame->addWidget(HdisplayField_frame);

        SdisplayField_frame = new QFrame(materialDeliveryDisplay_frame);
        SdisplayField_frame->setObjectName(QStringLiteral("SdisplayField_frame"));
        SdisplayField_frame->setMinimumSize(QSize(280, 0));
        SdisplayField_frame->setMaximumSize(QSize(500, 16777215));
        SdisplayField_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        SdisplayField_frame->setFrameShape(QFrame::StyledPanel);
        SdisplayField_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_26 = new QHBoxLayout(SdisplayField_frame);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(6, 6, 6, 6);
        sPositionDisplay_title = new QLabel(SdisplayField_frame);
        sPositionDisplay_title->setObjectName(QStringLiteral("sPositionDisplay_title"));
        sPositionDisplay_title->setMaximumSize(QSize(66, 16777215));
        sPositionDisplay_title->setFont(font14);
        sPositionDisplay_title->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(141,158,198,180)"));
        sPositionDisplay_title->setAlignment(Qt::AlignCenter);
        sPositionDisplay_title->setMargin(-1);

        horizontalLayout_26->addWidget(sPositionDisplay_title);

        sPositionDisplay_field = new QLabel(SdisplayField_frame);
        sPositionDisplay_field->setObjectName(QStringLiteral("sPositionDisplay_field"));
        sPositionDisplay_field->setFont(font13);
        sPositionDisplay_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        sPositionDisplay_field->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(sPositionDisplay_field);


        materialDeliveryDisplayField_frame->addWidget(SdisplayField_frame);


        horizontalLayout_19->addLayout(materialDeliveryDisplayField_frame);


        DeviceDisplay_Layout->addWidget(materialDeliveryDisplay_frame);

        enviroDisplay_frame = new QFrame(dashboardPage);
        enviroDisplay_frame->setObjectName(QStringLiteral("enviroDisplay_frame"));
        enviroDisplay_frame->setMinimumSize(QSize(0, 170));
        enviroDisplay_frame->setMaximumSize(QSize(530, 16777215));
        enviroDisplay_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,24);\n"
""));
        enviroDisplay_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplay_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_33 = new QHBoxLayout(enviroDisplay_frame);
        horizontalLayout_33->setSpacing(4);
        horizontalLayout_33->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(6, 6, 6, 6);
        enviroDisplayInfo_frame = new QFrame(enviroDisplay_frame);
        enviroDisplayInfo_frame->setObjectName(QStringLiteral("enviroDisplayInfo_frame"));
        enviroDisplayInfo_frame->setMinimumSize(QSize(225, 0));
        enviroDisplayInfo_frame->setMaximumSize(QSize(300, 16777215));
        enviroDisplayInfo_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayInfo_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_19 = new QVBoxLayout(enviroDisplayInfo_frame);
        verticalLayout_19->setSpacing(4);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(4, 4, 4, 4);
        enviroDisplayTitleFrame = new QFrame(enviroDisplayInfo_frame);
        enviroDisplayTitleFrame->setObjectName(QStringLiteral("enviroDisplayTitleFrame"));
        enviroDisplayTitleFrame->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
""));
        enviroDisplayTitleFrame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayTitleFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_34 = new QHBoxLayout(enviroDisplayTitleFrame);
        horizontalLayout_34->setSpacing(4);
        horizontalLayout_34->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        horizontalLayout_34->setContentsMargins(4, 4, 4, 4);
        enviroDisplayEnable_button = new QPushButton(enviroDisplayTitleFrame);
        enviroDisplayEnable_button->setObjectName(QStringLiteral("enviroDisplayEnable_button"));
        sizePolicy.setHeightForWidth(enviroDisplayEnable_button->sizePolicy().hasHeightForWidth());
        enviroDisplayEnable_button->setSizePolicy(sizePolicy);
        enviroDisplayEnable_button->setMinimumSize(QSize(28, 32));
        enviroDisplayEnable_button->setBaseSize(QSize(32, 32));
        enviroDisplayEnable_button->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,100)"));
        enviroDisplayEnable_button->setIcon(icon14);
        enviroDisplayEnable_button->setIconSize(QSize(34, 22));
        enviroDisplayEnable_button->setCheckable(true);
        enviroDisplayEnable_button->setFlat(true);

        horizontalLayout_34->addWidget(enviroDisplayEnable_button, 0, Qt::AlignLeft);

        enviroDisplay_title = new QLabel(enviroDisplayTitleFrame);
        enviroDisplay_title->setObjectName(QStringLiteral("enviroDisplay_title"));
        enviroDisplay_title->setMinimumSize(QSize(150, 32));
        enviroDisplay_title->setMaximumSize(QSize(400, 16777215));
        enviroDisplay_title->setFont(font);
        enviroDisplay_title->setStyleSheet(QLatin1String("background:none;\n"
"color: rgba(212,215,217,180)"));
        enviroDisplay_title->setInputMethodHints(Qt::ImhNoEditMenu);
        enviroDisplay_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_34->addWidget(enviroDisplay_title, 0, Qt::AlignHCenter);


        verticalLayout_19->addWidget(enviroDisplayTitleFrame);

        enviroDisplayInfo_layout = new QVBoxLayout();
        enviroDisplayInfo_layout->setSpacing(0);
        enviroDisplayInfo_layout->setObjectName(QStringLiteral("enviroDisplayInfo_layout"));
        enviroDisplayStatus_layout = new QHBoxLayout();
        enviroDisplayStatus_layout->setSpacing(0);
        enviroDisplayStatus_layout->setObjectName(QStringLiteral("enviroDisplayStatus_layout"));
        enviroDisplayStatus_indicator = new QPushButton(enviroDisplayInfo_frame);
        enviroDisplayStatus_indicator->setObjectName(QStringLiteral("enviroDisplayStatus_indicator"));
        enviroDisplayStatus_indicator->setMaximumSize(QSize(20, 16777215));
        enviroDisplayStatus_indicator->setStyleSheet(QStringLiteral("background:none;"));
        enviroDisplayStatus_indicator->setIcon(icon);
        enviroDisplayStatus_indicator->setFlat(true);

        enviroDisplayStatus_layout->addWidget(enviroDisplayStatus_indicator);

        enviroDisplayStatus_title = new QLabel(enviroDisplayInfo_frame);
        enviroDisplayStatus_title->setObjectName(QStringLiteral("enviroDisplayStatus_title"));
        enviroDisplayStatus_title->setMinimumSize(QSize(0, 24));
        enviroDisplayStatus_title->setMaximumSize(QSize(64, 24));
        enviroDisplayStatus_title->setFont(font6);
        enviroDisplayStatus_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        enviroDisplayStatus_layout->addWidget(enviroDisplayStatus_title);

        enviroDisplayStatus_field = new QLabel(enviroDisplayInfo_frame);
        enviroDisplayStatus_field->setObjectName(QStringLiteral("enviroDisplayStatus_field"));
        enviroDisplayStatus_field->setMinimumSize(QSize(0, 24));
        enviroDisplayStatus_field->setMaximumSize(QSize(16777215, 24));
        enviroDisplayStatus_field->setFont(font11);
        enviroDisplayStatus_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));

        enviroDisplayStatus_layout->addWidget(enviroDisplayStatus_field);


        enviroDisplayInfo_layout->addLayout(enviroDisplayStatus_layout);

        enviroDisplayDoorState_icon = new QPushButton(enviroDisplayInfo_frame);
        enviroDisplayDoorState_icon->setObjectName(QStringLiteral("enviroDisplayDoorState_icon"));
        enviroDisplayDoorState_icon->setMinimumSize(QSize(0, 33));
        enviroDisplayDoorState_icon->setStyleSheet(QStringLiteral("background:none"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/icons/icons/unlock-alt.png"), QSize(), QIcon::Normal, QIcon::Off);
        enviroDisplayDoorState_icon->setIcon(icon24);
        enviroDisplayDoorState_icon->setIconSize(QSize(27, 50));

        enviroDisplayInfo_layout->addWidget(enviroDisplayDoorState_icon);

        enviroDisplayDoorState_field = new QLabel(enviroDisplayInfo_frame);
        enviroDisplayDoorState_field->setObjectName(QStringLiteral("enviroDisplayDoorState_field"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(enviroDisplayDoorState_field->sizePolicy().hasHeightForWidth());
        enviroDisplayDoorState_field->setSizePolicy(sizePolicy7);
        enviroDisplayDoorState_field->setMinimumSize(QSize(0, 24));
        enviroDisplayDoorState_field->setMaximumSize(QSize(200, 24));
        QFont font15;
        font15.setPointSize(12);
        font15.setBold(true);
        font15.setWeight(75);
        enviroDisplayDoorState_field->setFont(font15);
        enviroDisplayDoorState_field->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(212,215,217,200)"));
        enviroDisplayDoorState_field->setAlignment(Qt::AlignCenter);

        enviroDisplayInfo_layout->addWidget(enviroDisplayDoorState_field, 0, Qt::AlignHCenter);

        enviro_options_box = new QComboBox(enviroDisplayInfo_frame);
        enviro_options_box->addItem(QString());
        enviro_options_box->setObjectName(QStringLiteral("enviro_options_box"));
        enviro_options_box->setStyleSheet(QLatin1String("background:rgba(212,215,217,10);\n"
"color:rgba(212,215,217,200)"));

        enviroDisplayInfo_layout->addWidget(enviro_options_box);


        verticalLayout_19->addLayout(enviroDisplayInfo_layout);


        horizontalLayout_33->addWidget(enviroDisplayInfo_frame);

        enviroDisplayData_frame = new QFrame(enviroDisplay_frame);
        enviroDisplayData_frame->setObjectName(QStringLiteral("enviroDisplayData_frame"));
        enviroDisplayData_frame->setMinimumSize(QSize(280, 0));
        enviroDisplayData_frame->setStyleSheet(QLatin1String("background: rgba(212,215,217,8);\n"
""));
        enviroDisplayData_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayData_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(enviroDisplayData_frame);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        enviroDisplayPressure_frame = new QFrame(enviroDisplayData_frame);
        enviroDisplayPressure_frame->setObjectName(QStringLiteral("enviroDisplayPressure_frame"));
        enviroDisplayPressure_frame->setMinimumSize(QSize(100, 0));
        enviroDisplayPressure_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayPressure_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_22 = new QVBoxLayout(enviroDisplayPressure_frame);
        verticalLayout_22->setSpacing(2);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(4, 4, 4, 4);
        enviroDisplayPressure_title = new QLabel(enviroDisplayPressure_frame);
        enviroDisplayPressure_title->setObjectName(QStringLiteral("enviroDisplayPressure_title"));
        sizePolicy.setHeightForWidth(enviroDisplayPressure_title->sizePolicy().hasHeightForWidth());
        enviroDisplayPressure_title->setSizePolicy(sizePolicy);
        enviroDisplayPressure_title->setMinimumSize(QSize(0, 24));
        enviroDisplayPressure_title->setMaximumSize(QSize(200, 24));
        QFont font16;
        font16.setPointSize(14);
        font16.setBold(true);
        font16.setWeight(75);
        enviroDisplayPressure_title->setFont(font16);
        enviroDisplayPressure_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(141,158,198,180)"));
        enviroDisplayPressure_title->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(enviroDisplayPressure_title);

        enviroDisplayPressure_field = new QLabel(enviroDisplayPressure_frame);
        enviroDisplayPressure_field->setObjectName(QStringLiteral("enviroDisplayPressure_field"));
        QFont font17;
        font17.setPointSize(32);
        font17.setBold(true);
        font17.setItalic(true);
        font17.setWeight(75);
        enviroDisplayPressure_field->setFont(font17);
        enviroDisplayPressure_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        enviroDisplayPressure_field->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(enviroDisplayPressure_field);


        gridLayout_2->addWidget(enviroDisplayPressure_frame, 1, 0, 1, 1);

        enviroDisplayBuildTemperature_frame = new QFrame(enviroDisplayData_frame);
        enviroDisplayBuildTemperature_frame->setObjectName(QStringLiteral("enviroDisplayBuildTemperature_frame"));
        sizePolicy7.setHeightForWidth(enviroDisplayBuildTemperature_frame->sizePolicy().hasHeightForWidth());
        enviroDisplayBuildTemperature_frame->setSizePolicy(sizePolicy7);
        enviroDisplayBuildTemperature_frame->setMinimumSize(QSize(100, 60));
        enviroDisplayBuildTemperature_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayBuildTemperature_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(enviroDisplayBuildTemperature_frame);
        verticalLayout_17->setSpacing(2);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(4, 4, 4, 4);
        enviroDisplayBuildTemperature_title = new QLabel(enviroDisplayBuildTemperature_frame);
        enviroDisplayBuildTemperature_title->setObjectName(QStringLiteral("enviroDisplayBuildTemperature_title"));
        sizePolicy.setHeightForWidth(enviroDisplayBuildTemperature_title->sizePolicy().hasHeightForWidth());
        enviroDisplayBuildTemperature_title->setSizePolicy(sizePolicy);
        enviroDisplayBuildTemperature_title->setMinimumSize(QSize(0, 24));
        enviroDisplayBuildTemperature_title->setMaximumSize(QSize(200, 24));
        enviroDisplayBuildTemperature_title->setFont(font16);
        enviroDisplayBuildTemperature_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(141,158,198,180)"));
        enviroDisplayBuildTemperature_title->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(enviroDisplayBuildTemperature_title);

        enviroDisplayBuildTemperature_field = new QLabel(enviroDisplayBuildTemperature_frame);
        enviroDisplayBuildTemperature_field->setObjectName(QStringLiteral("enviroDisplayBuildTemperature_field"));
        enviroDisplayBuildTemperature_field->setFont(font17);
        enviroDisplayBuildTemperature_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        enviroDisplayBuildTemperature_field->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(enviroDisplayBuildTemperature_field);


        gridLayout_2->addWidget(enviroDisplayBuildTemperature_frame, 0, 0, 1, 1);

        enviroDisplayOxygen_frame = new QFrame(enviroDisplayData_frame);
        enviroDisplayOxygen_frame->setObjectName(QStringLiteral("enviroDisplayOxygen_frame"));
        enviroDisplayOxygen_frame->setMinimumSize(QSize(100, 0));
        enviroDisplayOxygen_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayOxygen_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_21 = new QVBoxLayout(enviroDisplayOxygen_frame);
        verticalLayout_21->setSpacing(2);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(4, 4, 4, 4);
        enviroDisplayOxygen_title = new QLabel(enviroDisplayOxygen_frame);
        enviroDisplayOxygen_title->setObjectName(QStringLiteral("enviroDisplayOxygen_title"));
        sizePolicy7.setHeightForWidth(enviroDisplayOxygen_title->sizePolicy().hasHeightForWidth());
        enviroDisplayOxygen_title->setSizePolicy(sizePolicy7);
        enviroDisplayOxygen_title->setMinimumSize(QSize(0, 24));
        enviroDisplayOxygen_title->setMaximumSize(QSize(200, 24));
        enviroDisplayOxygen_title->setFont(font16);
        enviroDisplayOxygen_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(141,158,198,180)"));
        enviroDisplayOxygen_title->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(enviroDisplayOxygen_title);

        enviroDisplayOxygen_field = new QLabel(enviroDisplayOxygen_frame);
        enviroDisplayOxygen_field->setObjectName(QStringLiteral("enviroDisplayOxygen_field"));
        enviroDisplayOxygen_field->setFont(font17);
        enviroDisplayOxygen_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        enviroDisplayOxygen_field->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(enviroDisplayOxygen_field);


        gridLayout_2->addWidget(enviroDisplayOxygen_frame, 1, 1, 1, 1);

        enviroDisplayTemperature_frame = new QFrame(enviroDisplayData_frame);
        enviroDisplayTemperature_frame->setObjectName(QStringLiteral("enviroDisplayTemperature_frame"));
        sizePolicy7.setHeightForWidth(enviroDisplayTemperature_frame->sizePolicy().hasHeightForWidth());
        enviroDisplayTemperature_frame->setSizePolicy(sizePolicy7);
        enviroDisplayTemperature_frame->setMinimumSize(QSize(100, 60));
        enviroDisplayTemperature_frame->setFrameShape(QFrame::StyledPanel);
        enviroDisplayTemperature_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_18 = new QVBoxLayout(enviroDisplayTemperature_frame);
        verticalLayout_18->setSpacing(2);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(4, 4, 4, 4);
        enviroDisplayTemperature_title = new QLabel(enviroDisplayTemperature_frame);
        enviroDisplayTemperature_title->setObjectName(QStringLiteral("enviroDisplayTemperature_title"));
        sizePolicy7.setHeightForWidth(enviroDisplayTemperature_title->sizePolicy().hasHeightForWidth());
        enviroDisplayTemperature_title->setSizePolicy(sizePolicy7);
        enviroDisplayTemperature_title->setMinimumSize(QSize(0, 24));
        enviroDisplayTemperature_title->setMaximumSize(QSize(200, 24));
        enviroDisplayTemperature_title->setFont(font16);
        enviroDisplayTemperature_title->setStyleSheet(QLatin1String("background: none;\n"
"color: rgba(141,158,198,180)"));
        enviroDisplayTemperature_title->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(enviroDisplayTemperature_title);

        enviroDisplayTemperature_field = new QLabel(enviroDisplayTemperature_frame);
        enviroDisplayTemperature_field->setObjectName(QStringLiteral("enviroDisplayTemperature_field"));
        enviroDisplayTemperature_field->setFont(font17);
        enviroDisplayTemperature_field->setStyleSheet(QLatin1String("background: rgba(212,215,217,16);\n"
"color: rgba(55,255,139, 180)"));
        enviroDisplayTemperature_field->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(enviroDisplayTemperature_field);


        gridLayout_2->addWidget(enviroDisplayTemperature_frame, 0, 1, 1, 1);


        horizontalLayout_33->addWidget(enviroDisplayData_frame, 0, Qt::AlignHCenter);


        DeviceDisplay_Layout->addWidget(enviroDisplay_frame);


        horizontalLayout_7->addLayout(DeviceDisplay_Layout);

        AppPages->addWidget(dashboardPage);
        HelpPage = new QWidget();
        HelpPage->setObjectName(QStringLiteral("HelpPage"));
        AppPages->addWidget(HelpPage);
        Menu_Page_Splitter->addWidget(AppPages);

        horizontalLayout_14->addWidget(Menu_Page_Splitter);


        retranslateUi(PowderApp);

        jogXminus_button->setDefault(false);
        jogYplus_button->setDefault(false);
        jogYminus_button->setDefault(false);
        jogXplus_button->setDefault(false);
        jogZplus_button->setDefault(false);
        jogZminus_button->setDefault(false);
        jogHplus_button->setDefault(false);
        jogHminus_button->setDefault(false);
        jogSminus_button->setDefault(false);
        jogSplus_button->setDefault(false);


        QMetaObject::connectSlotsByName(PowderApp);
    } // setupUi

    void retranslateUi(QWidget *PowderApp)
    {
        PowderApp->setWindowTitle(QApplication::translate("PowderApp", "Widget", nullptr));
        PortManagerDisplay_title->setText(QApplication::translate("PowderApp", "Port Manager", nullptr));
        PortManager_options_box->setItemText(0, QApplication::translate("PowderApp", "Manage Connections", nullptr));
        PortManager_options_box->setItemText(1, QApplication::translate("PowderApp", "Open Laser & Galvanometer Port", nullptr));
        PortManager_options_box->setItemText(2, QApplication::translate("PowderApp", "Open Build Plate & Material Delivery Port", nullptr));

        LaserGalvoPort_title->setText(QApplication::translate("PowderApp", "Laser & Galvanometer", nullptr));
        LaserGalvoPortStatus_indicator->setText(QString());
        LaserGalvoPortStatus_field->setText(QApplication::translate("PowderApp", "Not Assigned", nullptr));
        MaterialDeliveryPort_title->setText(QApplication::translate("PowderApp", "Build Plate & Mat. Deliv.", nullptr));
        MaterialDeliveryPortStatus_indicator->setText(QString());
        MaterialDeliveryPortStatus_field->setText(QApplication::translate("PowderApp", "Not Assigned", nullptr));
        EnvironmentPortStatus_title->setText(QApplication::translate("PowderApp", "Environment Control", nullptr));
        EnvironmentPortStatus_indicator->setText(QString());
        EnvironmentPortStatus_field->setText(QApplication::translate("PowderApp", "Not Assigned", nullptr));
        Main_Button_Home->setText(QString());
        Main_Button_PortPage->setText(QApplication::translate("PowderApp", "  Scan for Serial Ports", nullptr));
        Main_Button_ConfigurationPage->setText(QApplication::translate("PowderApp", "  Configure Devices", nullptr));
        Main_Button_GCodePage->setText(QApplication::translate("PowderApp", "  Process G-Code File", nullptr));
        Main_Button_ControllerPage->setText(QApplication::translate("PowderApp", "  Open System Controller", nullptr));
        Main_Button_HelpPage->setText(QApplication::translate("PowderApp", "  View Documentation", nullptr));
#ifndef QT_NO_TOOLTIP
        settings_button_resetToDefault->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        settings_button_resetToDefault->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        settings_button_resetToDefault->setText(QApplication::translate("PowderApp", " Reset", nullptr));
        settings_button_openFile->setText(QApplication::translate("PowderApp", " Import Configuration", nullptr));
        settings_buttons_saveFile->setText(QApplication::translate("PowderApp", " Export Configuration", nullptr));
        settings_button_apply->setText(QApplication::translate("PowderApp", " Apply", nullptr));
        settings_button_refreshPorts->setText(QApplication::translate("PowderApp", "Rescan Ports", nullptr));
        gcode_tool_button_openFile->setText(QApplication::translate("PowderApp", "Open G-Code File", nullptr));
        printTools_display_commands_button->setText(QApplication::translate("PowderApp", "Display Command Strings", nullptr));
        printTools_displayComments_button->setText(QApplication::translate("PowderApp", "Display Comments", nullptr));
        printTools_ignoreErrors_button->setText(QApplication::translate("PowderApp", "Ignore Errors", nullptr));
        gcode_tool_button_clearPart->setText(QApplication::translate("PowderApp", "Clear Part", nullptr));
        printTools_outputBrowser_title->setText(QApplication::translate("PowderApp", "Original G-Code", nullptr));
        printTools_outputBrowser_title_2->setText(QApplication::translate("PowderApp", "Command Codes", nullptr));
        printTools_outputBrowser_title_3->setText(QApplication::translate("PowderApp", "Errors", nullptr));
        printTools_page_acceptPart_button->setText(QApplication::translate("PowderApp", "Add Part To Job List", nullptr));
        PrintManagerEnable_button->setText(QString());
        label_47->setText(QApplication::translate("PowderApp", "Print Manager", nullptr));
        printManagerStatus_indicator->setText(QString());
        printManagerStatus_title->setText(QApplication::translate("PowderApp", "  Status:", nullptr));
        printManager_status_field->setText(QString());
        activeFile_titleLabel->setText(QApplication::translate("PowderApp", "Active File:", nullptr));
        printManager_file_field->setText(QString());
        printManager_options_box->setItemText(0, QApplication::translate("PowderApp", "Options", nullptr));

        printManager_stop_button->setText(QString());
        printManager_pause_button->setText(QString());
        printManager_stepThrough_button->setText(QString());
        printManager_start_button->setText(QString());
        blockTitle_label->setText(QApplication::translate("PowderApp", "Block", nullptr));
        currentBlock_field->setText(QApplication::translate("PowderApp", "0", nullptr));
        blockOf_label->setText(QApplication::translate("PowderApp", "of", nullptr));
        totalBlocks_field->setText(QApplication::translate("PowderApp", "0", nullptr));
        layerTitle_label->setText(QApplication::translate("PowderApp", "Layer", nullptr));
        currentLayer_field->setText(QApplication::translate("PowderApp", "0", nullptr));
        layerOf_label->setText(QApplication::translate("PowderApp", "of", nullptr));
        totalLayers_field->setText(QApplication::translate("PowderApp", "0", nullptr));
        ManualControlEnable_button->setText(QString());
        label_46->setText(QApplication::translate("PowderApp", "Manual Controller", nullptr));
        ManualControlHome_button->setText(QApplication::translate("PowderApp", " Home", nullptr));
        ManualControlHome_options_box->setItemText(0, QApplication::translate("PowderApp", "All Axis", nullptr));
        ManualControlHome_options_box->setItemText(1, QApplication::translate("PowderApp", "X & Y & Z", nullptr));
        ManualControlHome_options_box->setItemText(2, QApplication::translate("PowderApp", "X & Y", nullptr));
        ManualControlHome_options_box->setItemText(3, QApplication::translate("PowderApp", "X", nullptr));
        ManualControlHome_options_box->setItemText(4, QApplication::translate("PowderApp", "Y", nullptr));
        ManualControlHome_options_box->setItemText(5, QApplication::translate("PowderApp", "Z", nullptr));
        ManualControlHome_options_box->setItemText(6, QApplication::translate("PowderApp", "H", nullptr));
        ManualControlHome_options_box->setItemText(7, QApplication::translate("PowderApp", "S", nullptr));

        jogDistance_title->setText(QApplication::translate("PowderApp", "Jog Distance", nullptr));
        jog_units_label->setText(QApplication::translate("PowderApp", "[mm]", nullptr));
        galvo_jog_control_title->setText(QApplication::translate("PowderApp", "Galvanometer", nullptr));
        jogXminus_button->setText(QApplication::translate("PowderApp", "X", nullptr));
        jogYplus_button->setText(QApplication::translate("PowderApp", "  Y", nullptr));
        jogYminus_button->setText(QApplication::translate("PowderApp", "  Y", nullptr));
        jogXplus_button->setText(QApplication::translate("PowderApp", "  X", nullptr));
        build_jog_control_title->setText(QApplication::translate("PowderApp", "Build", nullptr));
        hopper_jog_control_title->setText(QApplication::translate("PowderApp", "Hopper", nullptr));
        spreader_jog_control_title->setText(QApplication::translate("PowderApp", "Spreader", nullptr));
        jogZplus_button->setText(QApplication::translate("PowderApp", "  Z", nullptr));
        jogZminus_button->setText(QApplication::translate("PowderApp", "  Z", nullptr));
        jogHplus_button->setText(QApplication::translate("PowderApp", "  H", nullptr));
        jogHminus_button->setText(QApplication::translate("PowderApp", "  H", nullptr));
        jogSminus_button->setText(QApplication::translate("PowderApp", "S", nullptr));
        jogSplus_button->setText(QApplication::translate("PowderApp", "  S", nullptr));
        laserDisplayEnable_button->setText(QString());
        laserDispla_title->setText(QApplication::translate("PowderApp", "Laser", nullptr));
        LaserDisplayStatus_indicator->setText(QString());
        LaserDisplayStatus_title->setText(QApplication::translate("PowderApp", "  Status:", nullptr));
        LaserDisplayStatus_field->setText(QApplication::translate("PowderApp", " Disabled", nullptr));
        LaserDisplayPower_title->setText(QApplication::translate("PowderApp", "Power:", nullptr));
        LaserDisplayPower_field->setHtml(QApplication::translate("PowderApp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        LaserDisplayPower_units->setText(QApplication::translate("PowderApp", "[W]", nullptr));
        Laser_options_box->setItemText(0, QApplication::translate("PowderApp", "Options", nullptr));

        laserDisplay_EnableState_field->setText(QApplication::translate("PowderApp", "Laser\n"
"Off", nullptr));
        galvoDisplayEnable_button->setText(QString());
        galvoDisplay_title->setText(QApplication::translate("PowderApp", "Galvanometer", nullptr));
        galvoDisplayStatus_indicator->setText(QString());
        galvoStatus_title->setText(QApplication::translate("PowderApp", "  Status:", nullptr));
        galvoStatus_field->setText(QApplication::translate("PowderApp", " Disabled", nullptr));
        galvoSpeed_title->setText(QApplication::translate("PowderApp", "Speed:", nullptr));
        galvoSpeed_field->setHtml(QApplication::translate("PowderApp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        galvoSpeed_units->setText(QApplication::translate("PowderApp", "[mm/s]", nullptr));
        galvoOptions_box->setItemText(0, QApplication::translate("PowderApp", "Options", nullptr));

        xPosition_title->setText(QApplication::translate("PowderApp", "X", nullptr));
        xPositionDisplay_field->setText(QApplication::translate("PowderApp", "000.000", nullptr));
        yPosition_title->setText(QApplication::translate("PowderApp", "Y", nullptr));
        yPositionDisplay_field->setText(QApplication::translate("PowderApp", "000.000", nullptr));
        buildPlateEnable_button->setText(QString());
        buildPlate_title->setText(QApplication::translate("PowderApp", "Build Plate ", nullptr));
        buildPlateDisplayStatus_indicator->setText(QString());
        buildPlateDisplayStatus_title->setText(QApplication::translate("PowderApp", "  Status:", nullptr));
        buildPlateDisplayStatus_field->setText(QApplication::translate("PowderApp", " Disabled", nullptr));
        buildPlate_options_box->setItemText(0, QApplication::translate("PowderApp", "Options", nullptr));

        buildPlateDisplayField_title->setText(QApplication::translate("PowderApp", "Z", nullptr));
        zPositionDisplay_field->setText(QApplication::translate("PowderApp", "000.000", nullptr));
        materialDeliveryDisplayEnable_button->setText(QString());
        materialDeliveryDisplay_title->setText(QApplication::translate("PowderApp", "Material Delivery ", nullptr));
        materialDeliveryDisplayStatus_indicator->setText(QString());
        materialDeliveryDisplayStatus_title->setText(QApplication::translate("PowderApp", "  Status:", nullptr));
        materialDeliveryDisplayStatus_field->setText(QApplication::translate("PowderApp", " Disabled", nullptr));
        materialDelivery_options_box->setItemText(0, QApplication::translate("PowderApp", "Options", nullptr));

        hPositionDisplay_title->setText(QApplication::translate("PowderApp", "H", nullptr));
        hPositionDisplay_field->setText(QApplication::translate("PowderApp", "000.000", nullptr));
        sPositionDisplay_title->setText(QApplication::translate("PowderApp", "S", nullptr));
        sPositionDisplay_field->setText(QApplication::translate("PowderApp", "000.000", nullptr));
        enviroDisplayEnable_button->setText(QString());
        enviroDisplay_title->setText(QApplication::translate("PowderApp", "Environment", nullptr));
        enviroDisplayStatus_indicator->setText(QString());
        enviroDisplayStatus_title->setText(QApplication::translate("PowderApp", "  Status:", nullptr));
        enviroDisplayStatus_field->setText(QApplication::translate("PowderApp", " Disabled", nullptr));
        enviroDisplayDoorState_icon->setText(QString());
        enviroDisplayDoorState_field->setText(QApplication::translate("PowderApp", "Door is Open", nullptr));
        enviro_options_box->setItemText(0, QApplication::translate("PowderApp", "Options", nullptr));

        enviroDisplayPressure_title->setText(QApplication::translate("PowderApp", "Pressure", nullptr));
        enviroDisplayPressure_field->setText(QApplication::translate("PowderApp", "00.0 Pa", nullptr));
        enviroDisplayBuildTemperature_title->setText(QApplication::translate("PowderApp", "Build Plate", nullptr));
        enviroDisplayBuildTemperature_field->setText(QApplication::translate("PowderApp", "00.0\302\260 C", nullptr));
        enviroDisplayOxygen_title->setText(QApplication::translate("PowderApp", "Oxygen", nullptr));
        enviroDisplayOxygen_field->setText(QApplication::translate("PowderApp", "00.0 %", nullptr));
        enviroDisplayTemperature_title->setText(QApplication::translate("PowderApp", "Environment", nullptr));
        enviroDisplayTemperature_field->setText(QApplication::translate("PowderApp", "00.0\302\260 C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PowderApp: public Ui_PowderApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWDERAPP_H
