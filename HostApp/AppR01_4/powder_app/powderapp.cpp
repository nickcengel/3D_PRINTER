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
PowderApp::PowderApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowderApp)
{
    ui->setupUi(this);
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



    QStringList headers;
    headers << tr("  ") << tr("  ");
    m_currentCustomSettingsFile = "null";
    QFile file(":/default/machineset.txt");
    file.open(QIODevice::ReadOnly);
    settingsModel = new Settings_Model(headers, file.readAll());
    file.close();
    ui->settings_view->setModel(settingsModel);
    for (int column = 0; column < settingsModel->columnCount(); ++column)
        ui->settings_view->resizeColumnToContents(column);

    m_file_open = false;

    //    partAnnex = new PartAnnex();
    //    partAnnex->setParent(this);

    //    QObject::connect(this, SIGNAL(NewPartFilePath(const QString&)),
    //                     partAnnex, SLOT(loadNewPart(const QString&)));

    //    QObject::connect(partAnnex, SIGNAL(loadPartComplete(PartObject*)),
    //                     this, SLOT(display_newPartData(PartObject*)));
    myConfiguration = nullptr;
    m_myPart = nullptr;
    m_block3d = nullptr;

    this->applySettings();
}

PowderApp::~PowderApp()
{
    delete ui;
    delete myConfiguration;
    if(m_myPart != nullptr)
        delete m_myPart;
}

void PowderApp::applySettings()
{
    myConfiguration = new SettingsObject;

    QModelIndex first = settingsModel->index(0,0, QModelIndex());
    QModelIndex root =  settingsModel->parent(first);

    QModelIndex configParent = settingsModel->index(0,0,root);
    myConfiguration->setLaser_galvo_portNumber(settingsModel->index(2,1,configParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setMaterialDelivery_portNumber(settingsModel->index(3,1,configParent).data(Qt::DisplayRole).toUInt());

    QModelIndex LaserParent = settingsModel->index(1, 0, root);
    myConfiguration->setLaser_deviceNumber(settingsModel->index(0,1,LaserParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setLaser_axisNumber(settingsModel->index(1,1,LaserParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setLaser_power_resolution(settingsModel->index(2,1,LaserParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setLaser_power_default(settingsModel->index(3,1,LaserParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setLaser_power_max(settingsModel->index(4,1,LaserParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setLaser_power_min(settingsModel->index(5,1,LaserParent).data(Qt::DisplayRole).toUInt());


    QModelIndex GalvoParent = settingsModel->index(2, 0, root);
    myConfiguration->setGalvo_deviceNumber(settingsModel->index(0,1,GalvoParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setXY_speed_default(settingsModel->index(1,1,GalvoParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setXY_speed_max(settingsModel->index(2,1,GalvoParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setXY_speed_min(settingsModel->index(3,1,GalvoParent).data(Qt::DisplayRole).toFloat());

    QModelIndex GalvoXParent = settingsModel->index(4, 0, GalvoParent);
    myConfiguration->setX_axisNumber(settingsModel->index(0,1,GalvoXParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setX_position_resolution(settingsModel->index(1,1,GalvoXParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setX_position_max(settingsModel->index(2,1,GalvoXParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setX_position_min(settingsModel->index(3,1,GalvoXParent).data(Qt::DisplayRole).toFloat());

    QModelIndex GalvoYParent = settingsModel->index(5, 0, GalvoParent);
    myConfiguration->setY_axisNumber(settingsModel->index(0,1,GalvoYParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setY_position_resolution(settingsModel->index(1,1,GalvoYParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setY_position_max(settingsModel->index(2,1,GalvoYParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setY_position_min(settingsModel->index(3,1,GalvoYParent).data(Qt::DisplayRole).toFloat());

    QModelIndex BuildParent = settingsModel->index(3, 0, root);
    myConfiguration->setZ_deviceNumber(settingsModel->index(0,1,BuildParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setZ_axisNumber(settingsModel->index(1,1,BuildParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setZ_position_resolution(settingsModel->index(2,1,BuildParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setZ_position_max(settingsModel->index(3,1,BuildParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setZ_position_min(settingsModel->index(4,1,BuildParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setZ_speed_default(settingsModel->index(5,1,BuildParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setZ_speed_max(settingsModel->index(6,1,BuildParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setZ_speed_min(settingsModel->index(7,1,BuildParent).data(Qt::DisplayRole).toFloat());


    QModelIndex HopperParent = settingsModel->index(4, 0, root);
    myConfiguration->setHopper_deviceNumber(settingsModel->index(0,1,HopperParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setHopper_axisNumber(settingsModel->index(1,1,HopperParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setHopper_position_resolution(settingsModel->index(2,1,HopperParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setHopper_position_max(settingsModel->index(3,1,HopperParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setHopper_position_min(settingsModel->index(4,1,HopperParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setHopper_speed_default(settingsModel->index(5,1,HopperParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setHopper_speed_max(settingsModel->index(6,1,HopperParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setHopper_speed_min(settingsModel->index(7,1,HopperParent).data(Qt::DisplayRole).toFloat());

    QModelIndex SpreaderParent = settingsModel->index(5, 0, root);
    myConfiguration->setSpreader_deviceNumber(settingsModel->index(0,1,SpreaderParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setSpreader_axisNumber(settingsModel->index(1,1,SpreaderParent).data(Qt::DisplayRole).toUInt());
    myConfiguration->setSpreader_position_resolution(settingsModel->index(2,1,SpreaderParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setSpreader_position_max(settingsModel->index(3,1,SpreaderParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setSpreader_position_min(settingsModel->index(4,1,SpreaderParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setSpreader_speed_default(settingsModel->index(5,1,SpreaderParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setSpreader_speed_max(settingsModel->index(6,1,SpreaderParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setSpreader_speed_min(settingsModel->index(7,1,SpreaderParent).data(Qt::DisplayRole).toFloat());
    myConfiguration->setStatus(SettingsObject::SettingsStatus::SETTINGS_VALID);
    ui->gcode_tool_button_openFile->setEnabled(true);
}


void PowderApp::on_Main_Button_ConfigurationPage_clicked()
{

    ui->AppPages->setCurrentIndex(1);
    this->QWidget::setMaximumWidth(2000);
    this->QWidget::setMaximumHeight(2000);
    this->QWidget::setMinimumWidth(880);
    this->QWidget::setMinimumHeight(640);
    QList<int> splitterSizes = {210,700};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->MenuTree->expand(menuModel->index(1,0,QModelIndex()));


}

void PowderApp::on_Main_Button_PortPage_clicked()
{
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
    ui->AppPages->setCurrentIndex(2);
    this->QWidget::setFixedSize(880,640);
    QList<int> splitterSizes = {210,700};
    ui->Menu_Page_Splitter->setSizes(splitterSizes);
    ui->AppPages->setCurrentIndex(5);
    ui->MenuTree->expand(menuModel->index(0,0,QModelIndex()));

}

QVector<Block3D> *PowderApp::block3d() const
{
    return m_block3d;
}

void PowderApp::setBlock3d(QVector<Block3D> *block3d)
{
    m_block3d = block3d;
}




void PowderApp::on_MenuTree_clicked(const QModelIndex &index)
{

    // HomePage
    if(index == menuModel->index(0,0,QModelIndex())){
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
    portList.clear();
    QString info;
    portList = QSerialPortInfo::availablePorts();
    for(int p = 0; p < portList.length(); p++){
        info += ("Serial Port " + QString::number(p,10) + "\n");
        info += (" Name\t" + portList[p].portName() + "\n");
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

void PowderApp::on_settings_button_resetToDefault_clicked()
{
    QFile file(":/default/machineset.txt");
    file.open(QIODevice::ReadOnly);
    QStringList headers;
    headers << tr("  ") << tr("  ");
    settingsModel = new Settings_Model(headers, file.readAll());
    file.close();

    ui->settings_view->setModel(settingsModel);
    for (int column = 0; column < settingsModel->columnCount(); ++column)
        ui->settings_view->resizeColumnToContents(column);
}

void PowderApp::on_settings_button_openFile_clicked()
{
    QFileDialog dialog(this);
    if (dialog.exec())
        m_currentCustomSettingsFile = dialog.selectedFiles()[0];
    QFile file(m_currentCustomSettingsFile);
    file.open(QIODevice::ReadOnly);
    QStringList headers;
    headers << tr("  ") << tr("  ");
    settingsModel = new Settings_Model(headers, file.readAll());
    file.close();
    ui->settings_view->setModel(settingsModel);
    for (int column = 0; column < settingsModel->columnCount(); ++column)
        ui->settings_view->resizeColumnToContents(column);

}

void PowderApp::on_settings_buttons_saveFile_clicked()
{
    if(m_currentCustomSettingsFile.contains("null")){
        QFileDialog dialog(this);
        dialog.setFileMode(QFileDialog::Directory);
        if (dialog.exec())
            m_currentCustomSettingsFile =  dialog.selectedFiles()[0];
        m_currentCustomSettingsFile += "/mySettings.txt";
    }

    QFile file(m_currentCustomSettingsFile);
    file.open(QIODevice::WriteOnly| QFile::Truncate);
    QTextStream out(&file);
    QModelIndex first = settingsModel->index(0,0, QModelIndex());
    QModelIndex root =  settingsModel->parent(first);

    int rows0 = settingsModel->rowCount(root);
    for(int r0 = 0; r0 < rows0; r0++){

        QModelIndex r0c0 = settingsModel->index(r0,0,root);
        out << (settingsModel->data(r0c0,Qt::DisplayRole).toString() +"\t-\n");
        int rows1 = settingsModel->rowCount(r0c0);
        int cols1 = settingsModel->columnCount(r0c0);
        for(int r1 = 0; r1 < rows1; r1++){
            out << " ";
            for(int c1 = 0; c1 < cols1; c1++){
                QModelIndex r1c1 = settingsModel->index(r1,c1,r0c0);
                if(c1 < (cols1 - 1)){
                    out << (settingsModel->data(r1c1,Qt::DisplayRole).toString() + "\t");
                }
                else
                    out << (settingsModel->data(r1c1,Qt::DisplayRole).toString() + "\n");

                if(c1 == 0){
                    int rows2 = settingsModel->rowCount(r1c1);
                    int cols2 = settingsModel->columnCount(r1c1);
                    if(rows2 > 1)
                        out << "\n";
                    for(int r2 = 0; r2 < rows2; r2++){
                        out << "  ";
                        for(int c2 = 0; c2 < cols2; c2++){
                            QModelIndex r2c2 = settingsModel->index(r2,c2,r1c1);
                            if(c2 < (cols2 - 1)){
                                out << (settingsModel->data(r2c2,Qt::DisplayRole).toString() + "\t");
                            }
                            else
                                out << (settingsModel->data(r2c2,Qt::DisplayRole).toString() + "\n");
                        }
                    }
                }
            }
        }

    }
    file.close();
}

void PowderApp::on_settings_button_apply_clicked()
{
    applySettings();
}


void PowderApp::on_gcode_tool_button_openFile_clicked()
{
    emit close_view3d();
    if(m_myPart != nullptr)
        delete m_myPart;
    QString partFileName;
    QFileDialog dialog(this);
    if (dialog.exec())
        partFileName = dialog.selectedFiles()[0];
    m_file_open = true;

    m_myPart = new PartObject(partFileName, myConfiguration);
    m_block3d = new QVector<Block3D>;
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

    uint32_t blockCount = 0;
    u_int32_t layerCount = 0;
    ui->printTools_gCodeBrowser->clear();
    ui->printTools_outputBrowser->clear();

    QVector3D previousPosition(0,0,0);

    QStringList gcodeList = m_myPart->gcode();
    QStringList::iterator gcodeIterator = gcodeList.begin();
    QVector<uint32_t> lflags = m_myPart->layerFlags();
    while ((gcodeIterator != gcodeList.end())) {
        if((lflags.length() > 0) && (static_cast<int>(layerCount) < lflags.length())){
            if(lflags.at(static_cast<int>(layerCount)) == blockCount){
                layerCount++;
            }
        }
        QString gCodeOut =  ("[Block " + QString::number(blockCount) + " , Layer " + QString::number(layerCount) + "]\n");
        gCodeOut += "   " + *gcodeIterator;
        gCodeOut += "\n";
        ui->printTools_gCodeBrowser->append(gCodeOut);

        QString commandOut = ("[Block " + QString::number(blockCount) + ", Layer " + QString::number(layerCount) + "]\n");
        commandOut += " Laser/Galvo:\n";
        commandOut += "   " + m_myPart->getBlock(static_cast<int>(blockCount))->lg_string();
        commandOut += "\n Material Delivery:\n";
        commandOut += "   " +   m_myPart->getBlock(static_cast<int>(blockCount))->md_string();
        commandOut += "\n";
        ui->printTools_outputBrowser->append(commandOut);

        uint16_t task = m_myPart->getBlock(static_cast<int>(blockCount))->blockTask();

        QVector3D current(previousPosition);
        if(task & (BlockObject::BlockTask::SET_X_POSITION)){
            current.setX(m_myPart->getBlock(static_cast<int>(blockCount))->x_position());
        }
        if(task & (BlockObject::BlockTask::SET_Y_POSITION)){
            current.setY(m_myPart->getBlock(static_cast<int>(blockCount))->y_position());
        }
        if(task & (BlockObject::BlockTask::SET_Z_POSITION)){
            current.setZ(m_myPart->getBlock(static_cast<int>(blockCount))->y_position());
        }

        if(current != previousPosition){
            bool lenabled = m_myPart->getBlock(static_cast<int>(blockCount))->laser_enabled();
            m_block3d->append(Block3D(previousPosition,current,lenabled));
        }
        previousPosition = current;

        blockCount++;

        ++gcodeIterator;
    }
}




void PowderApp::on_gcode_tool_button_clearPart_clicked()
{
    emit close_view3d();
    if(m_file_open){
        ui->printTools_outputBrowser->clear();
        ui->printTools_gCodeBrowser->clear();
        ui->printTools_outputBrowser->clear();
        PartInfoDataModel->clear();
        delete m_myPart;
        delete m_block3d;
        m_block3d = nullptr;
        m_myPart = nullptr;
        m_file_open = false;
    }
}

PartObject *PowderApp::myPart() const
{
    return m_myPart;
}

void PowderApp::setMyPart(PartObject *myPart)
{
    m_myPart = myPart;
}

