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

#include <QCloseEvent>
#include <QSharedPointer>
#include "block3d.h"

class View3DApp : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QVector<Block3D *> *blocks3d READ blocks3d WRITE setBlocks3d)
public:
    explicit View3DApp(QWidget *parent = nullptr);


    QVector<Block3D *> *blocks3d() const;
    void setBlocks3d(QVector<Block3D *> *blocks3d);

public slots:
    //    void open_3dView();
    void open_3dView(QVector<Block3D*> *blocks3d);

    void close_3dView();

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
    QVector<Block3D*> *m_blocks3d;
    void closeEvent(QCloseEvent *bar);
};

#endif // VIEW3DWIDGET_H
