#include "powderapp.h"
#include "ui_powderapp.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QTreeView>
#include <QIcon>
#include <QList>
#include <QVector3D>

Q_LOGGING_CATEGORY(powder_app, "powder.app")

PowderApp::PowderApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowderApp)
{
    ui->setupUi(this);
    viewDefaultSettings();
    deviceTransport = new PowderDaemon(this);

    this->QWidget::setMaximumWidth(335);
    this->QWidget::setMaximumHeight(700);
    ui->gcode_tool_button_openFile->setDisabled(true);
    QList<int> splitterSizes = {0,325};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->AppPages->setCurrentIndex(0);
    PartInfoLabelModel = new QStandardItemModel;
    QStandardItem * partInfoRoot = PartInfoLabelModel->invisibleRootItem();
    ui->PartInfoView->setModel(PartInfoLabelModel);

    QStandardItem *partInfo_Name = new QStandardItem("File Name:");
    QStandardItem *partInfo_Status = new QStandardItem("Status:");
    QStandardItem *partInfo_Layers = new QStandardItem("Layers:");
    QStandardItem *partInfo_Blocks = new QStandardItem("Blocks:");
    QStandardItem *partInfo_Dimensions = new QStandardItem("Dimensions:");
    partInfoRoot->appendRow(partInfo_Name);
    partInfoRoot->appendRow(partInfo_Status);
    partInfoRoot->appendRow(partInfo_Layers);
    partInfoRoot->appendRow(partInfo_Blocks);
    partInfoRoot->appendRow(partInfo_Dimensions);

    menuModel = new QStandardItemModel;
    QStandardItem * menuRoot = menuModel->invisibleRootItem();
    ui->MenuTree->setModel(menuModel);
    ui->MenuTree->setExpandsOnDoubleClick(true);

    ui->MenuTree->setIconSize(QSize(32,32));
    QStandardItem* HomeMenuRoot = new QStandardItem("P0WD3R");
    HomeMenuRoot->setIcon(QIcon(":/icons/icons/cube.png"));
    menuRoot->appendRow(HomeMenuRoot);

    QStandardItem* HomeMenu_Help = new QStandardItem("Help");
    HomeMenu_Help->setIcon(QIcon(":/icons/icons/Icon-eto-help-circled.png"));
    HomeMenuRoot->appendRow(HomeMenu_Help);

    QStandardItem* ConfigureMenuRoot = new QStandardItem("System Settings");
    ConfigureMenuRoot->setIcon(QIcon(":/icons/icons/Icon-elusive-cogs.png"));
    menuRoot->appendRow(ConfigureMenuRoot);

    QStandardItem* ConfigureMenu_Ports = new QStandardItem("Port List");
    ConfigureMenu_Ports->setIcon(QIcon(":/icons/icons/Icon-eto-flow-cascade.png"));
    ConfigureMenuRoot->appendRow(ConfigureMenu_Ports);

    QStandardItem* ConfigureMenu_Devices = new QStandardItem("Configurator");
    ConfigureMenu_Devices->setIcon(QIcon(":/icons/icons/iosSettingsStrong.png"));
    ConfigureMenuRoot->appendRow(ConfigureMenu_Devices);

    QStandardItem* PrintToolsRoot = new QStandardItem("Preprocessor");
    PrintToolsRoot->setIcon(QIcon(":/icons/icons/buffer.png"));
    menuRoot->appendRow(PrintToolsRoot);

    QStandardItem* ImportGcodeMenu = new QStandardItem("G-Code Converter");
    ImportGcodeMenu->setIcon(QIcon(":/icons/icons/angle-double-right.png"));
    PrintToolsRoot->appendRow(ImportGcodeMenu);

    QStandardItem* HardwareToolsRoot = new QStandardItem("Print Tools");
    HardwareToolsRoot->setIcon(QIcon(":/icons/icons/Icon-eto-tools.png"));
    menuRoot->appendRow(HardwareToolsRoot);


    QStandardItem* HardwareTools_Controller = new QStandardItem("3D View");
    HardwareTools_Controller->setIcon(QIcon(":/icons/icons/iosGlasses.png"));
    HardwareToolsRoot->appendRow(HardwareTools_Controller);

    QStandardItem* HardwareTools_CommandLine = new QStandardItem("Debug");
    HardwareTools_CommandLine->setIcon(QIcon(":/icons/icons/code.png"));
    HardwareToolsRoot->appendRow(HardwareTools_CommandLine);

    m_partFile_open = false;

    myConfiguration = nullptr;
    m_myPart.clear();
    m_block3d = nullptr;

    ui->printManager_frame->setDisabled(true);
    ui->ManualControl_Frame->setDisabled(true);
    ui->laserDisplay_frame->setDisabled(true);
    ui->galvoDisplay_frame->setDisabled(true);
    ui->buildPlateDisplay_frame->setDisabled(true);
    ui->materialDeliveryDisplay_frame->setDisabled(true);
    ui->enviroDisplay_frame->setDisabled(true);
    ui->printManager_block_bar->setValue(0);
    ui->printManager_layer_bar->setValue(0);

    ui->PortManagerDisplay_frame->setVisible(false);

    QObject::connect(this, SIGNAL(lgPort_name_changed(const QString&)),
                     deviceTransport, SLOT(on_lgPortName_changed(const QString&)));

    QObject::connect(this, SIGNAL(lgPort_connectionRequested(bool)),
                     deviceTransport, SLOT(on_lg_port_connectionRequested(bool)));

    QObject::connect(deviceTransport, SIGNAL(lg_port_connectionChanged(bool)),
                     this, SLOT(on_lg_port_connectionChanged(bool)));

    QObject::connect(this, SIGNAL(mdPort_name_changed(const QString&)),
                     deviceTransport, SLOT(on_mdPortName_changed(const QString&)));

    QObject::connect(this, SIGNAL(mdPort_connectionRequested(bool)),
                     deviceTransport, SLOT(on_md_port_connectionRequested(bool)));

    QObject::connect(deviceTransport, SIGNAL(md_port_connectionChanged(bool)),
                     this, SLOT(on_md_port_connectionChanged(bool)));

    QObject::connect(deviceTransport, SIGNAL(printRoutine_error(const QString&)),
                     this, SLOT(on_transportError(const QString&)));

    QObject::connect(deviceTransport, SIGNAL(lg_port_error(const QString&)),
                     this, SLOT(on_lg_portError(const QString&)));

    QObject::connect(deviceTransport, SIGNAL(md_port_error(const QString&)),
                     this, SLOT(on_md_portError(const QString&)));


    QObject::connect(deviceTransport, SIGNAL(lg_port_deviceReply(const QString&)),
                     this, SLOT(on_lg_portReply(const QString&)));

    QObject::connect(deviceTransport, SIGNAL(md_port_deviceReply(const QString&)),
                     this, SLOT(on_md_portReply(const QString&)));

    QObject::connect(deviceTransport, SIGNAL(currentBlockNumber_changed(int)),
                     ui->currentBlock_field, SLOT(setNum(int)));

    QObject::connect(deviceTransport, SIGNAL(currentBlockNumber_changed(int)),
                     ui->printManager_block_bar, SLOT(setValue(int)));

    QObject::connect(deviceTransport, SIGNAL(currentLayerNumber_changed(int)),
                     ui->printManager_layer_bar, SLOT(setValue(int)));

    QObject::connect(deviceTransport, SIGNAL(currentLayerNumber_changed(int)),
                     ui->currentLayer_field, SLOT(setNum(int)));

    QObject::connect(this, SIGNAL(newPartAvailable(QSharedPointer<PartObject>)),
                     deviceTransport, SLOT(on_partFile_available(QSharedPointer<PartObject>)));

    QObject::connect(this, SIGNAL(newConfigAvailable(QSharedPointer<SettingsObject>)),
                     deviceTransport, SLOT(on_config_available(QSharedPointer<SettingsObject>)));

    QObject::connect(ui->PrintManagerEnable_button, SIGNAL(clicked(bool)),
                     deviceTransport, SLOT(on_printManager_enabled(bool)));

    QObject::connect(ui->ManualControlEnable_button, SIGNAL(clicked(bool)),
                     deviceTransport, SLOT(on_manualControl_enabled(bool)));

    QObject::connect(ui->printManager_start_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_startPrint_request()));

    QObject::connect(ui->printManager_stop_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_stopPrint_request()));

    QObject::connect(ui->printManager_reset_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_reset_request()));

    QObject::connect(ui->ManualControlHome_options_box, SIGNAL(currentIndexChanged(int)),
                     deviceTransport, SLOT(on_homeOption_change(int)));

    QObject::connect(ui->ManualControlHome_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_home_request()));

    QObject::connect(ui->printManager_JogDistance_Input, SIGNAL(valueChanged(double)),
                     deviceTransport, SLOT(on_jogIncrement_changed(double)));


    QObject::connect(ui->jogXplus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_increment_xPosition_request()));
    QObject::connect(ui->jogXminus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_decrement_xPosition_request()));

    QObject::connect(ui->jogYplus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_increment_yPosition_request()));
    QObject::connect(ui->jogYminus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_decrement_yPosition_request()));

    QObject::connect(ui->jogZplus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_increment_zPosition_request()));
    QObject::connect(ui->jogZminus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_decrement_zPosition_request()));

    QObject::connect(ui->jogHplus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_increment_hPosition_request()));
    QObject::connect(ui->jogHminus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_decrement_hPosition_request()));


    QObject::connect(ui->jogSplus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_increment_sPosition_request()));
    QObject::connect(ui->jogSminus_button, SIGNAL(pressed()),
                     deviceTransport, SLOT(on_decrement_sPosition_request()));



    QObject::connect(deviceTransport, SIGNAL(laserEnableState_changed(const QString&)),
                     ui->laserDisplay_EnableState_field, SLOT(setText(const QString&)));

    QObject::connect(deviceTransport, SIGNAL(xPosition_changed(double)),
                     ui->xPositionDisplay_field, SLOT(setNum(double)));

    QObject::connect(deviceTransport, SIGNAL(yPosition_changed(double)),
                     ui->yPositionDisplay_field, SLOT(setNum(double)));

    QObject::connect(deviceTransport, SIGNAL(zPosition_changed(double)),
                     ui->zPositionDisplay_field, SLOT(setNum(double)));

    QObject::connect(deviceTransport, SIGNAL(hPosition_changed(double)),
                     ui->hPositionDisplay_field, SLOT(setNum(double)));

    QObject::connect(deviceTransport, SIGNAL(sPosition_changed(double)),
                     ui->sPositionDisplay_field, SLOT(setNum(double)));

    QObject::connect(deviceTransport, SIGNAL(laserPower_changed(int)),
                     ui->LaserDisplayPower_field, SLOT(setNum(int)));

    QObject::connect(deviceTransport, SIGNAL(xySpeed_changed(double)),
                     ui->galvoSpeed_field, SLOT(setNum(double)));

    QObject::connect(deviceTransport, SIGNAL(buildPlateBusy()),
                     this, SLOT(on_buildPlateBusy()));

    QObject::connect(deviceTransport, SIGNAL(galvoBusy()),
                     this, SLOT(on_galvoBusy()));

    QObject::connect(deviceTransport, SIGNAL(hopperBusy()),
                     this, SLOT(on_hop_spread_busy()));

    QObject::connect(deviceTransport, SIGNAL(spreaderBusy()),
                     this, SLOT(on_hop_spread_busy()));

    QObject::connect(this, SIGNAL(cleaDeviceErrors()),
                     deviceTransport, SLOT(on_clearError_request()));

    this->applySettings();
    qCWarning(powder_app, "entered powder app");

}

PowderApp::~PowderApp()
{
    delete ui;
    myConfiguration.clear();
    m_myPart.clear();

    deviceTransport->deleteLater();
    qCWarning(powder_app, "exited powder app");

}

void PowderApp::applySettings()
{
    myConfiguration.clear();

    myConfiguration = QSharedPointer<SettingsObject>(new SettingsObject);

    myConfiguration->setLaser_galvo_portNumber(ui->lg_portnum_field->text().toInt());
    myConfiguration->setMaterialDelivery_portNumber(ui->md_portnum_field->text().toInt());

    myConfiguration->setLaser_deviceNumber(ui->laser_devicenum_field->text().toInt());
    myConfiguration->setLaser_axisNumber(ui->laser_axisnum_field->text().toInt());
    myConfiguration->setLaser_power_resolution(ui->laser_powerres_field->text().toInt());
    myConfiguration->setLaser_power_default(ui->laser_powerdef_field->text().toInt());
    myConfiguration->setLaser_power_max(ui->laser_powermax_field->text().toInt());
    myConfiguration->setLaser_power_min(ui->laser_powermin_field->text().toInt());


    myConfiguration->setGalvo_deviceNumber(ui->galvo_devicenum_field->text().toInt());
    myConfiguration->setXY_speed_default(ui->galvo_speeddef_field->text().toFloat());
    myConfiguration->setXY_speed_max(ui->galvo_speedmax_field->text().toFloat());
    myConfiguration->setXY_speed_min(ui->galvo_speedmin_field->text().toFloat());

    myConfiguration->setX_axisNumber(ui->galvo_x_axisnum_field->text().toInt());
    myConfiguration->setX_position_resolution(ui->galvo_x_steps_field->text().toFloat());
    myConfiguration->setX_position_max(ui->galvo_x_positionmax_field->text().toFloat());
    myConfiguration->setX_position_min(ui->galvo_x_positionmin_field->text().toFloat());

    myConfiguration->setY_axisNumber(ui->galvo_y_axisnum_field->text().toInt());
    myConfiguration->setY_position_resolution(ui->galvo_y_steps_field->text().toFloat());
    myConfiguration->setY_position_max(ui->galvo_y_positionmax_field->text().toFloat());
    myConfiguration->setY_position_min(ui->galvo_y_positionmin_field->text().toFloat());


    myConfiguration->setZ_deviceNumber(ui->buildplate_devicenum_field->text().toInt());
    myConfiguration->setZ_axisNumber(ui->buildplate_axisnum_field->text().toInt());
    myConfiguration->setZ_position_resolution(ui->buildplate_steps_field->text().toFloat());
    myConfiguration->setZ_position_max(ui->buildplate_speedmax_field->text().toFloat());
    myConfiguration->setZ_position_min(ui->buildplate_speedmin_field->text().toFloat());
    myConfiguration->setZ_speed_default(ui->buildplate_speeddef_field->text().toFloat());
    myConfiguration->setZ_speed_max(ui->buildplate_speedmax_field->text().toFloat());
    myConfiguration->setZ_speed_min(ui->buildplate_speedmin_field->text().toFloat());

    myConfiguration->setHopper_deviceNumber(ui->hopper_devicenum_field->text().toInt());
    myConfiguration->setHopper_axisNumber(ui->hopper_axisnum_field->text().toInt());
    myConfiguration->setHopper_position_resolution(ui->hopper_steps_field->text().toFloat());
    myConfiguration->setHopper_position_max(ui->hopper_speedmax_field->text().toFloat());
    myConfiguration->setHopper_position_min(ui->hopper_speedmin_field->text().toFloat());
    myConfiguration->setHopper_speed_default(ui->hopper_speeddef_field->text().toFloat());
    myConfiguration->setHopper_speed_max(ui->hopper_speedmax_field->text().toFloat());
    myConfiguration->setHopper_speed_min(ui->hopper_speedmin_field->text().toFloat());

    myConfiguration->setSpreader_deviceNumber(ui->spreader_devicenum_field->text().toInt());
    myConfiguration->setSpreader_axisNumber(ui->spreader_axisnum_field->text().toInt());
    myConfiguration->setSpreader_position_resolution(ui->spreader_steps_field->text().toFloat());
    myConfiguration->setSpreader_position_max(ui->spreader_speedmax_field->text().toFloat());
    myConfiguration->setSpreader_position_min(ui->spreader_speedmin_field->text().toFloat());
    myConfiguration->setSpreader_speed_default(ui->spreader_speeddef_field->text().toFloat());
    myConfiguration->setSpreader_speed_max(ui->spreader_speedmax_field->text().toFloat());
    myConfiguration->setSpreader_speed_min(ui->spreader_speedmin_field->text().toFloat());

    myConfiguration->setStatus(SettingsObject::SettingsStatus::SETTINGS_VALID);
    ui->gcode_tool_button_openFile->setEnabled(true);
    ui->ManualControlHome_frame->setEnabled(false);
    ui->ManualControlTop_frame->setEnabled(false);
    ui->jogHminus_button->setEnabled(false);
    ui->jogHplus_button->setEnabled(false);
    ui->jogSminus_button->setEnabled(false);
    ui->jogSplus_button->setEnabled(false);
    ui->jogXminus_button->setEnabled(false);
    ui->jogXplus_button->setEnabled(false);
    ui->jogYminus_button->setEnabled(false);
    ui->jogYplus_button->setEnabled(false);
    ui->jogZminus_button->setEnabled(false);
    ui->jogZplus_button->setEnabled(false);
    ui->ManualControl_Frame->setEnabled(true);
    ui->printManagerControls_frame->setEnabled(false);


    if(serialPortNames.isEmpty()){
        refreshSerialPorts();
    }

    for( int i = 0; i < serialPortNames.length(); i++){
        if(i == myConfiguration.get()->laserGalvo_portNumber()){
            emit lgPort_name_changed(serialPortNames.at(i));
            ui->LaserGalvoPortStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
            ui->LaserGalvoPortStatus_field->setText("Closed");
            const QString log = "laser and galvanometer port assigned to " + serialPortNames.at(i);
            qCWarning(powder_app, log.toLocal8Bit());
        }
        else if (i == myConfiguration.get()->materialDelivery_portNumber()){
            emit mdPort_name_changed(serialPortNames.at(i));
            ui->MaterialDeliveryPortStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
            ui->MaterialDeliveryPortStatus_field->setText("Closed");
            ui->LaserGalvoPortStatus_field->setText("Closed");
            const QString log = "material delivery port assigned to " + serialPortNames.at(i);
            qCWarning(powder_app, log.toLocal8Bit());
        }
    }
    emit newConfigAvailable(myConfiguration);
    qCWarning(powder_app, "settings applied");

}

void PowderApp::refreshSerialPorts()
{
    serialPortNames.clear();
    portList.clear();
    QString info;
    portList = QSerialPortInfo::availablePorts();
    for(int p = 0; p < portList.length(); p++){
        info += ("Serial Port " + QString::number(p,10) + "\n");
        info += (" Name\t" + portList[p].portName() + "\n");
        serialPortNames.append(portList[p].portName());
        info += (" Number\t" + QString::number(p,10) + "\n");
        info += (" Description\t" + portList[p].description() + "\n");
        info += (" Location\t" + portList[p].systemLocation() + "\n");
        if(portList[p].hasProductIdentifier())
            info += (" Product ID\t" + QString::number( portList[p].productIdentifier(), 10) + "\n");
        if(portList[p].hasVendorIdentifier())
            info += (" Vendor ID\t" + QString::number( portList[p].vendorIdentifier(), 10) + "\n");
        if(portList[p].serialNumber().length() > 1)
            info += (" Serial Number\t" + portList[p].serialNumber() + "\n");
    }

    QStringList headers;
    headers << tr("  ") << tr("  ");
    portModel = new Settings_Model(headers, info);
    ui->port_view->setModel(portModel);
    for (int column = 0; column < portModel->columnCount(); ++column)
        ui->port_view->resizeColumnToContents(column);
}


void PowderApp::on_Main_Button_ConfigurationPage_clicked()
{
    ui->PortManagerDisplay_frame->setVisible(false);
    ui->AppPages->setCurrentIndex(1);
    this->QWidget::setMaximumWidth(2000);
    this->QWidget::setMaximumHeight(2000);
    this->QWidget::setMinimumWidth(1080);
    this->QWidget::setMinimumHeight(640);
    QList<int> splitterSizes = {210,700};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->MenuTree->expand(menuModel->index(1,0,QModelIndex()));

}

void PowderApp::on_Main_Button_PortPage_clicked()
{
    ui->PortManagerDisplay_frame->setVisible(false);
    ui->AppPages->setCurrentIndex(2);
    this->QWidget::setMaximumWidth(2000);
    this->QWidget::setMaximumHeight(2000);
    this->QWidget::setMinimumWidth(880);
    this->QWidget::setMinimumHeight(640);
    QList<int> splitterSizes = {210,700};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->MenuTree->expand(menuModel->index(1,0,QModelIndex()));

}

void PowderApp::on_Main_Button_GCodePage_clicked()
{
    ui->PortManagerDisplay_frame->setVisible(false);
    ui->AppPages->setCurrentIndex(2);
    this->QWidget::setMaximumWidth(2000);
    this->QWidget::setMaximumHeight(2000);
    this->QWidget::setMinimumWidth(1080);
    this->QWidget::setMinimumHeight(750);
    QList<int> splitterSizes = {210,1080};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->AppPages->setCurrentIndex(3);
    ui->MenuTree->expand(menuModel->index(2,0,QModelIndex()));

}

void PowderApp::on_Main_Button_ControllerPage_clicked()
{
    ui->PortManagerDisplay_frame->setVisible(true);
    ui->AppPages->setCurrentIndex(2);
    this->QWidget::setMaximumWidth(2000);
    this->QWidget::setMaximumHeight(2000);
    this->QWidget::setMinimumWidth(1080);
    this->QWidget::setMinimumHeight(750);
    QList<int> splitterSizes = {210,1080};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->AppPages->setCurrentIndex(4);
    ui->MenuTree->expand(menuModel->index(3,0,QModelIndex()));

}

void PowderApp::on_Main_Button_HelpPage_clicked()
{
    ui->PortManagerDisplay_frame->setVisible(false);
    ui->AppPages->setCurrentIndex(2);
    this->QWidget::setFixedSize(880,640);
    QList<int> splitterSizes = {210,700};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->AppPages->setCurrentIndex(5);
    ui->MenuTree->expand(menuModel->index(0,0,QModelIndex()));

}

QVector<Block3D*> *PowderApp::block3d() const
{
    return m_block3d;
}

void PowderApp::setBlock3d(QVector<Block3D*> *block3d)
{
    m_block3d = block3d;
}




void PowderApp::on_MenuTree_clicked(const QModelIndex &index)
{

    // HomePage
    if(index == menuModel->index(0,0,QModelIndex())){
        ui->PortManagerDisplay_frame->setVisible(false);
        ui->AppPages->setCurrentIndex(0);
        this->QWidget::setMinimumWidth(335);
        this->QWidget::setMinimumHeight(700);

        this->QWidget::setMaximumWidth(335);
        this->QWidget::setMaximumHeight(700);
        QList<int> splitterSizes = {0,325};
        ui->Menu_Page_Splitter->setSizes(splitterSizes);
        ui->MenuTree->collapseAll();

    }

    //HelpPage
    if(index == menuModel->index(0,0,menuModel->index(0,0, QModelIndex()))){
        ui->PortManagerDisplay_frame->setVisible(false);
        ui->AppPages->setCurrentIndex(5);
        this->QWidget::setMaximumWidth(2000);
        this->QWidget::setMaximumHeight(2000);
        this->QWidget::setMinimumWidth(880);
        this->QWidget::setMinimumHeight(640);
        QList<int> splitterSizes = {210,700};
        ui->Menu_Page_Splitter->setSizes(splitterSizes);


    }

    // Port Page
    if(index == menuModel->index(0,0,menuModel->index(1,0, QModelIndex()))){
        ui->PortManagerDisplay_frame->setVisible(false);
        ui->AppPages->setCurrentIndex(2);
        this->QWidget::setMaximumWidth(2000);
        this->QWidget::setMaximumHeight(2000);
        this->QWidget::setMinimumWidth(880);
        this->QWidget::setMinimumHeight(640);
        QList<int> splitterSizes = {210,700};
        ui->Menu_Page_Splitter->setSizes(splitterSizes);

    }
    // Confirgurator Page
    if(index == menuModel->index(1,0,menuModel->index(1,0, QModelIndex()))){
        ui->PortManagerDisplay_frame->setVisible(false);
        ui->AppPages->setCurrentIndex(1);
        this->QWidget::setMaximumWidth(2000);
        this->QWidget::setMaximumHeight(2000);
        this->QWidget::setMinimumWidth(880);
        this->QWidget::setMinimumHeight(640);
        QList<int> splitterSizes = {210,700};
        ui->Menu_Page_Splitter->setSizes(splitterSizes);

    }

    // G-Code Preprocessor Page
    if(index == menuModel->index(0,0,(menuModel->index(2,0, QModelIndex())))){
        ui->PortManagerDisplay_frame->setVisible(false);
        ui->AppPages->setCurrentIndex(3);
        this->QWidget::setMaximumWidth(2000);
        this->QWidget::setMaximumHeight(2000);
        this->QWidget::setMinimumWidth(1080);
        this->QWidget::setMinimumHeight(750);
        QList<int> splitterSizes = {210,1080};
        ui->Menu_Page_Splitter->setSizes(splitterSizes);

    }

    // Print Tools Page
    if(index == menuModel->index(3,0,QModelIndex())){
        ui->PortManagerDisplay_frame->setVisible(true);
        this->QWidget::setMaximumWidth(2000);
        this->QWidget::setMaximumHeight(2000);
        this->QWidget::setMinimumWidth(1080);
        this->QWidget::setMinimumHeight(750);
        QList<int> splitterSizes = {210,1080};
        ui->Menu_Page_Splitter->setSizes(splitterSizes);
        ui->AppPages->setCurrentIndex(4);
    }



    // 3D View Page
    if(index == menuModel->index(0,0,(menuModel->index(3,0, QModelIndex())))){

        if(m_block3d != nullptr)
            emit view3d_pressed(m_block3d);
    }

    // Debug Terminal Page
    if(index == menuModel->index(1,0,(menuModel->index(3,0, QModelIndex())))){

    }

}

void PowderApp::on_settings_button_refreshPorts_clicked()
{
    refreshSerialPorts();
}

void PowderApp::on_settings_button_resetToDefault_clicked()
{
    m_userSettingsPath.clear();
    viewDefaultSettings();

}

void PowderApp::on_settings_button_openFile_clicked()
{
    m_userSettingsPath.clear();

    QFileDialog dialog(this);
    if (dialog.exec())
        m_userSettingsPath = dialog.selectedFiles()[0];

    if(!m_userSettingsPath.isEmpty()){
        viewUserSettings();
    }


}

void PowderApp::on_settings_buttons_saveFile_clicked()
{
    if(m_userSettingsPath.isEmpty()){
        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::Directory);
        if (dialog.exec())
            m_userSettingsPath =  dialog.selectedFiles()[0];
        m_userSettingsPath += "/powderUserConfig.ini";
    }

    qWarning(powder_app, "Settings Exported");
    saveUserSettings();

}

void PowderApp::on_settings_button_apply_clicked()
{
    applySettings();
}


void PowderApp::on_gcode_tool_button_openFile_clicked()
{
    emit close_view3d();
    if(!m_myPart.isNull())
        m_myPart.clear();
    QString partFileName;
    QFileDialog dialog(this);
    if (dialog.exec())
        partFileName = dialog.selectedFiles()[0];
    m_partFile_open = true;

    m_myPart = QSharedPointer<PartObject>(new PartObject(partFileName, myConfiguration));
    m_block3d = new QVector<Block3D*>;
    m_block3d->clear();
    QString partStatusStr;
    if(m_myPart->parserStatus() != PartObject::ParserStatus::PARSER_SUCCESS)
        partStatusStr = "Parser Failed: Invalid Part!";
    else
        partStatusStr = "Part is Valid";

    PartInfoDataModel = new QStandardItemModel;
    QStandardItem * partDataRoot = PartInfoDataModel->invisibleRootItem();
    ui->PartInfoViewData->setModel(PartInfoDataModel);
    QStandardItem *partName = new QStandardItem(m_myPart->partFilePath());
    QStandardItem *partStatus =new QStandardItem(partStatusStr);
    QStandardItem *partLayers = new QStandardItem(QString::number(m_myPart->layerCount()));
    QStandardItem *partBlocks = new QStandardItem(QString::number(m_myPart->blockCount()));
    partDataRoot->appendRow(partName);
    partDataRoot->appendRow(partStatus);
    partDataRoot->appendRow(partLayers);
    partDataRoot->appendRow(partBlocks);

    ui->printTools_errorBrowser->setText(m_myPart->errorStr());

    int blockCount = 0;
    int layerCount = 0;
    ui->printTools_gCodeBrowser->clear();
    ui->printTools_outputBrowser->clear();

    QVector3D previousPosition(0,0,0);

    QStringList gcodeList = m_myPart->gcode();
    QStringList::iterator gcodeIterator = gcodeList.begin();
    QVector<int> lflags = m_myPart->layerFlags();
    while ((gcodeIterator != gcodeList.end())) {
        if((lflags.length() > 0) && ((layerCount < lflags.length()))){
            if(lflags.at(layerCount) == blockCount){
                layerCount++;
            }
        }
        QString gCodeOut =  ("[Block " + QString::number(blockCount) + " , Layer " + QString::number(layerCount) + "]\n");
        gCodeOut += "   " + *gcodeIterator;
        gCodeOut += "\n";
        ui->printTools_gCodeBrowser->append(gCodeOut);

        QString commandOut = ("[Block " + QString::number(blockCount) + ", Layer " + QString::number(layerCount) + "]\n");
        commandOut += " Laser/Galvo:\n";
        commandOut += "   " + m_myPart.get()->getBlock(blockCount).lg_string();
        commandOut += "\n Material Delivery:";
        commandOut += "\n Build Plate: " + m_myPart.get()->getBlock(blockCount).md_string().at(0);
        commandOut += "\n Hoppper: " + m_myPart.get()->getBlock(blockCount).md_string().at(1);
        commandOut += "\n Spreader: " + m_myPart.get()->getBlock(blockCount).md_string().at(2);
        commandOut += "\n";
        ui->printTools_outputBrowser->append(commandOut);

        uint16_t task = m_myPart.get()->getBlock(blockCount).blockTask();

        QVector3D current(previousPosition);
        if(task & (BlockObject::BlockTask::SET_X_POSITION)){
            current.setX(m_myPart.get()->getBlock(blockCount).x_position());
        }
        if(task & (BlockObject::BlockTask::SET_Y_POSITION)){
            current.setZ(m_myPart.get()->getBlock(blockCount).y_position());
        }
        if(task & (BlockObject::BlockTask::SET_Z_POSITION)){
            current.setY(m_myPart.get()->getBlock(blockCount).z_position());
        }

        if(current != previousPosition){
            bool lenabled = m_myPart.get()->getBlock(blockCount).laser_enabled();
            m_block3d->append(new Block3D(previousPosition,current,lenabled));
        }
        previousPosition = current;

        blockCount++;

        ++gcodeIterator;
    }

    if(m_myPart.get()->parserStatus() == PartObject::ParserStatus::PARSER_SUCCESS){
        ui->printManager_frame->setEnabled(true);
        ui->printManagerStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
        ui->printManager_status_field->setText("Part File Loaded");
        QString pf = partFileName;
        int namestart = pf.lastIndexOf("/")+1;
        pf = pf.right(pf.length()-namestart);
        ui->printManager_file_field->setText(pf);
        ui->printManager_block_bar->setValue(0);
        ui->printManager_block_bar->setMaximum(m_myPart.get()->blockCount()-1);
        ui->printManager_layer_bar->setValue(0);
        ui->printManager_layer_bar->setMaximum(m_myPart.get()->layerCount());
        ui->totalBlocks_field->setNum(m_myPart.get()->blockCount()-1);
        ui->totalLayers_field->setNum(m_myPart.get()->layerCount());
        ui->printManagerControls_frame->setEnabled(true);
        emit newPartAvailable(m_myPart);
    }
}




void PowderApp::on_gcode_tool_button_clearPart_clicked()
{
    emit close_view3d();
    if(m_partFile_open){
        ui->printTools_outputBrowser->clear();
        ui->printTools_gCodeBrowser->clear();
        ui->printTools_outputBrowser->clear();
        PartInfoDataModel->clear();
        for(int i = 0; i < m_block3d->size(); i++)
            delete m_block3d->takeAt(i);
        m_block3d->clear();
        delete m_block3d;
        m_block3d = nullptr;
        m_myPart.clear();
        m_partFile_open = false;
    }
}



void PowderApp::on_printManager_start_button_pressed()
{

}

QSharedPointer<SettingsObject> PowderApp::getMyConfiguration() const
{
    return myConfiguration;
}

void PowderApp::setMyConfiguration(const QSharedPointer<SettingsObject> &value)
{
    myConfiguration = value;
}

void PowderApp::viewDefaultSettings()
{
    QSettings defaultConfig(":/config.ini", QSettings::IniFormat);

    ui->env_baud_field->setText(defaultConfig.value("port_settings/environment_controller/baud_rate").toString());
    ui->env_portnum_field->setText(defaultConfig.value("port_settings/environment_controller/port_number").toString());

    ui->lg_baudrate_field->setText(defaultConfig.value("port_settings/laser_and_galvanometer/baud_rate").toString());
    ui->lg_portnum_field->setText(defaultConfig.value("port_settings/laser_and_galvanometer/port_number").toString());

    ui->md_baudrate_field->setText(defaultConfig.value("port_settings/material_delivery/baud_rate").toString());
    ui->md_portnum_field->setText(defaultConfig.value("port_settings/material_delivery/port_number").toString());

    ui->laser_axisnum_field->setText(defaultConfig.value("laser_settings/axis_number").toString());
    ui->laser_devicenum_field->setText(defaultConfig.value("laser_settings/device_number").toString());
    ui->laser_powerres_field->setText(defaultConfig.value("laser_settings/power/resolution").toString());
    ui->laser_powerdef_field->setText(defaultConfig.value("laser_settings/power/default").toString());
    ui->laser_powermax_field->setText(defaultConfig.value("laser_settings/power/max").toString());
    ui->laser_powermin_field->setText(defaultConfig.value("laser_settings/power/min").toString());

    ui->galvo_devicenum_field->setText(defaultConfig.value("galvanometer_settings/device_number").toString());
    ui->galvo_speeddef_field->setText(defaultConfig.value("galvanometer_settings/speed/default").toString());
    ui->galvo_speedmax_field->setText(defaultConfig.value("galvanometer_settings/speed/max").toString());
    ui->galvo_speedmin_field->setText(defaultConfig.value("galvanometer_settings/speed/min").toString());

    ui->galvo_x_axisnum_field->setText(defaultConfig.value("galvanometer_settings/x_axis/axis_number").toString());
    ui->galvo_x_axisalias_field->setText(defaultConfig.value("galvanometer_settings/x_axis/gcode_alias").toString());
    ui->galvo_x_steps_field->setText(defaultConfig.value("galvanometer_settings/x_axis/position/ustep_per_mm").toString());
    ui->galvo_x_positionmax_field->setText(defaultConfig.value("galvanometer_settings/x_axis/position/max").toString());
    ui->galvo_x_positionmin_field->setText(defaultConfig.value("galvanometer_settings/x_axis/position/min").toString());

    ui->galvo_y_axisnum_field->setText(defaultConfig.value("galvanometer_settings/y_axis/axis_number").toString());
    ui->galvo_y_axisalias_field->setText(defaultConfig.value("galvanometer_settings/y_axis/gcode_alias").toString());
    ui->galvo_y_steps_field->setText(defaultConfig.value("galvanometer_settings/y_axis/position/ustep_per_mm").toString());
    ui->galvo_y_positionmax_field->setText(defaultConfig.value("galvanometer_settings/y_axis/position/max").toString());
    ui->galvo_y_positionmin_field->setText(defaultConfig.value("galvanometer_settings/y_axis/position/min").toString());

    ui->buildplate_devicenum_field->setText(defaultConfig.value("build_plate_settings/device_number").toString());
    ui->buildplate_axisnum_field->setText(defaultConfig.value("build_plate_settings/axis_number").toString());
    ui->buildplate_axisalias_field->setText(defaultConfig.value("build_plate_settings/gcode_alias").toString());
    ui->buildplate_steps_field->setText(defaultConfig.value("build_plate_settings/position/ustep_per_mm").toString());
    ui->buildplate_positionmax_field->setText(defaultConfig.value("build_plate_settings/position/max").toString());
    ui->buildplate_positionmin_field->setText(defaultConfig.value("build_plate_settings/position/min").toString());
    ui->buildplate_speeddef_field->setText(defaultConfig.value("build_plate_settings/speed/default").toString());
    ui->buildplate_speedmax_field->setText(defaultConfig.value("build_plate_settings/speed/max").toString());
    ui->buildplate_speedmin_field->setText(defaultConfig.value("build_plate_settings/speed/min").toString());

    ui->hopper_devicenum_field->setText(defaultConfig.value("hopper_settings/device_number").toString());
    ui->hopper_axisnum_field->setText(defaultConfig.value("hopper_settings/axis_number").toString());
    ui->hopper_axisalias_field->setText(defaultConfig.value("hopper_settings/gcode_alias").toString());
    ui->hopper_steps_field->setText(defaultConfig.value("hopper_settings/position/ustep_per_mm").toString());
    ui->hopper_positionmax_field->setText(defaultConfig.value("hopper_settings/position/max").toString());
    ui->hopper_positionmin_field->setText(defaultConfig.value("hopper_settings/position/min").toString());
    ui->hopper_speeddef_field->setText(defaultConfig.value("hopper_settings/speed/default").toString());
    ui->hopper_speedmax_field->setText(defaultConfig.value("hopper_settings/speed/max").toString());
    ui->hopper_speedmin_field->setText(defaultConfig.value("hopper_settings/speed/min").toString());

    ui->spreader_devicenum_field->setText(defaultConfig.value("spreader_settings/device_number").toString());
    ui->spreader_axisnum_field->setText(defaultConfig.value("spreader_settings/axis_number").toString());
    ui->spreader_axisalias_field->setText(defaultConfig.value("spreader_settings/gcode_alias").toString());
    ui->spreader_steps_field->setText(defaultConfig.value("spreader_settings/position/ustep_per_mm").toString());
    ui->spreader_positionmax_field->setText(defaultConfig.value("spreader_settings/position/max").toString());
    ui->spreader_positionmin_field->setText(defaultConfig.value("spreader_settings/position/min").toString());
    ui->spreader_speeddef_field->setText(defaultConfig.value("spreader_settings/speed/default").toString());
    ui->spreader_speedmax_field->setText(defaultConfig.value("spreader_settings/speed/max").toString());
    ui->spreader_speedmin_field->setText(defaultConfig.value("spreader_settings/speed/min").toString());


}

void PowderApp::viewUserSettings()
{
    QSettings userConfig(m_userSettingsPath, QSettings::IniFormat);

    ui->env_baud_field->setText(userConfig.value("port_settings/environment_controller/baud_rate").toString());
    ui->env_portnum_field->setText(userConfig.value("port_settings/environment_controller/port_number").toString());

    ui->lg_baudrate_field->setText(userConfig.value("port_settings/laser_and_galvanometer/baud_rate").toString());
    ui->lg_portnum_field->setText(userConfig.value("port_settings/laser_and_galvanometer/port_number").toString());

    ui->md_baudrate_field->setText(userConfig.value("port_settings/material_delivery/baud_rate").toString());
    ui->md_portnum_field->setText(userConfig.value("port_settings/material_delivery/port_number").toString());

    ui->laser_axisnum_field->setText(userConfig.value("laser_settings/axis_number").toString());
    ui->laser_devicenum_field->setText(userConfig.value("laser_settings/device_number").toString());
    ui->laser_powerres_field->setText(userConfig.value("laser_settings/power/resolution").toString());
    ui->laser_powerdef_field->setText(userConfig.value("laser_settings/power/default").toString());
    ui->laser_powermax_field->setText(userConfig.value("laser_settings/power/max").toString());
    ui->laser_powermin_field->setText(userConfig.value("laser_settings/power/min").toString());

    ui->galvo_devicenum_field->setText(userConfig.value("galvanometer_settings/device_number").toString());
    ui->galvo_speeddef_field->setText(userConfig.value("galvanometer_settings/speed/default").toString());
    ui->galvo_speedmax_field->setText(userConfig.value("galvanometer_settings/speed/max").toString());
    ui->galvo_speedmin_field->setText(userConfig.value("galvanometer_settings/speed/min").toString());

    ui->galvo_x_axisnum_field->setText(userConfig.value("galvanometer_settings/x_axis/axis_number").toString());
    ui->galvo_x_axisalias_field->setText(userConfig.value("galvanometer_settings/x_axis/gcode_alias").toString());
    ui->galvo_x_steps_field->setText(userConfig.value("galvanometer_settings/x_axis/position/ustep_per_mm").toString());
    ui->galvo_x_positionmax_field->setText(userConfig.value("galvanometer_settings/x_axis/position/max").toString());
    ui->galvo_x_positionmin_field->setText(userConfig.value("galvanometer_settings/x_axis/position/min").toString());

    ui->galvo_y_axisnum_field->setText(userConfig.value("galvanometer_settings/y_axis/axis_number").toString());
    ui->galvo_y_axisalias_field->setText(userConfig.value("galvanometer_settings/y_axis/gcode_alias").toString());
    ui->galvo_y_steps_field->setText(userConfig.value("galvanometer_settings/y_axis/position/ustep_per_mm").toString());
    ui->galvo_y_positionmax_field->setText(userConfig.value("galvanometer_settings/y_axis/position/max").toString());
    ui->galvo_y_positionmin_field->setText(userConfig.value("galvanometer_settings/y_axis/position/min").toString());

    ui->buildplate_devicenum_field->setText(userConfig.value("build_plate_settings/device_number").toString());
    ui->buildplate_axisnum_field->setText(userConfig.value("build_plate_settings/axis_number").toString());
    ui->buildplate_axisalias_field->setText(userConfig.value("build_plate_settings/gcode_alias").toString());
    ui->buildplate_steps_field->setText(userConfig.value("build_plate_settings/position/ustep_per_mm").toString());
    ui->buildplate_positionmax_field->setText(userConfig.value("build_plate_settings/position/max").toString());
    ui->buildplate_positionmin_field->setText(userConfig.value("build_plate_settings/position/min").toString());
    ui->buildplate_speeddef_field->setText(userConfig.value("build_plate_settings/speed/default").toString());
    ui->buildplate_speedmax_field->setText(userConfig.value("build_plate_settings/speed/max").toString());
    ui->buildplate_speedmin_field->setText(userConfig.value("build_plate_settings/speed/min").toString());

    ui->hopper_devicenum_field->setText(userConfig.value("hopper_settings/device_number").toString());
    ui->hopper_axisnum_field->setText(userConfig.value("hopper_settings/axis_number").toString());
    ui->hopper_axisalias_field->setText(userConfig.value("hopper_settings/gcode_alias").toString());
    ui->hopper_steps_field->setText(userConfig.value("hopper_settings/position/ustep_per_mm").toString());
    ui->hopper_positionmax_field->setText(userConfig.value("hopper_settings/position/max").toString());
    ui->hopper_positionmin_field->setText(userConfig.value("hopper_settings/position/min").toString());
    ui->hopper_speeddef_field->setText(userConfig.value("hopper_settings/speed/default").toString());
    ui->hopper_speedmax_field->setText(userConfig.value("hopper_settings/speed/max").toString());
    ui->hopper_speedmin_field->setText(userConfig.value("hopper_settings/speed/min").toString());

    ui->spreader_devicenum_field->setText(userConfig.value("spreader_settings/device_number").toString());
    ui->spreader_axisnum_field->setText(userConfig.value("spreader_settings/axis_number").toString());
    ui->spreader_axisalias_field->setText(userConfig.value("spreader_settings/gcode_alias").toString());
    ui->spreader_steps_field->setText(userConfig.value("spreader_settings/position/ustep_per_mm").toString());
    ui->spreader_positionmax_field->setText(userConfig.value("spreader_settings/position/max").toString());
    ui->spreader_positionmin_field->setText(userConfig.value("spreader_settings/position/min").toString());
    ui->spreader_speeddef_field->setText(userConfig.value("spreader_settings/speed/default").toString());
    ui->spreader_speedmax_field->setText(userConfig.value("spreader_settings/speed/max").toString());
    ui->spreader_speedmin_field->setText(userConfig.value("spreader_settings/speed/min").toString());

}

void PowderApp::saveDefaultSettings()
{
    QSettings defaultConfig(":/config.ini", QSettings::IniFormat);

    defaultConfig.beginGroup("port_settings");

    defaultConfig.beginGroup("laser_and_galvanometer");
    defaultConfig.setValue("port_number", ui->lg_portnum_field->text());
    defaultConfig.setValue("baud_rate", ui->lg_baudrate_field->text());
    defaultConfig.endGroup();

    defaultConfig.beginGroup("material_delivery");
    defaultConfig.setValue("port_number", ui->md_portnum_field->text());
    defaultConfig.setValue("baud_rate", ui->md_baudrate_field->text());
    defaultConfig.endGroup();

    defaultConfig.beginGroup("environment_controller");
    defaultConfig.setValue("port_number", ui->env_portnum_field->text());
    defaultConfig.setValue("baud_rate", ui->env_baud_field->text());
    defaultConfig.endGroup();

    defaultConfig.endGroup();


    defaultConfig.beginGroup("laser_settings");
    defaultConfig.setValue("device_number", ui->laser_devicenum_field->text());
    defaultConfig.setValue("axis_number", ui->laser_axisnum_field->text());

    defaultConfig.beginGroup("power");
    defaultConfig.setValue("resolution", ui->laser_powerres_field->text());
    defaultConfig.setValue("default",ui->laser_powerdef_field->text());
    defaultConfig.setValue("max",ui->laser_powermax_field->text());
    defaultConfig.setValue("min",ui->laser_powermin_field->text());
    defaultConfig.endGroup();
    defaultConfig.endGroup();

    defaultConfig.beginGroup("galvanometer_settings");
    defaultConfig.setValue("device_number", ui->galvo_devicenum_field->text());

    defaultConfig.beginGroup("speed");
    defaultConfig.setValue("default", ui->galvo_speeddef_field->text());
    defaultConfig.setValue("max", ui->galvo_speedmax_field->text());
    defaultConfig.setValue("min", ui->galvo_speedmin_field->text());
    defaultConfig.endGroup();

    defaultConfig.beginGroup("x_axis");
    defaultConfig.setValue("axis_number", ui->galvo_x_axisnum_field->text());
    defaultConfig.setValue("gcode_alias", ui->galvo_x_axisalias_field->text());

    defaultConfig.beginGroup("position");
    defaultConfig.setValue("ustep_per_mm", ui->galvo_x_steps_field->text());
    defaultConfig.setValue("max", ui->galvo_x_positionmax_field->text());
    defaultConfig.setValue("min", ui->galvo_x_positionmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.endGroup();

    defaultConfig.beginGroup("y_axis");
    defaultConfig.setValue("axis_number", ui->galvo_y_axisnum_field->text());
    defaultConfig.setValue("gcode_alias", ui->galvo_y_axisalias_field->text());

    defaultConfig.beginGroup("position");
    defaultConfig.setValue("ustep_per_mm", ui->galvo_y_steps_field->text());
    defaultConfig.setValue("max", ui->galvo_y_positionmax_field->text());
    defaultConfig.setValue("min", ui->galvo_y_positionmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.endGroup();

    defaultConfig.endGroup();

    defaultConfig.beginGroup("build_plate_settings");
    defaultConfig.setValue("device_number", ui->buildplate_devicenum_field->text());
    defaultConfig.setValue("axis_number", ui->buildplate_axisnum_field->text());
    defaultConfig.setValue("gcode_alias", ui->buildplate_axisalias_field->text());
    defaultConfig.beginGroup("speed");
    defaultConfig.setValue("default", ui->buildplate_speeddef_field->text());
    defaultConfig.setValue("max", ui->buildplate_speedmax_field->text());
    defaultConfig.setValue("min", ui->buildplate_speedmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.beginGroup("position");
    defaultConfig.setValue("ustep_per_mm", ui->buildplate_steps_field->text());
    defaultConfig.setValue("max", ui->buildplate_positionmax_field->text());
    defaultConfig.setValue("min", ui->buildplate_positionmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.endGroup();

    defaultConfig.beginGroup("hopper_settings");
    defaultConfig.setValue("device_number", ui->hopper_devicenum_field->text());
    defaultConfig.setValue("axis_number", ui->hopper_axisnum_field->text());
    defaultConfig.setValue("gcode_alias", ui->hopper_axisalias_field->text());
    defaultConfig.beginGroup("speed");
    defaultConfig.setValue("default", ui->hopper_speeddef_field->text());
    defaultConfig.setValue("max", ui->hopper_speedmax_field->text());
    defaultConfig.setValue("min", ui->hopper_speedmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.beginGroup("position");
    defaultConfig.setValue("ustep_per_mm", ui->hopper_steps_field->text());
    defaultConfig.setValue("max", ui->hopper_positionmax_field->text());
    defaultConfig.setValue("min", ui->hopper_positionmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.endGroup();

    defaultConfig.beginGroup("spreader_settings");
    defaultConfig.setValue("device_number", ui->spreader_devicenum_field->text());
    defaultConfig.setValue("axis_number", ui->spreader_axisnum_field->text());
    defaultConfig.setValue("gcode_alias", ui->spreader_axisalias_field->text());
    defaultConfig.beginGroup("speed");
    defaultConfig.setValue("default", ui->spreader_speeddef_field->text());
    defaultConfig.setValue("max", ui->spreader_speedmax_field->text());
    defaultConfig.setValue("min", ui->spreader_speedmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.beginGroup("position");
    defaultConfig.setValue("ustep_per_mm", ui->spreader_steps_field->text());
    defaultConfig.setValue("max", ui->spreader_positionmax_field->text());
    defaultConfig.setValue("min", ui->spreader_positionmin_field->text());
    defaultConfig.endGroup();
    defaultConfig.endGroup();

}

void PowderApp::saveUserSettings()
{
    QSettings userConfig(m_userSettingsPath, QSettings::IniFormat);

    userConfig.beginGroup("port_settings");

    userConfig.beginGroup("laser_and_galvanometer");
    userConfig.setValue("port_number", ui->lg_portnum_field->text());
    userConfig.setValue("baud_rate", ui->lg_baudrate_field->text());
    userConfig.endGroup();

    userConfig.beginGroup("material_delivery");
    userConfig.setValue("port_number", ui->md_portnum_field->text());
    userConfig.setValue("baud_rate", ui->md_baudrate_field->text());
    userConfig.endGroup();

    userConfig.beginGroup("environment_controller");
    userConfig.setValue("port_number", ui->env_portnum_field->text());
    userConfig.setValue("baud_rate", ui->env_baud_field->text());
    userConfig.endGroup();

    userConfig.endGroup();


    userConfig.beginGroup("laser_settings");
    userConfig.setValue("device_number", ui->laser_devicenum_field->text());
    userConfig.setValue("axis_number", ui->laser_axisnum_field->text());

    userConfig.beginGroup("power");
    userConfig.setValue("resolution", ui->laser_powerres_field->text());
    userConfig.setValue("default",ui->laser_powerdef_field->text());
    userConfig.setValue("max",ui->laser_powermax_field->text());
    userConfig.setValue("min",ui->laser_powermin_field->text());
    userConfig.endGroup();
    userConfig.endGroup();

    userConfig.beginGroup("galvanometer_settings");
    userConfig.setValue("device_number", ui->galvo_devicenum_field->text());

    userConfig.beginGroup("speed");
    userConfig.setValue("default", ui->galvo_speeddef_field->text());
    userConfig.setValue("max", ui->galvo_speedmax_field->text());
    userConfig.setValue("min", ui->galvo_speedmin_field->text());
    userConfig.endGroup();

    userConfig.beginGroup("x_axis");
    userConfig.setValue("axis_number", ui->galvo_x_axisnum_field->text());
    userConfig.setValue("gcode_alias", ui->galvo_x_axisalias_field->text());

    userConfig.beginGroup("position");
    userConfig.setValue("ustep_per_mm", ui->galvo_x_steps_field->text());
    userConfig.setValue("max", ui->galvo_x_positionmax_field->text());
    userConfig.setValue("min", ui->galvo_x_positionmin_field->text());
    userConfig.endGroup();
    userConfig.endGroup();

    userConfig.beginGroup("y_axis");
    userConfig.setValue("axis_number", ui->galvo_y_axisnum_field->text());
    userConfig.setValue("gcode_alias", ui->galvo_y_axisalias_field->text());

    userConfig.beginGroup("position");
    userConfig.setValue("ustep_per_mm", ui->galvo_y_steps_field->text());
    userConfig.setValue("max", ui->galvo_y_positionmax_field->text());
    userConfig.setValue("min", ui->galvo_y_positionmin_field->text());
    userConfig.endGroup();
    userConfig.endGroup();

    userConfig.endGroup();

    userConfig.beginGroup("build_plate_settings");
    userConfig.setValue("device_number", ui->buildplate_devicenum_field->text());
    userConfig.setValue("axis_number", ui->buildplate_axisnum_field->text());
    userConfig.setValue("gcode_alias", ui->buildplate_axisalias_field->text());
    userConfig.beginGroup("speed");
    userConfig.setValue("default", ui->buildplate_speeddef_field->text());
    userConfig.setValue("max", ui->buildplate_speedmax_field->text());
    userConfig.setValue("min", ui->buildplate_speedmin_field->text());
    userConfig.endGroup();
    userConfig.beginGroup("position");
    userConfig.setValue("ustep_per_mm", ui->buildplate_steps_field->text());
    userConfig.setValue("max", ui->buildplate_positionmax_field->text());
    userConfig.setValue("min", ui->buildplate_positionmin_field->text());
    userConfig.endGroup();
    userConfig.endGroup();

    userConfig.beginGroup("hopper_settings");
    userConfig.setValue("device_number", ui->hopper_devicenum_field->text());
    userConfig.setValue("axis_number", ui->hopper_axisnum_field->text());
    userConfig.setValue("gcode_alias", ui->hopper_axisalias_field->text());
    userConfig.beginGroup("speed");
    userConfig.setValue("default", ui->hopper_speeddef_field->text());
    userConfig.setValue("max", ui->hopper_speedmax_field->text());
    userConfig.setValue("min", ui->hopper_speedmin_field->text());
    userConfig.endGroup();
    userConfig.beginGroup("position");
    userConfig.setValue("ustep_per_mm", ui->hopper_steps_field->text());
    userConfig.setValue("max", ui->hopper_positionmax_field->text());
    userConfig.setValue("min", ui->hopper_positionmin_field->text());
    userConfig.endGroup();
    userConfig.endGroup();

    userConfig.beginGroup("spreader_settings");
    userConfig.setValue("device_number", ui->spreader_devicenum_field->text());
    userConfig.setValue("axis_number", ui->spreader_axisnum_field->text());
    userConfig.setValue("gcode_alias", ui->spreader_axisalias_field->text());
    userConfig.beginGroup("speed");
    userConfig.setValue("default", ui->spreader_speeddef_field->text());
    userConfig.setValue("max", ui->spreader_speedmax_field->text());
    userConfig.setValue("min", ui->spreader_speedmin_field->text());
    userConfig.endGroup();
    userConfig.beginGroup("position");
    userConfig.setValue("ustep_per_mm", ui->spreader_steps_field->text());
    userConfig.setValue("max", ui->spreader_positionmax_field->text());
    userConfig.setValue("min", ui->spreader_positionmin_field->text());
    userConfig.endGroup();
    userConfig.endGroup();
}


QSharedPointer<PartObject> PowderApp::myPart() const
{
    return m_myPart;
}

void PowderApp::setMyPart(const QSharedPointer<PartObject> &myPart)
{
    m_myPart = myPart;
}



void PowderApp::on_PortManager_options_box_activated(const QString &arg1)
{
    if(arg1 == "Close Laser & Galvanometer Port"){
        emit lgPort_connectionRequested(false);
    }
    else if(arg1 == "Open Laser & Galvanometer Port")
    {
        emit lgPort_connectionRequested(true);
    }
    else if(arg1 == "Close Build Plate & Material Delivery Port"){
        emit mdPort_connectionRequested(false);
    }
    else if(arg1 == "Open Build Plate & Material Delivery Port"){
        emit mdPort_connectionRequested(true);
    }
    else if (arg1 == "Clear Errors"){
        ui->laserDisplayEnable_button->setChecked(false);
        ui->LaserDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->LaserDisplayStatus_field->setText("Disabled");

        ui->galvoDisplayEnable_button->setChecked(false);
        ui->galvoDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->galvoStatus_field->setText("Disabled");

        ui->materialDeliveryDisplayEnable_button->setChecked(false);
        ui->materialDeliveryDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->materialDeliveryDisplayStatus_field->setText("Disabled");


        emit cleaDeviceErrors();
    }
    ui->PortManager_options_box->setCurrentIndex(0);
}


void PowderApp::on_ManualControlEnable_button_toggled(bool checked)
{
    if(checked){
        ui->PrintManagerEnable_button->setChecked(false);
        ui->ManualControlHome_frame->setEnabled(true);
        ui->ManualControlTop_frame->setEnabled(true);

    }
    else
    {
        ui->ManualControlHome_frame->setEnabled(false);
        ui->ManualControlTop_frame->setEnabled(false);
        ui->jogHminus_button->setEnabled(false);
        ui->jogHplus_button->setEnabled(false);
        ui->jogSminus_button->setEnabled(false);
        ui->jogSplus_button->setEnabled(false);
        ui->jogXminus_button->setEnabled(false);
        ui->jogXplus_button->setEnabled(false);
        ui->jogYminus_button->setEnabled(false);
        ui->jogYplus_button->setEnabled(false);
        ui->jogZminus_button->setEnabled(false);
        ui->jogZplus_button->setEnabled(false);
    }
}

void PowderApp::on_galvoDisplayEnable_button_toggled(bool checked)
{
    if(checked){
        ui->jogXminus_button->setEnabled(true);
        ui->jogXplus_button->setEnabled(true);
        ui->jogYminus_button->setEnabled(true);
        ui->jogYplus_button->setEnabled(true);
        deviceTransport->ping_laserGalvo();
    }
    else
    {
        ui->jogXminus_button->setEnabled(false);
        ui->jogXplus_button->setEnabled(false);
        ui->jogYminus_button->setEnabled(false);
        ui->jogYplus_button->setEnabled(false);
        ui->galvoDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->galvoStatus_field->setText("Disabled");
    }
}

void PowderApp::on_buildPlateEnable_button_toggled(bool checked)
{
    if(checked){
        ui->jogZminus_button->setEnabled(true);
        ui->jogZplus_button->setEnabled(true);
//        deviceTransport->on_homeOption_change(2);
//        deviceTransport->on_home_request();
        deviceTransport->ping_materialDelivery(1,1);

    }
    else
    {
        ui->jogZminus_button->setEnabled(false);
        ui->jogZplus_button->setEnabled(false);
        ui->buildPlateDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->buildPlateDisplayStatus_field->setText("Disabled");
    }
}

void PowderApp::on_materialDeliveryDisplayEnable_button_toggled(bool checked)
{
    if(checked){
        ui->jogHminus_button->setEnabled(true);
        ui->jogHplus_button->setEnabled(true);
        ui->jogSminus_button->setEnabled(true);
        ui->jogSplus_button->setEnabled(true);
        deviceTransport->ping_materialDelivery(2,0);
    }
    else
    {
        ui->jogHminus_button->setEnabled(false);
        ui->jogHplus_button->setEnabled(false);
        ui->jogSminus_button->setEnabled(false);
        ui->jogSplus_button->setEnabled(false);
        ui->materialDeliveryDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->materialDeliveryDisplayStatus_field->setText("Disabled");
    }
}



void PowderApp::on_PrintManagerEnable_button_toggled(bool checked)
{
    if(checked && ui->printManager_status_field->text() == "Part File Loaded"){
        ui->ManualControlEnable_button->setChecked(false);
    }
}

void PowderApp::on_lg_port_connectionChanged(bool open)
{
    if(open){
        ui->LaserGalvoPortStatus_indicator->setIcon(QIcon(":/icons/icons/greenbut.png"));
        ui->LaserGalvoPortStatus_field->setText("Open");
        ui->laserDisplay_frame->setEnabled(true);
        ui->galvoDisplay_frame->setEnabled(true);
        ui->PortManagerInfo_browser->setStyleSheet("color:rgb(191,87,218)");
        ui->PortManagerInfo_browser->setText("Port Opened For Laser & Galvanometer!");
        ui->PortManagerInfo_browser->append("Port # " + QString::number(myConfiguration.get()->laserGalvo_portNumber()));
        ui->PortManagerInfo_browser->append(serialPortNames.at(myConfiguration.get()->laserGalvo_portNumber()));
        ui->PortManager_options_box->setItemText(1,"Close Laser & Galvanometer Port");
    }
    else{
        ui->laserDisplayEnable_button->setChecked(false);
        ui->galvoDisplayEnable_button->setChecked(false);
        ui->LaserGalvoPortStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
        ui->LaserGalvoPortStatus_field->setText("Closed");
        ui->laserDisplay_frame->setEnabled(false);
        ui->galvoDisplay_frame->setEnabled(false);
        ui->PortManagerInfo_browser->setStyleSheet("color:rgb(191,87,218)");
        ui->PortManagerInfo_browser->setText("Port Closed For Laser & Galvanometer!");
        ui->PortManagerInfo_browser->append("Port # " + QString::number(myConfiguration.get()->laserGalvo_portNumber()));
        ui->PortManagerInfo_browser->append(serialPortNames.at(myConfiguration.get()->laserGalvo_portNumber()));
        ui->PortManager_options_box->setItemText(1,"Open Laser & Galvanometer Port");
    }
}

void PowderApp::on_md_port_connectionChanged(bool open)
{
    if(open){
        ui->materialDeliveryDisplayEnable_button->setChecked(false);
        ui->buildPlateEnable_button->setChecked(false);
        ui->MaterialDeliveryPortStatus_indicator->setIcon(QIcon(":/icons/icons/greenbut.png"));
        ui->MaterialDeliveryPortStatus_field->setText("Open");
        ui->materialDeliveryDisplay_frame->setEnabled(true);
        ui->buildPlateDisplay_frame->setEnabled(true);
        ui->PortManagerInfo_browser->setStyleSheet("color:rgb(191,87,218)");
        ui->PortManagerInfo_browser->setText("Port Opened For Build Plate & Material Delivery!");
        ui->PortManagerInfo_browser->append("Port # " + QString::number(myConfiguration.get()->materialDelivery_portNumber()));
        ui->PortManagerInfo_browser->append(serialPortNames.at(myConfiguration.get()->materialDelivery_portNumber()));
        ui->PortManager_options_box->setItemText(2,"Close Build Plate & Material Delivery Port");
    }
    else{
        ui->MaterialDeliveryPortStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
        ui->MaterialDeliveryPortStatus_field->setText("Closed");
        ui->materialDeliveryDisplay_frame->setEnabled(false);
        ui->buildPlateDisplay_frame->setEnabled(false);
        ui->PortManagerInfo_browser->setStyleSheet("color:rgb(191,87,218)");
        ui->PortManagerInfo_browser->setText("Port Closed For Build Plate & Material Delivery!");
        ui->PortManagerInfo_browser->append("Port # " + QString::number(myConfiguration.get()->materialDelivery_portNumber()));
        ui->PortManagerInfo_browser->append(serialPortNames.at(myConfiguration.get()->materialDelivery_portNumber()));
        ui->PortManager_options_box->setItemText(2,"Open Build Plate & Material Delivery Port");
    }
}

void PowderApp::on_lg_portError(const QString &Error)
{
    ui->PortManagerInfo_browser->setStyleSheet("color:rgb(125,37,33)");
    ui->PortManagerInfo_browser->setText(Error);

    ui->galvoDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
    ui->galvoStatus_field->setText("Error!");
}

void PowderApp::on_lg_portReply(const QString &reply)
{
    ui->PortManagerInfo_browser->setStyleSheet("color:rgb(29,155,246)");
    ui->PortManagerInfo_browser->append(reply);

    ui->galvoDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/greenbut.png"));
    ui->galvoStatus_field->setText("Idle");
}

void PowderApp::on_md_portError(const QString &Error)
{
    ui->PortManagerInfo_browser->setStyleSheet("color:rgb(255,37,33)");
    ui->PortManagerInfo_browser->setText(Error);

    const QString z = "0"+QString::number(myConfiguration.get()->z_deviceNumber())
            +" " + QString::number(myConfiguration.get()->z_axisNumber());
    const QString hs = "/0"+QString::number(myConfiguration.get()->hopper_deviceNumber());

    if(Error.contains(z)){
        ui->buildPlateDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->buildPlateDisplayStatus_field->setText("Error!");
    }
    else if(Error.contains(hs)){
        ui->materialDeliveryDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/redbutton.png"));
        ui->materialDeliveryDisplayStatus_field->setText("Error");
    }


}

void PowderApp::on_md_portReply(const QString &reply)
{
    ui->PortManagerInfo_browser->setStyleSheet("color:rgb(29,155,246)");
    ui->PortManagerInfo_browser->append(reply);

    const QString z = "0"+QString::number(myConfiguration.get()->z_deviceNumber())
            +" " + QString::number(myConfiguration.get()->z_axisNumber());

    const QString hs = "/0"+QString::number(myConfiguration.get()->hopper_deviceNumber());

    if(reply.contains("IDLE")){
        if(reply.contains(z)){
            ui->buildPlateDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/greenbut.png"));
            ui->buildPlateDisplayStatus_field->setText("Idle");
        }
        else if(reply.contains(hs)){
            ui->materialDeliveryDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/greenbut.png"));
            ui->materialDeliveryDisplayStatus_field->setText("Idle");
        }
    }
    else if(reply.contains("BUSY")){
        if(reply.contains(z)){
            ui->buildPlateDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
            ui->buildPlateDisplayStatus_field->setText("Busy");
        }
        else if(reply.contains(hs)){
            ui->materialDeliveryDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
            ui->materialDeliveryDisplayStatus_field->setText("Busym");
        }
    }
}

void PowderApp::on_transportError(const QString &Error)
{
    ui->PortManagerInfo_browser->setStyleSheet("color:rgb(255,37,33)");
    ui->PortManagerInfo_browser->setText(Error);

}

void PowderApp::on_printManager_reset_button_clicked()
{
    emit reset_printManger();
}

void PowderApp::on_buildPlateBusy()
{
    ui->buildPlateDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
    ui->buildPlateDisplayStatus_field->setText("Busy");
}

void PowderApp::on_galvoBusy()
{
    ui->galvoDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
    ui->galvoStatus_field->setText("Busy");
}

void PowderApp::on_hop_spread_busy()
{    ui->materialDeliveryDisplayStatus_indicator->setIcon(QIcon(":/icons/icons/orangebut.png"));
     ui->materialDeliveryDisplayStatus_field->setText("Busy");
}

void PowderApp::on_settings_button_saveAsDefault_released()
{
    saveDefaultSettings();
    qWarning(powder_app, "Default Settings Modified");
}


