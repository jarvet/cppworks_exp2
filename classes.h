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
    void set_x(int x);//设置x轴坐标
    void set_y(int y);//设置y轴坐标
    int get_x();//获取x轴坐标
    int get_y();//获取y轴坐标
    virtual point DisplayPoint();//用于输出点的信息
protected:
    int m_x,m_y;
};

class Point3D:public Point
{
public:
    Point3D(int x=0,int y=0,int z=0);
    void set_z(int z);//设置z轴坐标
    int get_z();//获取z轴坐标
    virtual point DisplayPoint();//用于输出点的信息
protected:
    int m_z;
};

class Curve3D
{
public:
    Curve3D(int maxn=1000);//默认构造最多1000个点
    ~Curve3D();
    void DisplayCurve();//用于输出各点信息
    double CurveLen();//计算并输出折线长度

    //重载运算符
    Curve3D operator+(Point3D t_point) const;//将一个Point3D点增加到折线点序列中
    Curve3D operator-(Point3D t_point) const;//将一个Poin3D点从折线序列中删除
    Curve3D& operator=(const Curve3D& t_curve);//浅拷贝

    void write_txt(ofstream &os);//将折线数据写入文本文件
    void read_txt(ifstream &is);//从文本文件读入折线数据
    void write_binary(ofstream &os);//将折线数据写入二进制文件
    void read_binary(ifstream &is);//从二进制文件读入折线数据
private:
    int m_num;//记录已有点的数量
    int m_maxn;//点的数量的上限
    Point3D *m_pt;//Point3D指针，用于申请动态内存
};
