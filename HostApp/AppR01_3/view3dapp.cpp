#include "view3dapp.h"

View3DApp::View3DApp(QWidget *parent) : QWidget(parent)
{


}



void View3DApp::open_3dView(){
    this->setStyleSheet("background:rgb(0,0,0)");

    view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));

    container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(container, 1);
    hLayout->setContentsMargins(0,0,0,0);
    this->setWindowTitle("3D Viewer");
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
    lightEntity->addComponent(light);
    lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);
    camController->setAcceleration(64.0);
    camController->setLookSpeed(128.0);
    camController->setLinearSpeed(128.0);
    modifier = new SceneModifier(rootEntity);
    view->setRootEntity(rootEntity);
    this->show();
    this->resize(640,640);
}

void View3DApp::get_Part(GCODE_BLOCK_NS::Part &newPart){
    myPart = &newPart;
    QVector3D oldVector;
    QVector3D newVector;
    bool laserOn = 0;
    HARDWARE_NS::POSITION_MODE positionMode = ABSOLUTE;

    for(int l = 0; l < myPart->get_LayerCount(); l++){
        for(int b = 0; b < myPart->getLayer(l).getBlockCount(); b++){

            if((myPart->getBlock(l,b).Plate()->task)|(CHANGE_MD_POSITION_MODE)){
                positionMode = myPart->getBlock(l,b).Plate()->get_positionMode();
            }
            if((myPart->getBlock(l,b).Plate()->task)|(CHANGE_MD_POSITION)){
                if(positionMode == HARDWARE_NS::POSITION_MODE::RELATIVE){
                    newVector.setY(myPart->getBlock(l,b).Plate()->get_position() + oldVector.y());
                }
                else{
                    newVector.setY(myPart->getBlock(l,b).Plate()->get_position());
                }
            }

            if((myPart->getBlock(l,b).Laser_Galvo()->laser.is_enabled())){
                laserOn = true;
            }
            if((myPart->getBlock(l,b).Laser_Galvo()->task)|(CHANGE_LG_POSITION_MODE)){
                positionMode = myPart->getBlock(l,b).Laser_Galvo()->get_positionMode();
            }
            if((myPart->getBlock(l,b).Laser_Galvo()->task)|CHANGE_LG_X_POSITION){
                if(positionMode == HARDWARE_NS::POSITION_MODE::RELATIVE){
                    newVector.setX(myPart->getBlock(l,b).Laser_Galvo()->x_axis.get_position() + oldVector.x());
                }
                else{
                    newVector.setX(myPart->getBlock(l,b).Laser_Galvo()->x_axis.get_position());
                }
            }
            if((myPart->getBlock(l,b).Laser_Galvo()->task)|CHANGE_LG_Y_POSITION){
                if(positionMode == HARDWARE_NS::POSITION_MODE::RELATIVE){
                    newVector.setZ(myPart->getBlock(l,b).Laser_Galvo()->y_axis.get_position() + oldVector.z());
                }
                else{
                    newVector.setZ(myPart->getBlock(l,b).Laser_Galvo()->y_axis.get_position());
                }
            }
            if(oldVector != newVector){
                this->modifier->addSegment(oldVector, newVector, 0.125, Qt::red);
                oldVector = newVector;
            }


        }
    }

}

void View3DApp::closeEvent(QCloseEvent *bar){
    delete hLayout;
    container->close();
    view->close();
    this->close();
    bar->accept();
}
