#-------------------------------------------------
#
# Project created by QtCreator 2018-08-23T18:27:21
#
#-------------------------------------------------

QT += core gui widgets
QT += 3dextras
QT += 3dcore 3drender 3dinput 3dextras
QT += widgets
QT += widgets serialport

TARGET = Powder
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    3d_framework/line3d.cpp \
    3d_framework/scenemodifier.cpp \
    3d_framework/segment3d.cpp \
    model_item_frameworks/menu_item.cpp \
    model_item_frameworks/menu_model.cpp \
    model_item_frameworks/settings_item.cpp \
    model_item_frameworks/settings_model.cpp \
    main.cpp \
    hardware_tools/zaber_utility.cpp \
    powder_objects/powder_part.cpp \
    powder_objects/powder_block.cpp \
    powder_objects/powder_settings.cpp \
    3d_framework/powder_block3d.cpp \
    3d_framework/powder_view3d.cpp \
    powder_app/powder_app.cpp \
    powder_app/powder_transport.cpp \
    hardware_tools/galvo_utility.cpp \
    hardware_tools/laser_utility.cpp

HEADERS += \
    3d_framework/line3d.h \
    3d_framework/scenemodifier.h \
    3d_framework/segment3d.h \
    model_item_frameworks/menu_item.h \
    model_item_frameworks/menu_model.h \
    model_item_frameworks/settings_item.h \
    model_item_frameworks/settings_model.h \
    hardware_tools/zaber_utility.h \
    powder_objects/powder_block.h \
    powder_objects/powder_part.h \
    powder_objects/powder_settings.h \
    3d_framework/powder_block3d.h \
    3d_framework/powder_view3d.h \
    powder_app/powder_app.h \
    powder_app/powder_transport.h \
    hardware_tools/galvo_utility.h \
    hardware_tools/laser_utility.h

FORMS += \
    powder_app/powderapp.ui

target.path = $$[QT_INSTALL_EXAMPLES]/qt3d/$$TARGET
INSTALLS += target

RESOURCES += \
    resources/icons.qrc \
    resources/settings.qrc

SUBDIRS += \
    Powder_R02_00.pro

DISTFILES += \
    resources/icons/angle-double-right.png \
    resources/icons/apply.png \
    resources/icons/apply_filled.png \
    resources/icons/arrows.png \
    resources/icons/buffer.png \
    resources/icons/code.png \
    resources/icons/codeWorking.png \
    resources/icons/cube.png \
    resources/icons/greenbut.png \
    resources/icons/greybut.png \
    resources/icons/Homing.png \
    resources/icons/Icon-elusive-cogs.png \
    resources/icons/Icon-eto-flow-cascade.png \
    resources/icons/Icon-eto-help-circled.png \
    resources/icons/Icon-eto-tools.png \
    resources/icons/iosAnalytics.png \
    resources/icons/iosArrowDown.png \
    resources/icons/iosArrowForward.png \
    resources/icons/iosArrowLeft.png \
    resources/icons/iosArrowRight copy.png \
    resources/icons/iosArrowUp.png \
    resources/icons/iosDownload.png \
    resources/icons/iosGlasses.png \
    resources/icons/iosPause.png \
    resources/icons/iosPlay.png \
    resources/icons/iosPlus.png \
    resources/icons/iosRedo.png \
    resources/icons/iosSettingsStrong.png \
    resources/icons/iosSkipforward.png \
    resources/icons/iosTrash.png \
    resources/icons/iosUndo.png \
    resources/icons/iosUndoOutline.png \
    resources/icons/iosUpload.png \
    resources/icons/linea--basic-elaboration-document-next.png \
    resources/icons/linea--basic-elaboration-document-refresh.png \
    resources/icons/lock.png \
    resources/icons/newhw.png \
    resources/icons/open_file.png \
    resources/icons/orangebut.png \
    resources/icons/print.png \
    resources/icons/redbutton.png \
    resources/icons/reload.png \
    resources/icons/reset.png \
    resources/icons/reset_filled.png \
    resources/icons/save_file.png \
    resources/icons/stop.png \
    resources/icons/toggle-off1.png \
    resources/icons/toggle-on1.png \
    resources/icons/unlock-alt.png \
    resources/config.ini
