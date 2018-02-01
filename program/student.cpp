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
		cout<<"studata.dat文件打开错误";
		exit(0);
	}
	cout<<"输入学生的学号：";
	cin>>stu.number;
	cout<<"输入学生的姓名：";
	cin>>stu.name;
	cout<<"输入学生的性别：";
	cin>>stu.gender; 
	cout<<"输入学生的电话号码：";
	cin>>stu.phone;
	cout<<"输入学生的地址：";
	cin>>stu.address;
	cout<<"输入学生的绩点：";
	cin>>stu.point;
	cout<<"输入学生目前所处状态（正常，转班、转校、休学、复学、留级、退学）：";
	cin>>stu.state;
	cout<<"输入学生的奖罚情况：";
	cin>>stu.other;
	file.write((char*)&stu,sizeof(stu)) ;
	file.clear();
	file.close();
}
