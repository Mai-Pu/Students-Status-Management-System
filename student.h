#ifndef STUDENT_H
#define STUDENT_H
struct info
{
    char number[10];
	char name[21];
	char phone[12];
	char gender[5];//�Ա� 
	char address[40];
	float point;//���� 
	char state[10];//״̬��ת�ࡢתУ����ѧ����ѧ����������ѧ
	char other[100];// ���͹���	
};
class student
{
	protected:
		info stu;
	public:
		void setdata();
};
#endif

