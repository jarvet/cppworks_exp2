#include "classes.h"
#include <stdio.h>
#include <math.h>
using namespace std;
Curve3D::Curve3D(int maxn)
{
    m_pt = new Point3D[maxn];
    m_num = 1;
    m_maxn = maxn;

    //折线默认包含点（0,0,0）
    m_pt[0].set_x(0);
    m_pt[0].set_y(0);
    m_pt[0].set_z(0);
}

Curve3D::~Curve3D()
{
    if (NULL!=m_pt)
        delete []m_pt;
}

/*
功能:输出点的坐标信息
*/
void Curve3D::DisplayCurve()
{
    cout << "折线各点坐标为："<<endl;
    for (int i=0; i<m_num; i++)
        cout<<"("<<m_pt[i].get_x()<<","<<m_pt[i].get_y()<<","<<m_pt[i].get_z()<<")"<<endl;

}


inline double cal(point a, point b)//计算两点间距离
{
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2) + pow(a.z-b.z,2));
}
/*
功能:计算折线总长度
返回值:总长度
*/
double Curve3D::CurveLen()
{
    double t_len=0;
    for (int i=1; i<m_num; i++)//枚举各点与其相邻点计算并累加
    {
       t_len += cal(m_pt[i-1].Point3D::DisplayPoint(), m_pt[i].Point3D::DisplayPoint());

    }
    return t_len;
}

/*
功能：重载运算符+，可以将一个Point3D点增加到折线点序列中（表示将折线延长到改点处）
参数：Point3D类t_point：要加入的点
返回值：Curve3D类temp，包含加入新的点后的新折线信息
*/
Curve3D Curve3D::operator+(Point3D t_point) const
{
    Curve3D temp;


    for (int i=0; i<m_num; i++)//复制已有点
    {
        temp.m_pt[i].set_x(m_pt[i].get_x());
        temp.m_pt[i].set_y(m_pt[i].get_y());
        temp.m_pt[i].set_z(m_pt[i].get_z());
    }

    if (temp.m_num>=m_maxn-1)//若已达到点数上限则不做操作退出
    {
        cout<<"!!!!!已超过能加入点的最大数量，将不做改变!!!!!"<<endl;
        return temp;
    }

    //设置新点坐标
    temp.m_pt[m_num].set_x(t_point.get_x());
    temp.m_pt[m_num].set_y(t_point.get_y());
    temp.m_pt[m_num].set_z(t_point.get_z());
    temp.m_num = m_num + 1;
    temp.m_maxn = m_maxn;

    return temp;
}

/*
功能：重载运算符-，可以将一个Point3D点从折线点序列中删除（先在点序列中搜索，如果有要删除的点，就删除，如果没有，返回即可）；
参数：Point3D类t_point，要搜索并删除的点
返回值：Curve3D类temp，包含加入新的点后的新折线信息
*/
Curve3D Curve3D::operator-(Point3D t_point) const
{
    Curve3D temp;

    for (int i=0; i<m_num; i++)
    {
        if ( t_point.get_x()==m_pt[i].get_x()
            && t_point.get_y()==m_pt[i].get_y()
            && t_point.get_z()==m_pt[i].get_z())
        {//若找到要该点则进行删除

            for (int j=0; j<i; j++)//将该点之前的点依次复制
            {
                temp.m_pt[j].set_x(m_pt[j].get_x());
                temp.m_pt[j].set_y(m_pt[j].get_y());
                temp.m_pt[j].set_z(m_pt[j].get_z());
            }
            for (int j=i; j<m_num-1; j++)//将后面的点依次向前覆盖
            {
                temp.m_pt[j].set_x(m_pt[j+1].get_x());
                temp.m_pt[j].set_y(m_pt[j+1].get_y());
                temp.m_pt[j].set_z(m_pt[j+1].get_z());
            }
            temp.m_num = m_num - 1;//个数减1
            temp.m_maxn = m_maxn;
            break;
        }
    }
    return temp;
}

/*
功能：重载运算符=，用于浅拷贝
参数：被复制的曲线
返回值：复制的曲线
*/
Curve3D& Curve3D::operator=(const Curve3D& t_curve)
{
    if (this == &t_curve)//如果对象相同，返回this即可
        return *this;

    //进行复制
    this->m_num = t_curve.m_num;
    this->m_maxn = t_curve.m_maxn;
    for (int i=0; i<this->m_num; i++)
    {
        this->m_pt[i].set_x(t_curve.m_pt[i].get_x());
        this->m_pt[i].set_y(t_curve.m_pt[i].get_y());
        this->m_pt[i].set_z(t_curve.m_pt[i].get_z());
    }
    return *this;
}

/*输出文本文件*/
void Curve3D::write_txt(ofstream &os)
{
    for (int i=0; i<m_num; i++)
        os<<m_pt[i].get_x()<<" "<<m_pt[i].get_y()<<" "<<m_pt[i].get_z()<<endl;
}

/*输入文本文件*/
void Curve3D::read_txt(ifstream &is)
{
    int x,y,z;
    while (!is.eof())
    {

        if (m_num>=m_maxn-1)//若超过最大数量则停止输入并返回
        {
            cout<<"!!!!!已超过能加入点的最大数量，将不做改变!!!!!"<<endl;
            return;
        }
        //读入并设置新加入的点
        is>>x>>y>>z;
        m_pt[m_num].set_x(x);
        m_pt[m_num].set_y(y);
        m_pt[m_num].set_z(z);
        m_num++;
    }
}

/*输出二进制文件*/
void Curve3D::write_binary(ofstream &os)
{
    point temp;
    for (int i=0; i<m_num; i++)
    {
        temp = m_pt[i].Point3D::DisplayPoint();
        os.write((char *)(&temp),sizeof(point));//将数据以点的结构体point的形式输出到文件
    }
}

/*读入二进制文件*/
void Curve3D::read_binary(ifstream &is)
{
    point temp;
    while (!is.eof())
    {
        if (m_num>=m_maxn-1)//若超过最大数量则停止输入并返回
        {
            cout<<"!!!!!已超过能加入点的最大数量，将不做改变!!!!!"<<endl;
            return;
        }
        is.read((char *)&temp,sizeof(point));//相对应的，将数据以点的结构体point的形式从文件读入
        m_pt[m_num].set_x(temp.x);
        m_pt[m_num].set_y(temp.y);
        m_pt[m_num].set_z(temp.z);
        m_num++;
    }
}
