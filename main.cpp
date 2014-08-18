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
    int func;//ѡ����
    int t_x,t_y,t_z;//����������
    bool flag=true;

    ifstream is;
    ofstream os;

    Curve3D curve;//����
    Point3D temp;//������ʱ�����ĵ�

    while (flag)
    {
        cout<<"ѡ���ܣ�"<<endl;
        cout<<"1.���̼���һ����"<<endl;
        cout<<"2.����ɾ��һ����"<<endl;
        cout<<"3.�ı��ļ�������������(�������߽���)"<<endl;
        cout<<"4.�ı��ļ������������"<<endl;
        cout<<"5.�������ļ�������������(�������߽���)"<<endl;
        cout<<"6.�������ļ������������"<<endl;
        cout<<"7.��Ļ�����������"<<endl;
        cout<<"8.���㵱ǰ���߳���"<<endl;
        cout<<"9.�˳�����"<<endl;
        cin>>func;

        switch (func)
        {
        case 1://���̼���һ����
            cout<<"�����ʽ��x(�ո�)y(�ո�)z"<<endl;
            cin>>t_x>>t_y>>t_z;
            temp.set_x(t_x);
            temp.set_y(t_y);
            temp.set_z(t_z);
            curve = curve + temp;
            break;

        case 2://����ɾ��һ����
            cout<<"�����ʽ��x(�ո�)y(�ո�)z"<<endl;
            cin>>t_x>>t_y>>t_z;
            temp.set_x(t_x);
            temp.set_y(t_y);
            temp.set_z(t_z);
            curve = curve - temp;
            break;

        case 3://�ı��ļ�������������
            is.open(in_txt_name);
            curve.read_txt(is);
            is.close();
            break;

        case 4://�ı��ļ������������
            os.open(out_txt_name);
            curve.write_txt(os);
            os.close();
            break;

        case 5://�������ļ�������������
            is.open(in_bin_name,ios::binary|ios::in);
            curve.read_binary(is);
            is.close();
            break;

        case 6://�������ļ������������
            os.open(out_bin_name,ios::binary|ios::out);
            curve.write_binary(os);
            os.close();
            break;

        case 7://��Ļ�����������
            curve.DisplayCurve();
            break;

        case 8://���㵱ǰ���߳���
            cout<<"��ǰ���߳���Ϊ��"<<fixed<<setprecision(2)<<curve.CurveLen()<<endl;
            break;

        case 9://�˳�
            flag = false;
            break;
        }
    }


    return 0;
}
