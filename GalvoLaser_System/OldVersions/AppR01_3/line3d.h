#ifndef LINE3D_H
#define LINE3D_H

#include <QColor>
#include <Qt3DCore/qentity.h>
#include <Qt3DExtras/QPlaneMesh>

Qt3DCore::QEntity *generateLine(const QVector3D& start, const QVector3D& end, const QColor& color, Qt3DCore::QEntity *_rootEntity);


#endif // LINE3D_H
