#include "classes.h"

Point::Point(int x,int y)
{
    m_x = x;
    m_y = y;
}

void Point::set_x(int x)
{
    m_x = x;
}

void Point::set_y(int y)
{
    m_y = y;
}
int Point::get_x()
{
    return m_x;
}

int Point::get_y()
{
    return m_y;
}


point Point::DisplayPoint()
{
    point t_point;

    t_point.x = get_x();
    t_point.y = get_y();
    t_point.z = 0;

    return t_point;
}
