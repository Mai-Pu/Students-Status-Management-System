#ifndef SHOW_H
#define SHOW_H
#include"student.h"
class show:public student
{
	public:
		void seeknum(char*);//按学号寻找 
		void showall();//显示所有信息 
		void seekname(char*);//按姓名寻找
		void showpoturn();//按绩点顺序输出 
	    void shownumturn();//按学号顺序输出 
	    void numturn();//按学号顺序排序但不输出 
	    void change();//更改信息 
		void otherinput();//奖罚信息录入 
		void deleteone();//删除一人信息
		void deleteall();//删除全部信息 
};
#endif

