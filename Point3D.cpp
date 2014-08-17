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

/*
功能：用于输出点3d坐标
返回值：含有点3d坐标的结构体
*/
point Point3D::DisplayPoint()
{
    point t_point;

    t_point.x = get_x();
    t_point.y = get_y();
    t_point.z = get_z();

    return t_point;
}
