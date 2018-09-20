#include "powder_block3d.h"
#include <QtDebug>

PowderBlock3D::PowderBlock3D()
{
    qRegisterMetaType<PowderBlock3D>("PowderBlock3D");
}

PowderBlock3D::PowderBlock3D(float x_start, float y_start, float z_start, float x_end, float y_end, float z_end, bool laser_state)
{
    m_start.setX(x_start);
    m_start.setY(y_start-100);
    m_start.setZ(z_start);
    m_end.setX(x_end);
    m_end.setY(y_end);
    m_end.setZ(z_end);
    m_LaserState = laser_state;
}

PowderBlock3D::PowderBlock3D(QVector3D &previous, QVector3D &current, bool laser_state)
{
    m_start = previous;
    m_start.setY(m_start.y() - 100);
    m_end = current;
    m_end.setY(m_end.y() - 100);
    m_LaserState = laser_state;
}



PowderBlock3D::~PowderBlock3D()
{

}

QVector3D PowderBlock3D::start() const
{
    return m_start;
}

void PowderBlock3D::setStart(const QVector3D &start)
{
    m_start = start;
}

QVector3D PowderBlock3D::end()
{
    return m_end;
}

void PowderBlock3D::setEnd(const QVector3D &end)
{
    m_end = end;
}

bool PowderBlock3D::LaserState() const
{
    return m_LaserState;
}

void PowderBlock3D::setLaserState(bool LaserState)
{
    m_LaserState = LaserState;
}
