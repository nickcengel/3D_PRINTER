#-------------------------------------------------
#
# Project created by QtCreator 2018-08-23T18:27:21
#
#-------------------------------------------------

QT       += core gui widgets \
            serialport

QT += 3dextras
QT += 3dcore 3drender 3dinput 3dextras
QT += widgets

TARGET = AppR01_2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    settings_item.cpp \
    settings_model.cpp \
    serial_port_drivers.cpp \
    hardware_drivers.cpp \
    gcode_tools.cpp \
    print_tools.cpp \
    menu_item.cpp \
    menu_model.cpp \
    line3d.cpp \
    scenemodifier.cpp \
    segment3d.cpp \
    powderapp.cpp \
    view3dapp.cpp \
    system_objects/blockobject.cpp \
    system_objects/partobject.cpp \
    system_objects/settingsobject.cpp \
    system_objects/partannex.cpp

HEADERS += \
    settings_model.h \
    settings_item.h \
    serial_port_drivers.h \
    hardware_drivers.h \
    gcode_tools.h \
    print_tools.h \
    menu_item.h \
    menu_model.h \
    line3d.h \
    scenemodifier.h \
    segment3d.h \
    powderapp.h \
    view3dapp.h \
    system_objects/blockobject.h \
    system_objects/partobject.h \
    system_objects/settingsobject.h \
    system_objects/partannex.h

FORMS += \
    powderapp.ui

target.path = $$[QT_INSTALL_EXAMPLES]/qt3d/$$TARGET
INSTALLS += target

RESOURCES += \
    icons.qrc \
    settings.qrc
