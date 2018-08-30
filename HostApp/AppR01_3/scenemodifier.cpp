
#include "scenemodifier.h"
#include "line3d.h"
#include "segment3d.h"
#include <QtCore/QDebug>
#include <Qt3DExtras>

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity)
{




    m_axis.push_back(generateLine(QVector3D(-50,0,0), QVector3D(50,0,0),QColor(Qt::black),m_rootEntity));
    m_axis.push_back(generateLine(QVector3D(-50,0,0), QVector3D(50,0,0),QColor(Qt::black),m_rootEntity));
    m_axis.push_back(generateLine(QVector3D(0,-50,0), QVector3D(0,50,0),QColor(Qt::black),m_rootEntity));
    m_axis.push_back(generateLine(QVector3D(0,0,-50), QVector3D(0,0,50),QColor(Qt::black),m_rootEntity));

    // Cuboid shape data
    Qt3DExtras::QCuboidMesh *buildVolume = new Qt3DExtras::QCuboidMesh();

    // CuboidMesh Transform
    Qt3DCore::QTransform *cuboidTransform = new Qt3DCore::QTransform();
    cuboidTransform->setScale(100.0f);
    cuboidTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DExtras::QPhongAlphaMaterial *cuboidMaterial = new Qt3DExtras::QPhongAlphaMaterial();
    cuboidMaterial->setDiffuse(QColor(QRgb(Qt::white)));
    cuboidMaterial->setAlpha(0.10f);

    //Cuboid
    m_buildEnvelope = new Qt3DCore::QEntity(m_rootEntity);
    m_buildEnvelope->addComponent(buildVolume);
    m_buildEnvelope->addComponent(cuboidMaterial);
    m_buildEnvelope->addComponent(cuboidTransform);



    // Plane shape data
    QVector3D start(0,0,0);
    QVector3D end(2,0,4);
    QVector3D d(2,0,4);
    QVector3D e(5,0,1);

    this->addSegment(generateSegment(start,end,0.125,(Qt::white),rootEntity));
    this->addSegment(generateSegment(d,e,0.125,(Qt::white),rootEntity));


}

SceneModifier::~SceneModifier()
{
}

//! [4]




void SceneModifier::enableBoundBox(bool enabled){
    m_buildEnvelope->setEnabled(enabled);
}

void SceneModifier::enableAxis(bool enabled){
    m_axis[0]->setEnabled(enabled);
    m_axis[1]->setEnabled(enabled);
    m_axis[2]->setEnabled(enabled);
    m_axis[3]->setEnabled(enabled);
}


void SceneModifier::addSegment(Qt3DCore::QEntity *segment){
    m_segments.push_back(segment);
}

void SceneModifier::addSegment(QVector3D &start,QVector3D &end, int width, QColor color){
    m_segments.push_back(generateSegment(start,end,width,color, m_rootEntity));
}


void SceneModifier::addSegment(float xStart, float yStart, float zStart,
                               float xEnd, float yEnd, float zEnd,
                               int width, QColor color){
    m_segments.push_back(generateSegment(QVector3D(xStart,yStart, zStart),
                                         QVector3D(xEnd, yEnd, zEnd),
                                         width, color, m_rootEntity));
}


void SceneModifier::clearSegment(int segmentNumber){
    m_segments.remove(segmentNumber);
}


void SceneModifier::clearSegments(){
    m_segments.clear();
}


void SceneModifier::showSegments(bool enabled){
    for (int i = 0; i < m_segments.length(); i++)
        m_segments[i]->setEnabled(enabled);
}
