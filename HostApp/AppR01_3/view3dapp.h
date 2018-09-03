#ifndef VIEW3DAPP_H
#define VIEW3DAPP_H

#include "scenemodifier.h"

#include <QWidget>
#include <QtWidgets/QHBoxLayout>

#include <QtGui/QScreen>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>
#include <Qt3DRender/qrenderaspect.h>

#include <Qt3DExtras/qforwardrenderer.h>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

#include "gcode_tools.h"
#include "QCloseEvent"

class View3DApp : public QWidget
{
    Q_OBJECT

public:
    explicit View3DApp(QWidget *parent = nullptr);

public slots:
    void open_3dView();

    void get_Part(GCODE_BLOCK_NS::Part &newPart);

private:
    Qt3DExtras::Qt3DWindow *view;
    QHBoxLayout *hLayout;
    QWidget *container;
    Qt3DInput::QInputAspect *input;
    Qt3DCore::QEntity *rootEntity;
    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity;
    Qt3DRender::QPointLight *light;
    Qt3DCore::QTransform *lightTransform;
    Qt3DExtras::QFirstPersonCameraController *camController;
    SceneModifier *modifier;

    GCODE_BLOCK_NS::Part *myPart;
    void closeEvent(QCloseEvent *bar);
};

#endif // VIEW3DWIDGET_H
