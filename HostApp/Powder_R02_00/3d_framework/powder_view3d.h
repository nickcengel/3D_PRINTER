#ifndef POWDER_VIEW3D_H
#define POWDER_VIEW3D_H


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

#include "powder_block3d.h"
#include "scenemodifier.h"

class PowderView3D : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QVector<PowderBlock3D *> *blocks3d READ blocks3d WRITE setBlocks3d)
public:
    explicit PowderView3D(QWidget *parent = nullptr);


    QVector<PowderBlock3D *> *blocks3d() const;
    void setBlocks3d(QVector<PowderBlock3D *> *blocks3d);

public slots:
    void on_3dView_open(QVector<PowderBlock3D*> *blocks3d);

    void on_3dView_close();

private:
    Qt3DExtras::Qt3DWindow *m_view;
    QHBoxLayout *m_hLayout;
    QWidget *m_container;
    Qt3DInput::QInputAspect *m_input;
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DRender::QCamera *m_cameraEntity;
    Qt3DCore::QEntity *m_lightEntity;
    Qt3DRender::QPointLight *m_light;
    Qt3DCore::QTransform *m_lightTransform;
    Qt3DExtras::QFirstPersonCameraController *m_camController;
    SceneModifier *m_modifier;
    QVector<PowderBlock3D*> *m_blocks3d;
    void closeEvent(QCloseEvent *bar);
};

#endif // POWDER_VIEW3D_H
