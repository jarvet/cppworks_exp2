#include "classes.h"

Curve3D::Curve3D(int maxn)
{
    m_pt = new Point3D[maxn];
    m_maxn=maxn;
    m_num=1;
    m_pt[0].set_x(0);
    m_pt[0].set_y(0);
    m_pt[0].set_z(0);
}

Curve3D::~Curve3D()
{
    if (NULL != m_pt)
        delete []m_pt;
}
