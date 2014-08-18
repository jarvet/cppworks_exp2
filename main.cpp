#include <iostream>
#include <fstream>
#include <iomanip>
#include "classes.h"
#define in_txt_name "itxt.txt"
#define out_txt_name "otxt.txt"
#define in_bin_name "ibin.bin"
#define out_bin_name "obin.bin"

using namespace std;

int main()
{
    int func;//选择功能
    int t_x,t_y,t_z;//读入坐标用
    bool flag=true;

    ifstream is;
    ofstream os;

    Curve3D curve;//曲线
    Point3D temp;//用于临时操作的点

    while (flag)
    {
        cout<<"选择功能："<<endl;
        cout<<"1.键盘加入一个点"<<endl;
        cout<<"2.键盘删除一个点"<<endl;
        cout<<"3.文本文件读入折线数据(允许折线交叉)"<<endl;
        cout<<"4.文本文件输出折线数据"<<endl;
        cout<<"5.二进制文件读入折线数据(允许折线交叉)"<<endl;
        cout<<"6.二进制文件输出折线数据"<<endl;
        cout<<"7.屏幕输出折线数据"<<endl;
        cout<<"8.计算当前折线长度"<<endl;
        cout<<"9.退出程序"<<endl;
        cin>>func;

        switch (func)
        {
        case 1://键盘加入一个点
            cout<<"输入格式：x(空格)y(空格)z"<<endl;
            cin>>t_x>>t_y>>t_z;
            temp.set_x(t_x);
            temp.set_y(t_y);
            temp.set_z(t_z);
            curve = curve + temp;
            break;

        case 2://键盘删除一个点
            cout<<"输入格式：x(空格)y(空格)z"<<endl;
            cin>>t_x>>t_y>>t_z;
            temp.set_x(t_x);
            temp.set_y(t_y);
            temp.set_z(t_z);
            curve = curve - temp;
            break;

        case 3://文本文件读入折线数据
            is.open(in_txt_name);
            curve.read_txt(is);
            is.close();
            break;

        case 4://文本文件输出折线数据
            os.open(out_txt_name);
            curve.write_txt(os);
            os.close();
            break;

        case 5://二进制文件读入折线数据
            is.open(in_bin_name,ios::binary|ios::in);
            curve.read_binary(is);
            is.close();
            break;

        case 6://二进制文件输出折线数据
            os.open(out_bin_name,ios::binary|ios::out);
            curve.write_binary(os);
            os.close();
            break;

        case 7://屏幕输出折线数据
            curve.DisplayCurve();
            break;

        case 8://计算当前折线长度
            cout<<"当前折线长度为："<<fixed<<setprecision(2)<<curve.CurveLen()<<endl;
            break;

        case 9://退出
            flag = false;
            break;
        }
    }


    return 0;
}
