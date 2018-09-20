#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include <QColor>
#include <Qt3DCore/qentity.h>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DCore/qtransform.h>

Qt3DExtras::QPlaneMesh *segmentMesh(const QVector3D &start, const QVector3D &end, float width);

Qt3DCore::QTransform *segmentTransform(const QVector3D& start, const QVector3D& end);

Qt3DCore::QEntity *generateSegment(const QVector3D &start, const QVector3D &end, float width, QColor color, Qt3DCore::QEntity *_rootEntity);

#endif // SEGMENT3D_H
