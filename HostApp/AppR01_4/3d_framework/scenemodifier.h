#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H



#include <QtCore/QObject>
#include <QVector>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QPhongMaterial>
#include "3d_framework/block3d.h"
class SceneModifier : public QObject
{
    Q_OBJECT

public:
    explicit SceneModifier(Qt3DCore::QEntity *rootEntity);
    ~SceneModifier();

public slots:

    void enableBoundBox(bool enabled);
    void enableAxis(bool enabled);

    void addSegment(Qt3DCore::QEntity *segment);
    void addSegment(QVector3D &start, QVector3D &end, float width, QColor color);
    void addSegment(float xStart, float yStart, float zStart, float xEnd, float yEnd, float zEnd, float width, QColor color);
    void addSegment(Block3D *b);

    void clearSegment(int segmentNumber);
    void clearSegments();

    void showSegments(bool enabled);



private:
    Qt3DCore::QEntity *m_rootEntity;
    QVector<Qt3DCore::QEntity*> m_segments;
    QVector<Qt3DCore::QEntity*> m_axis;
    Qt3DCore::QEntity *m_buildEnvelope;

};


#endif // SCENEMODIFIER_H
