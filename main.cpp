#include<iostream>
using namespace std;
#include"student.h"
#include"show.h"
#include<stdlib.h>
int main()
{
	int choice,i=1;
	show studshow;
	char*a;
	while(i)
	{
		cout<<"********学生学籍管理系统**********"<<endl;
		cout<<"【1】学生数据录入"<<endl;
		cout<<"【2】输入学号查找相关信息"<<endl;
		cout<<"【3】输入姓名查找相关信息"<<endl;
		cout<<"【4】按学号排列全部学生"<<endl;
		cout<<"【5】输出全部学生"<<endl;
		cout<<"【6】直接按绩点顺序输出全部信息"<<endl;
		cout<<"【7】直接按学号顺序输出全部信息"<<endl;
		cout<<"【8】通过学号更改学生信息"<<endl;
		cout<<"【9】奖罚信息录入"<<endl;
		cout<<"【10】删除一学生信息"<<endl;
		cout<<"【11】删除全部学生信息"<<endl;
		cout<<"【12】退出程序"<<endl;
		cout<<"*********************************"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				studshow.setdata();
				break;
			case 2:
				cout<<"输入学号：";
				cin>>a;
				studshow.seeknum(a);
				break;
			case 3:
				cout<<"输入姓名：";
				cin>>a;
				studshow.seekname(a);
				break;
			case 4:
				studshow.numturn();
				break;
			case 5:
				studshow.showall();
				break;
			case 6:
				studshow.showpoturn();
				break;
			case 7:
			    studshow.shownumturn(); 
			    break;
			case 8:
				studshow.change();
				break;
			case 9:
				studshow.otherinput();
				break;
			case 10:
                studshow.deleteone();
                break;
            case 11:
		        studshow.deleteall();
		        break;
		    case 12:
		    	i=0;			
		}
	}
	return 0;
}
