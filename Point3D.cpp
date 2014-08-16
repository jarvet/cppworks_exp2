#include "classes.h"

Point3D::Point3D(int x,int y,int z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

void Point3D::set_z(int z)
{
    m_z = z;
}

int Point3D::get_z()
{
    return m_z;
}

point Point3D::DisplayPoint()
{
    point t_point;

    t_point.x = get_x();
    t_point.y = get_y();
    t_point.z = get_z();

    return t_point;
}
