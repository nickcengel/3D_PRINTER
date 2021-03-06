#include "widget.h"
#include "ui_widget.h"
#include "settings_model.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QTreeView>
#include <QIcon>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

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
    HomeMenuRoot->setIcon(QIcon(":/icons/icons/icon_w_poly.png"));
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

    QStandardItem* PrintToolsRoot = new QStandardItem("Preprocessor Tools");
    PrintToolsRoot->setIcon(QIcon(":/icons/icons/buffer.png"));
    menuRoot->appendRow(PrintToolsRoot);

    QStandardItem* ImportGcodeMenu = new QStandardItem("G-Code Converter");
    ImportGcodeMenu->setIcon(QIcon(":/icons/icons/angle-double-right.png"));
    PrintToolsRoot->appendRow(ImportGcodeMenu);

    QStandardItem* HardwareToolsRoot = new QStandardItem("Hardware Tools");
    HardwareToolsRoot->setIcon(QIcon(":/icons/icons/Icon-eto-tools.png"));
    menuRoot->appendRow(HardwareToolsRoot);

    QStandardItem* HardwareTools_Monitor = new QStandardItem("System Monitor");
    HardwareTools_Monitor->setIcon(QIcon(":/icons/icons/iosAnalytics.png"));
    HardwareToolsRoot->appendRow(HardwareTools_Monitor);

    QStandardItem* HardwareTools_Controller = new QStandardItem("System Controller");
    HardwareTools_Controller->setIcon(QIcon(":/icons/icons/arrows.png"));
    HardwareToolsRoot->appendRow(HardwareTools_Controller);

    QStandardItem* HardwareTools_CommandLine = new QStandardItem("Command Line");
    HardwareTools_CommandLine->setIcon(QIcon(":/icons/icons/code.png"));
    HardwareToolsRoot->appendRow(HardwareTools_CommandLine);

    QStringList headers;
    headers << tr("  ") << tr("  ");
    m_currentCustomSettingsFile = "null";
    QFile file(":/default/Settings/machineset.txt");
    file.open(QIODevice::ReadOnly);
    settingsModel = new Settings_Model(headers, file.readAll());
    file.close();
    ui->settings_view->setModel(settingsModel);
    for (int column = 0; column < settingsModel->columnCount(); ++column)
        ui->settings_view->resizeColumnToContents(column);
}

Widget::~Widget()
{
    delete ui;
}





void Widget::on_settings_button_refreshPorts_clicked()
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

void Widget::on_settings_button_resetToDefault_clicked()
{
    QFile file(":/default/Settings/machineset.txt");
    file.open(QIODevice::ReadOnly);
    QStringList headers;
    headers << tr("  ") << tr("  ");
    settingsModel = new Settings_Model(headers, file.readAll());
    file.close();

    ui->settings_view->setModel(settingsModel);
    for (int column = 0; column < settingsModel->columnCount(); ++column)
        ui->settings_view->resizeColumnToContents(column);
}

void Widget::on_settings_button_openFile_clicked()
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

void Widget::on_settings_buttons_saveFile_clicked()
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
}

void Widget::on_settings_button_apply_clicked()
{
    QModelIndex first = settingsModel->index(0,0, QModelIndex());
    QModelIndex root =  settingsModel->parent(first);

    QModelIndex LaserParent = settingsModel->index(0, 0, root);
    machineSettings.l_settings.portNumber = (settingsModel->index(0,1,LaserParent).data(Qt::DisplayRole).toInt());   // portnum
    machineSettings.l_settings.deviceNumber = (settingsModel->index(1,1,LaserParent).data(Qt::DisplayRole).toUInt()); // devicenum
    machineSettings.l_settings.axisNumber = (settingsModel->index(2,1,LaserParent).data(Qt::DisplayRole).toUInt()); // axisnum
    QModelIndex LaserPowerParent = settingsModel->index(3, 0, LaserParent);
    machineSettings.l_settings.homeOffset = (settingsModel->index(0,1,LaserPowerParent).data(Qt::DisplayRole).toFloat());   // defpower
    machineSettings.l_settings.speedMax = (settingsModel->index(1,1,LaserPowerParent).data(Qt::DisplayRole).toFloat()); // maxpow
    machineSettings.l_settings.speedMin = (settingsModel->index(2,1,LaserPowerParent).data(Qt::DisplayRole).toFloat()); // minpow

    QModelIndex GalvoParent = settingsModel->index(1, 0, root);
    machineSettings.x_settings.portNumber = (settingsModel->index(0,1,GalvoParent).data(Qt::DisplayRole).toInt());   // portnum
    machineSettings.x_settings.deviceNumber = (settingsModel->index(1,1,GalvoParent).data(Qt::DisplayRole).toUInt()); // devicenum

    QModelIndex GalvoXParent = settingsModel->index(2, 0, GalvoParent);
    machineSettings.x_settings.axisNumber = (settingsModel->index(0,1,GalvoXParent).data(Qt::DisplayRole).toUInt()); // axisnum
    machineSettings.x_settings.uStepPerMM = (settingsModel->index(1,1,GalvoXParent).data(Qt::DisplayRole).toFloat());   // steps
    machineSettings.x_settings.positionMax =  (settingsModel->index(2,1,GalvoXParent).data(Qt::DisplayRole).toFloat()); // posmin
    machineSettings.x_settings.positionMin = (settingsModel->index(3,1,GalvoXParent).data(Qt::DisplayRole).toFloat()); // posmax
    machineSettings.x_settings.speedMin = (settingsModel->index(4,1,GalvoXParent).data(Qt::DisplayRole).toFloat()); // spdmin
    machineSettings.x_settings.speedMax = (settingsModel->index(5,1,GalvoXParent).data(Qt::DisplayRole).toFloat()); // spdmax

    QModelIndex GalvoYParent = settingsModel->index(3, 0, GalvoParent);
    machineSettings.y_settings.axisNumber = (settingsModel->index(0,1,GalvoYParent).data(Qt::DisplayRole).toUInt()); // axisnum
    machineSettings.y_settings.uStepPerMM = (settingsModel->index(1,1,GalvoYParent).data(Qt::DisplayRole).toFloat());   // steps
    machineSettings.y_settings.positionMax =  (settingsModel->index(2,1,GalvoYParent).data(Qt::DisplayRole).toFloat()); // posmin
    machineSettings.y_settings.positionMin = (settingsModel->index(3,1,GalvoYParent).data(Qt::DisplayRole).toFloat()); // posmax
    machineSettings.y_settings.speedMin = (settingsModel->index(4,1,GalvoYParent).data(Qt::DisplayRole).toFloat()); // spdmin
    machineSettings.y_settings.speedMax = (settingsModel->index(5,1,GalvoYParent).data(Qt::DisplayRole).toFloat()); // spdmax


    QModelIndex BuildParent = settingsModel->index(2, 0, root);
    machineSettings.z_settings.portNumber = (settingsModel->index(0,1,BuildParent).data(Qt::DisplayRole).toInt());   // portnum
    machineSettings.z_settings.deviceNumber = (settingsModel->index(1,1,BuildParent).data(Qt::DisplayRole).toUInt()); // devicenum
    machineSettings.z_settings.axisNumber = (settingsModel->index(2,1,BuildParent).data(Qt::DisplayRole).toUInt()); // axisnum
    machineSettings.z_settings.uStepPerMM = (settingsModel->index(3,1,BuildParent).data(Qt::DisplayRole).toFloat());   // steps
    machineSettings.z_settings.positionMin = (settingsModel->index(4,1,BuildParent).data(Qt::DisplayRole).toFloat()); // posmin
    machineSettings.z_settings.positionMax = (settingsModel->index(5,1,BuildParent).data(Qt::DisplayRole).toFloat()); // posmax
    machineSettings.z_settings.speedMin = (settingsModel->index(6,1,BuildParent).data(Qt::DisplayRole).toFloat()); // spdmin
    machineSettings.z_settings.speedMax = (settingsModel->index(7,1,BuildParent).data(Qt::DisplayRole).toFloat()); // spdmax


    QModelIndex HopperParent = settingsModel->index(3, 0, root);
    machineSettings.a_settings.portNumber = (settingsModel->index(0,1,HopperParent).data(Qt::DisplayRole).toInt());   // portnum
    machineSettings.a_settings.deviceNumber = (settingsModel->index(1,1,HopperParent).data(Qt::DisplayRole).toUInt()); // devicenum
    machineSettings.a_settings.axisNumber = (settingsModel->index(2,1,HopperParent).data(Qt::DisplayRole).toUInt()); // axisnum
    machineSettings.a_settings.uStepPerMM = (settingsModel->index(3,1,HopperParent).data(Qt::DisplayRole).toFloat());   // steps
    machineSettings.a_settings.positionMin = (settingsModel->index(4,1,HopperParent).data(Qt::DisplayRole).toFloat()); // posmin
    machineSettings.a_settings.positionMax = (settingsModel->index(5,1,HopperParent).data(Qt::DisplayRole).toFloat()); // posmax
    machineSettings.a_settings.speedMin = (settingsModel->index(6,1,HopperParent).data(Qt::DisplayRole).toFloat()); // spdmin
    machineSettings.a_settings.speedMax =  (settingsModel->index(7,1,HopperParent).data(Qt::DisplayRole).toFloat()); // spdmax


    QModelIndex SpreaderParent = settingsModel->index(4, 0, root);
    machineSettings.b_settings.portNumber = (settingsModel->index(0,1,SpreaderParent).data(Qt::DisplayRole).toInt());   // portnum
    machineSettings.b_settings.deviceNumber = (settingsModel->index(1,1,SpreaderParent).data(Qt::DisplayRole).toUInt()); // devicenum
    machineSettings.b_settings.axisNumber = (settingsModel->index(2,1,SpreaderParent).data(Qt::DisplayRole).toUInt()); // axisnum
    machineSettings.b_settings.uStepPerMM = (settingsModel->index(3,1,SpreaderParent).data(Qt::DisplayRole).toFloat());   // steps
    machineSettings.b_settings.positionMin = (settingsModel->index(4,1,SpreaderParent).data(Qt::DisplayRole).toFloat()); // posmin
    machineSettings.b_settings.positionMax = (settingsModel->index(5,1,SpreaderParent).data(Qt::DisplayRole).toFloat()); // posmax
    machineSettings.b_settings.speedMin = (settingsModel->index(6,1,SpreaderParent).data(Qt::DisplayRole).toFloat()); // spdmin
    machineSettings.b_settings.speedMax =  (settingsModel->index(7,1,SpreaderParent).data(Qt::DisplayRole).toFloat()); // spdmax
}



void Widget::on_MenuTree_clicked(const QModelIndex &index)
{
    QModelIndex settingsIndex = menuModel->index(0,0, QModelIndex());

    if(index == menuModel->index(0,0,settingsIndex)){
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(index == menuModel->index(1,0,settingsIndex)){
        ui->stackedWidget->setCurrentIndex(1);
    }

    QModelIndex HomeIndex = menuModel->index(1,0, QModelIndex());

    if(index == menuModel->index(0,0,HomeIndex)){
        ui->stackedWidget->setCurrentIndex(3);
    }
    if(index == menuModel->index(1,0,HomeIndex)){
        ui->stackedWidget->setCurrentIndex(2);
    }

    if(index == menuModel->index(0,0,(menuModel->index(2,0, QModelIndex())))){
        ui->stackedWidget->setCurrentIndex(4);
    }

    if(index == menuModel->index(0,0,(menuModel->index(3,0, QModelIndex())))){
        ui->stackedWidget->setCurrentIndex(5);
    }

}
