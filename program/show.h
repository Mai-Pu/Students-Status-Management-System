#ifndef SHOW_H
#define SHOW_H
#include"student.h"
class show:public student
{
	public:
		void seeknum(char*);//��ѧ��Ѱ�� 
		void showall();//��ʾ������Ϣ 
		void seekname(char*);//������Ѱ��
		void showpoturn();//������˳����� 
	    void shownumturn();//��ѧ��˳����� 
	    void numturn();//��ѧ��˳�����򵫲���� 
	    void change();//������Ϣ 
		void otherinput();//������Ϣ¼�� 
		void deleteone();//ɾ��һ����Ϣ
		void deleteall();//ɾ��ȫ����Ϣ 
};
#endif

