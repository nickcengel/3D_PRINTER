#include "view3dapp.h"

View3DApp::View3DApp(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");
    this->setWindowTitle("3D Viewer");
    view = nullptr;
    hLayout = nullptr;
    input = nullptr;
    rootEntity = nullptr;
    lightEntity = nullptr;
    light = nullptr;
    camController = nullptr;
    modifier = nullptr;
    m_blocks3d = nullptr;
    this->setVisible(false);
}



void View3DApp::open_3dView(QVector<Block3D> *blocks3d){


    if(!(this->isVisible())){

        view = new Qt3DExtras::Qt3DWindow();
        view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
        container = QWidget::createWindowContainer(view);
        QSize screenSize = view->screen()->size();
        container->setMinimumSize(QSize(200, 100));
        container->setMaximumSize(screenSize);

        hLayout = new QHBoxLayout(this);
        hLayout->addWidget(container, 1);
        hLayout->setContentsMargins(0,0,0,0);

        input = new Qt3DInput::QInputAspect;
        view->registerAspect(input);

        // Root entity
        rootEntity = new Qt3DCore::QEntity();
        // Camera
        cameraEntity = view->camera();
        cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
        cameraEntity->setPosition(QVector3D(25.0f, 25.0f, 25.0f));
        cameraEntity->setUpVector(QVector3D(0, 1, 0));
        cameraEntity->setViewCenter(QVector3D(0, 0, 0));

        lightEntity = new Qt3DCore::QEntity(rootEntity);
        light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(1);

        lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(25.0f, 25.0f, 25.0f));
        lightEntity->addComponent(lightTransform);

        camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
        camController->setCamera(cameraEntity);
        camController->setAcceleration(64.0);
        camController->setLookSpeed(128.0);
        camController->setLinearSpeed(128.0);

        modifier = new SceneModifier(rootEntity);

        if(blocks3d != nullptr){
            for(int i = 0; i < blocks3d->size(); i++){
                modifier->addSegment(blocks3d->at(i));
            }
        }
        view->setRootEntity(rootEntity);

        this->setVisible(true);
        this->show();
        this->resize(640,640);
    }
}

void View3DApp::close_3dView()
{
    if(this->isVisible()){
        this->closeEvent(new QCloseEvent());
    }
}




void View3DApp::closeEvent(QCloseEvent *bar){
    this->setVisible(false);
    delete modifier;
    delete hLayout;
    input->deleteLater();
    view->deleteLater();

    input = nullptr;
    view = nullptr;
    hLayout = nullptr;

    bar->accept();
}
