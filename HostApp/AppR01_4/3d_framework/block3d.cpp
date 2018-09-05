#include "block3d.h"
#include <QtDebug>

Block3D::Block3D()
{
    qRegisterMetaType<Block3D>("Block3D");
}

Block3D::Block3D(float x_start, float y_start, float z_start, float x_end, float y_end, float z_end, bool laser_state)
{
    m_start.setX(x_start);
    m_start.setY(y_start);
    m_start.setZ(z_start);
    m_end.setX(x_end);
    m_end.setY(y_end);
    m_end.setZ(z_end);
    m_LaserState = laser_state;
}

Block3D::Block3D(QVector3D &previous, QVector3D &current, bool laser_state)
{
    m_start = previous;
    m_end = current;
    m_LaserState = laser_state;
}



Block3D::~Block3D()
{

}

QVector3D Block3D::start() const
{
    return m_start;
}

void Block3D::setStart(const QVector3D &start)
{
    m_start = start;
}

QVector3D Block3D::end()
{
    return m_end;
}

void Block3D::setEnd(const QVector3D &end)
{
    m_end = end;
}

bool Block3D::LaserState() const
{
    return m_LaserState;
}

void Block3D::setLaserState(bool LaserState)
{
    m_LaserState = LaserState;
}
