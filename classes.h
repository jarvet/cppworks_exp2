#include <iostream>
#include <fstream>

using namespace std;

struct point
{
    int x,y,z;
};

class Point
{
public:
    Point(int x=0,int y=0);
    void set_x(int x);//����x������
    void set_y(int y);//����y������
    int get_x();//��ȡx������
    int get_y();//��ȡy������
    virtual point DisplayPoint();//������������Ϣ
protected:
    int m_x,m_y;
};

class Point3D:public Point
{
public:
    Point3D(int x=0,int y=0,int z=0);
    void set_z(int z);//����z������
    int get_z();//��ȡz������
    virtual point DisplayPoint();//������������Ϣ
protected:
    int m_z;
};

class Curve3D
{
public:
    Curve3D(int maxn=1000);//Ĭ�Ϲ������1000����
    ~Curve3D();
    void DisplayCurve();//�������������Ϣ
    double CurveLen();//���㲢������߳���

    //���������
    Curve3D operator+(Point3D t_point) const;//��һ��Point3D�����ӵ����ߵ�������
    Curve3D operator-(Point3D t_point) const;//��һ��Poin3D�������������ɾ��
    Curve3D& operator=(const Curve3D& t_curve);//ǳ����

    void write_txt(ofstream &os);//����������д���ı��ļ�
    void read_txt(ifstream &is);//���ı��ļ�������������
    void write_binary(ofstream &os);//����������д��������ļ�
    void read_binary(ifstream &is);//�Ӷ������ļ�������������
private:
    int m_num;//��¼���е������
    int m_maxn;//�������������
    Point3D *m_pt;//Point3Dָ�룬�������붯̬�ڴ�
};
