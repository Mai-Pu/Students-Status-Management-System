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
		cout<<"********ѧ��ѧ������ϵͳ**********"<<endl;
		cout<<"��1��ѧ������¼��"<<endl;
		cout<<"��2������ѧ�Ų��������Ϣ"<<endl;
		cout<<"��3�������������������Ϣ"<<endl;
		cout<<"��4����ѧ������ȫ��ѧ��"<<endl;
		cout<<"��5�����ȫ��ѧ��"<<endl;
		cout<<"��6��ֱ�Ӱ�����˳�����ȫ����Ϣ"<<endl;
		cout<<"��7��ֱ�Ӱ�ѧ��˳�����ȫ����Ϣ"<<endl;
		cout<<"��8��ͨ��ѧ�Ÿ���ѧ����Ϣ"<<endl;
		cout<<"��9��������Ϣ¼��"<<endl;
		cout<<"��10��ɾ��һѧ����Ϣ"<<endl;
		cout<<"��11��ɾ��ȫ��ѧ����Ϣ"<<endl;
		cout<<"��12���˳�����"<<endl;
		cout<<"*********************************"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				studshow.setdata();
				break;
			case 2:
				cout<<"����ѧ�ţ�";
				cin>>a;
				studshow.seeknum(a);
				break;
			case 3:
				cout<<"����������";
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
