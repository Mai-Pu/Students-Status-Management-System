#include<iostream>
using namespace std;
#include"student.h"
#include<fstream>
#include<stdlib.h>
void student::setdata()
{
	fstream file;
	file.open("studata.dat",ios::out|ios::app|ios::binary);
	if(file.fail())
	{
		cout<<"studata.dat�ļ��򿪴���";
		exit(0);
	}
	cout<<"����ѧ����ѧ�ţ�";
	cin>>stu.number;
	cout<<"����ѧ����������";
	cin>>stu.name;
	cout<<"����ѧ�����Ա�";
	cin>>stu.gender; 
	cout<<"����ѧ���ĵ绰���룺";
	cin>>stu.phone;
	cout<<"����ѧ���ĵ�ַ��";
	cin>>stu.address;
	cout<<"����ѧ���ļ��㣺";
	cin>>stu.point;
	cout<<"����ѧ��Ŀǰ����״̬��������ת�ࡢתУ����ѧ����ѧ����������ѧ����";
	cin>>stu.state;
	cout<<"����ѧ���Ľ��������";
	cin>>stu.other;
	file.write((char*)&stu,sizeof(stu)) ;
	file.clear();
	file.close();
}
