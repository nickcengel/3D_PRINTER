#include "segment3d.h"
#include <Qt3DExtras/QPhongMaterial>

Qt3DExtras::QPlaneMesh *segmentMesh(const QVector3D& start, const QVector3D& end, float width){
    const QVector3D seg(end - start);
    Qt3DExtras::QPlaneMesh *pMesh = new Qt3DExtras::QPlaneMesh();
    pMesh->setWidth(width);
    pMesh->setHeight(seg.length());
    return  pMesh;
}

Qt3DCore::QTransform *segmentTransform(const QVector3D& start, const QVector3D& end){
    const QVector3D seg(end - start);
    Qt3DCore::QTransform *segTransform = new Qt3DCore::QTransform();
    segTransform->setScale(1.0f);
    segTransform->setRotation(QQuaternion::fromDirection(seg, (QVector3D(0.0f, 1.0f, 0.0f))));
    segTransform->setTranslation(QVector3D((start.x() + seg.x()/2), seg.y(), (start.z() + seg.z()/2)));
    return  segTransform;
}

Qt3DCore::QEntity *generateSegment(const QVector3D &start, const QVector3D &end, float width, QColor color, Qt3DCore::QEntity *_rootEntity){
    Qt3DCore::QEntity *segment = new Qt3DCore::QEntity(_rootEntity);
    Qt3DExtras::QPhongMaterial *planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(color);
    segment->addComponent(planeMaterial);
    segment->addComponent(segmentTransform(start,end));
    segment->addComponent(segmentMesh(start,end, width));
    segment->setEnabled(true);
    return segment;
}
