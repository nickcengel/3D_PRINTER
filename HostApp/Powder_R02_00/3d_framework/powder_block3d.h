#ifndef POWDER_BLOCK3D_H
#define POWDER_BLOCK3D_H

#include "powder_objects/powder_block.h"
#include "segment3d.h"
#include <Qt3DCore/qentity.h>
#include <QVector3D>

class PowderBlock3D{
public:
    PowderBlock3D();
    PowderBlock3D(float x_start, float y_start, float z_start, float x_end, float y_end, float z_end, bool laser_state);
    PowderBlock3D(QVector3D &previous, QVector3D &current, bool laser_state);
    ~PowderBlock3D();

    QVector3D start() const;
    void setStart(const QVector3D &start);

    QVector3D end() ;
    void setEnd(const QVector3D &end);

    bool LaserState() const;
    void setLaserState(bool LaserState);

private:
    QVector3D m_start;
    QVector3D m_end;
    bool m_LaserState;
};
Q_DECLARE_METATYPE(PowderBlock3D);


#endif // POWDER_BLOCK3D_H
