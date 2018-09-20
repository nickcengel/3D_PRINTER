#include "powder_view3d.h"

PowderView3D::PowderView3D(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");
    this->setWindowTitle("3D Viewer");
    m_view = nullptr;
    m_hLayout = nullptr;
    m_input = nullptr;
    m_rootEntity = nullptr;
    m_lightEntity = nullptr;
    m_lightTransform = nullptr;
    m_camController = nullptr;
    m_modifier = nullptr;
    m_blocks3d = nullptr;
    this->setVisible(false);
}



void PowderView3D::on_3dView_open(QVector<PowderBlock3D*> *blocks3d){


    if(!(this->isVisible())){

        m_view = new Qt3DExtras::Qt3DWindow();
        m_view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
        m_container = QWidget::createWindowContainer(m_view);
        QSize screenSize = m_view->screen()->size();
        m_container->setMinimumSize(QSize(200, 100));
        m_container->setMaximumSize(screenSize);

        m_hLayout = new QHBoxLayout(this);
        m_hLayout->addWidget(m_container, 1);
        m_hLayout->setContentsMargins(0,0,0,0);

        m_input = new Qt3DInput::QInputAspect;
        m_view->registerAspect(m_input);

        // Root entity
        m_rootEntity = new Qt3DCore::QEntity();
        // Camera
        m_cameraEntity = m_view->camera();
        m_cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
        m_cameraEntity->setPosition(QVector3D(50.0f, 0.0f, 50.0f));
        m_cameraEntity->setUpVector(QVector3D(0, 1, 0));
        m_cameraEntity->setViewCenter(QVector3D(0, -100.0f, 0));

        m_lightEntity = new Qt3DCore::QEntity(m_rootEntity);
        m_light = new Qt3DRender::QPointLight(m_lightEntity);
        m_light->setColor("white");
        m_light->setIntensity(1.0f);

        m_lightTransform = new Qt3DCore::QTransform(m_lightEntity);
        m_lightTransform->setTranslation(m_cameraEntity->position());
        m_lightEntity->addComponent(m_lightTransform);

        m_camController = new Qt3DExtras::QFirstPersonCameraController(m_rootEntity);
        m_camController->setCamera(m_cameraEntity);
        m_camController->setAcceleration(64.0);
        m_camController->setLookSpeed(128.0);
        m_camController->setLinearSpeed(128.0);

        m_modifier = new SceneModifier(m_rootEntity);

        if(blocks3d != nullptr){
            for(int i = 0; i < blocks3d->size(); i++){
                m_modifier->addSegment(blocks3d->at(i));
            }
        }
        m_view->setRootEntity(m_rootEntity);

        this->setVisible(true);
        this->show();
        this->resize(640,640);
    }
}

void PowderView3D::on_3dView_close()
{
    if(this->isVisible()){
        this->closeEvent(new QCloseEvent());
    }
}



QVector<PowderBlock3D *> *PowderView3D::blocks3d() const
{
    return m_blocks3d;
}

void PowderView3D::setBlocks3d(QVector<PowderBlock3D *> *blocks3d)
{
    m_blocks3d = blocks3d;
}




void PowderView3D::closeEvent(QCloseEvent *bar){
    this->setVisible(false);
    delete m_modifier;
    delete m_hLayout;
    m_input->deleteLater();
    m_view->deleteLater();

    m_input = nullptr;
    m_view = nullptr;
    m_hLayout = nullptr;

    bar->accept();
}
