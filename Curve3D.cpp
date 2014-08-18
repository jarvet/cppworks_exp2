#include "classes.h"
#include <stdio.h>
#include <math.h>
using namespace std;
Curve3D::Curve3D(int maxn)
{
    m_pt = new Point3D[maxn];
    m_num = 1;
    m_maxn = maxn;

    //����Ĭ�ϰ����㣨0,0,0��
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
����:������������Ϣ
*/
void Curve3D::DisplayCurve()
{
    cout << "���߸�������Ϊ��"<<endl;
    for (int i=0; i<m_num; i++)
        cout<<"("<<m_pt[i].get_x()<<","<<m_pt[i].get_y()<<","<<m_pt[i].get_z()<<")"<<endl;

}


inline double cal(point a, point b)//������������
{
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2) + pow(a.z-b.z,2));
}
/*
����:���������ܳ���
����ֵ:�ܳ���
*/
double Curve3D::CurveLen()
{
    double t_len=0;
    for (int i=1; i<m_num; i++)//ö�ٸ����������ڵ���㲢�ۼ�
    {
       t_len += cal(m_pt[i-1].Point3D::DisplayPoint(), m_pt[i].Point3D::DisplayPoint());

    }
    return t_len;
}

/*
���ܣ����������+�����Խ�һ��Point3D�����ӵ����ߵ������У���ʾ�������ӳ����ĵ㴦��
������Point3D��t_point��Ҫ����ĵ�
����ֵ��Curve3D��temp�����������µĵ�����������Ϣ
*/
Curve3D Curve3D::operator+(Point3D t_point) const
{
    Curve3D temp;


    for (int i=0; i<m_num; i++)//�������е�
    {
        temp.m_pt[i].set_x(m_pt[i].get_x());
        temp.m_pt[i].set_y(m_pt[i].get_y());
        temp.m_pt[i].set_z(m_pt[i].get_z());
    }

    if (temp.m_num>=m_maxn-1)//���Ѵﵽ�����������������˳�
    {
        cout<<"!!!!!�ѳ����ܼ���������������������ı�!!!!!"<<endl;
        return temp;
    }

    //�����µ�����
    temp.m_pt[m_num].set_x(t_point.get_x());
    temp.m_pt[m_num].set_y(t_point.get_y());
    temp.m_pt[m_num].set_z(t_point.get_z());
    temp.m_num = m_num + 1;
    temp.m_maxn = m_maxn;

    return temp;
}

/*
���ܣ����������-�����Խ�һ��Point3D������ߵ�������ɾ�������ڵ������������������Ҫɾ���ĵ㣬��ɾ�������û�У����ؼ��ɣ���
������Point3D��t_point��Ҫ������ɾ���ĵ�
����ֵ��Curve3D��temp�����������µĵ�����������Ϣ
*/
Curve3D Curve3D::operator-(Point3D t_point) const
{
    Curve3D temp;

    for (int i=0; i<m_num; i++)
    {
        if ( t_point.get_x()==m_pt[i].get_x()
            && t_point.get_y()==m_pt[i].get_y()
            && t_point.get_z()==m_pt[i].get_z())
        {//���ҵ�Ҫ�õ������ɾ��

            for (int j=0; j<i; j++)//���õ�֮ǰ�ĵ����θ���
            {
                temp.m_pt[j].set_x(m_pt[j].get_x());
                temp.m_pt[j].set_y(m_pt[j].get_y());
                temp.m_pt[j].set_z(m_pt[j].get_z());
            }
            for (int j=i; j<m_num-1; j++)//������ĵ�������ǰ����
            {
                temp.m_pt[j].set_x(m_pt[j+1].get_x());
                temp.m_pt[j].set_y(m_pt[j+1].get_y());
                temp.m_pt[j].set_z(m_pt[j+1].get_z());
            }
            temp.m_num = m_num - 1;//������1
            temp.m_maxn = m_maxn;
            break;
        }
    }
    return temp;
}

/*
���ܣ����������=������ǳ����
�����������Ƶ�����
����ֵ�����Ƶ�����
*/
Curve3D& Curve3D::operator=(const Curve3D& t_curve)
{
    if (this == &t_curve)//���������ͬ������this����
        return *this;

    //���и���
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

/*����ı��ļ�*/
void Curve3D::write_txt(ofstream &os)
{
    for (int i=0; i<m_num; i++)
        os<<m_pt[i].get_x()<<" "<<m_pt[i].get_y()<<" "<<m_pt[i].get_z()<<endl;
}

/*�����ı��ļ�*/
void Curve3D::read_txt(ifstream &is)
{
    int x,y,z;
    while (!is.eof())
    {

        if (m_num>=m_maxn-1)//���������������ֹͣ���벢����
        {
            cout<<"!!!!!�ѳ����ܼ���������������������ı�!!!!!"<<endl;
            return;
        }
        //���벢�����¼���ĵ�
        is>>x>>y>>z;
        m_pt[m_num].set_x(x);
        m_pt[m_num].set_y(y);
        m_pt[m_num].set_z(z);
        m_num++;
    }
}

/*����������ļ�*/
void Curve3D::write_binary(ofstream &os)
{
    point temp;
    for (int i=0; i<m_num; i++)
    {
        temp = m_pt[i].Point3D::DisplayPoint();
        os.write((char *)(&temp),sizeof(point));//�������Ե�Ľṹ��point����ʽ������ļ�
    }
}

/*����������ļ�*/
void Curve3D::read_binary(ifstream &is)
{
    point temp;
    while (!is.eof())
    {
        if (m_num>=m_maxn-1)//���������������ֹͣ���벢����
        {
            cout<<"!!!!!�ѳ����ܼ���������������������ı�!!!!!"<<endl;
            return;
        }
        is.read((char *)&temp,sizeof(point));//���Ӧ�ģ��������Ե�Ľṹ��point����ʽ���ļ�����
        m_pt[m_num].set_x(temp.x);
        m_pt[m_num].set_y(temp.y);
        m_pt[m_num].set_z(temp.z);
        m_num++;
    }
}
