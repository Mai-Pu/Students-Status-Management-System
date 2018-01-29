#ifndef STUDENT_H
#define STUDENT_H
struct info
{
    char number[10];
	char name[21];
	char phone[12];
	char gender[5];//性别 
	char address[40];
	float point;//绩点 
	char state[10];//状态，转班、转校、休学、复学、留级、退学
	char other[100];// 奖惩管理	
};
class student
{
	protected:
		info stu;
	public:
		void setdata();
};
#endif

