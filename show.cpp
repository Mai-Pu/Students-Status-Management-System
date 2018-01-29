#include<iostream>
using namespace std;
#include"show.h"
#include<fstream>
#include<stdlib.h>
#include<string.h>
void show::seeknum(char*n)//按学号寻找 
{
	fstream filenum;
	int i=1;
	filenum.open("studata.dat",ios::in|ios::binary);
	if(filenum.fail())
	{
		cout<<"studata。dat打开失败！";
		exit(0);
	}
	filenum.seekg(0L,ios::beg);
	filenum.read((char*)&stu,sizeof(stu));
	while(i)
	{	
	    while(strcmp(stu.number,n)!=0&&(!filenum.eof()))
	    {
	       filenum.read((char*)&stu,sizeof(stu));
	    }
	    if(strcmp(stu.number,n)!=0)
	    {
		   cout<<"学号输入错误，不存在此人！"<<endl;
		   cout<<"输入0停止，1继续";
		   cin>>i; 
		   if(i==1) 
		   {
		    cout<<"请重新输入学号：";
		    cin>>n;
		   }
	    }
	    if(strcmp(stu.number,n)==0)
	    {
	 	   cout<<endl;
	 	   cout<<"学号："<<stu.number<<endl;
	       cout<<"姓名："<<stu.name<<endl;
	       cout<<"性别："<<stu.gender; 
	       cout<<"电话号码："<<stu.phone<<endl;
	       cout<<"地址："<<stu.address<<endl;
	       cout<<"绩点："<<stu.point<<endl;
	       cout<<"目前所处状态："<<stu.state<<endl;
	       cout<<"奖罚情况："<<stu.other<<endl;
	       i=0;
	    }
    }
    filenum.clear();
    filenum.close();
}




void show::showall()
{
	fstream fileall;
	fileall.open("studata.dat",ios::in|ios::binary);
	if(fileall.fail())
	{
		cout<<"studata。dat打开失败！";
		exit(0);
	}
	fileall.seekg(0L,ios::beg);
	fileall.read((char*)&stu,sizeof(stu));	
	while(!fileall.eof())
	{
	 	cout<<endl;
	 	cout<<"学号："<<stu.number<<endl;
	    cout<<"姓名："<<stu.name<<endl;
	    cout<<"性别："<<stu.gender; 
	    cout<<"电话号码："<<stu.phone<<endl;
	    cout<<"地址："<<stu.address<<endl;
	    cout<<"绩点："<<stu.point<<endl;
	    cout<<"目前所处状态："<<stu.state<<endl;
	    cout<<"奖罚情况："<<stu.other<<endl;
	    fileall.read((char*)&stu,sizeof(stu));
	}
	fileall.clear();
	fileall.close();
}





void show::seekname(char*nm)//按姓名寻找
{
	fstream filename;
	int i=1;
	filename.open("studata.dat",ios::in|ios::binary);
	if(filename.fail())
	{
		cout<<"studata。dat打开失败！";
		exit(0);
	}
	filename.seekg(0L,ios::beg);
	filename.read((char*)&stu,sizeof(stu));
	while(i)
	{	
	    while(strcmp(stu.name,nm)!=0&&!filename.eof())
	    {
	       filename.read((char*)&stu,sizeof(stu));
	    }
	    if(strcmp(stu.name,nm)!=0)
	    {
		   cout<<"姓名输入错误，不存在此人！"<<endl;
		   cout<<"输入0停止，1继续";
		   cin>>i;
		   if(i==1) 
		   {
		    cout<<"请重新输入姓名：";
		    cin>>nm;
		   }
	    }
	    if(strcmp(stu.name,nm)==0)
	    {
	 	   cout<<endl;
	 	   cout<<"学号："<<stu.number<<endl;
	       cout<<"姓名："<<stu.name<<endl;
	       cout<<"性别："<<stu.gender; 
	       cout<<"电话号码："<<stu.phone<<endl;
	       cout<<"地址："<<stu.address<<endl;
	       cout<<"绩点："<<stu.point<<endl;
	       cout<<"目前所处状态："<<stu.state<<endl;
	       cout<<"奖罚情况："<<stu.other<<endl;
	       i=0;
	    }
    }
    filename.clear();
    filename.close();
}




void show::showpoturn()//按绩点从高到低顺序输出 
{
	fstream filepoturn;
	int i,j,k;
	float*pot;
	float mm;
	filepoturn.open("studata.dat",ios::in|ios::binary);
	if(filepoturn.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	}
	filepoturn.seekg(0L,ios::beg);
	for(i=0;!filepoturn.eof();i++)
	{
		filepoturn.read((char*)&stu,sizeof(stu));
	}
	filepoturn.clear();
	filepoturn.seekg(0L,ios::beg);
	i=i-1;
	if(i==0)
	{
		cout<<"暂无学生！";
		exit(0);
	}
	pot=new float[i];
	for(j=0;j<i;j++)
	{
		filepoturn.read((char*)&stu,sizeof(stu));
		pot[j]=stu.point;
	}
	for(j=0;j<i;j++)
	{
		for(k=0;k<i-j-1;k++)
		{
			if(pot[k]<pot[k+1])
			{
				mm=pot[k];
				pot[k]=pot[k+1];
				pot[k+1]=mm;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		if(pot[j]<0.0)
		{
			continue;
		}
		for(k=0;k<i;k++)
		{
			if(j!=k)
			 {
			    if(pot[j]==pot[k])
			    {
				   pot[k]=-1.0;
			    }
		     }
		} 
	}
	for(j=0;j<i;j++)
	{
	  if(pot[j]<0)
	  {
	     continue;
	  }
	  filepoturn.clear();
	  filepoturn.seekg(0L,ios::beg);
	  filepoturn.read((char*)&stu,sizeof(stu));
	  while(!filepoturn.eof())	
	  {	
	    if(stu.point==pot[j])
	    {
	 	     cout<<endl;
	 	     cout<<"学号："<<stu.number<<endl;
	         cout<<"姓名："<<stu.name<<endl;
	         cout<<"性别："<<stu.gender; 
	         cout<<"电话号码："<<stu.phone<<endl;
	         cout<<"地址："<<stu.address<<endl;
	         cout<<"绩点："<<stu.point<<endl;
	         cout<<"目前所处状态："<<stu.state<<endl;
	         cout<<"奖罚情况："<<stu.other<<endl;
	    }
	    filepoturn.read((char*)&stu,sizeof(stu));
	  }
    }
	filepoturn.clear();
	filepoturn.close();
	delete []pot;
}



void show::shownumturn()//按学号顺序输出 
{
	fstream filenumturn;
	int i,j,k;
	char**numt;
	char* mm;
	filenumturn.open("studata.dat",ios::in|ios::binary);
	if(filenumturn.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	}
	filenumturn.seekg(0L,ios::beg);
	for(i=0;!filenumturn.eof();i++)
	{
		filenumturn.read((char*)&stu,sizeof(stu));
	}
	filenumturn.clear();
	filenumturn.seekg(0L,ios::beg);
	i=i-1;
	if(i==0)
	{
		cout<<"暂无学生！";
		exit(0);
	}
	numt=new char*[i];
	for(j=0;j<i;j++)
	{
		numt[j]=new char[10];
    }
	for(j=0;j<i;j++)
	{
		filenumturn.read((char*)&stu,sizeof(stu));
		strcpy(numt[j],stu.number);
	}
	for(j=0;j<i;j++)
	{
		for(k=0;k<i-j-1;k++)
		{
			if(strcmp(numt[k],numt[k+1])>0)
			{
				strcpy(mm,numt[k]);
				strcpy(numt[k],numt[k+1]);
				strcpy(numt[k+1],mm);
			}
		}
	}
	for(j=0;j<i;j++)
	{
	    filenumturn.clear();
	    filenumturn.seekg(0L,ios::beg);
		filenumturn.read((char*)&stu,sizeof(stu));	
	    while(!filenumturn.eof())	
	    {	
	      if(strcmp(stu.number,numt[j])==0)
	      {
	 	     cout<<endl;
	 	     cout<<"学号："<<stu.number<<endl;
	         cout<<"姓名："<<stu.name<<endl;
	         cout<<"性别："<<stu.gender; 
	         cout<<"电话号码："<<stu.phone<<endl;
	         cout<<"地址："<<stu.address<<endl;
	         cout<<"绩点："<<stu.point<<endl;
	         cout<<"目前所处状态："<<stu.state<<endl;
	         cout<<"奖罚情况："<<stu.other<<endl;
	         break;
	      }
	      filenumturn.read((char*)&stu,sizeof(stu));
	    }
	
    }
	filenumturn.clear();
	filenumturn.close();
	for(j=0;j<i;j++)
	{
		delete []numt[j];
    }
	delete []numt;
}




void show::numturn()//按学号顺序排序但不输出 
{
	fstream fnumt,fnumt1;
	int i,j,k;
	info stu2;
	char**numt;
	char mm[10];
	fnumt.open("studata.dat",ios::in|ios::binary);
	fnumt1.open("studata2.dat",ios::out|ios::binary);
	if(fnumt.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	}
	if(fnumt1.fail())
	{
		cout<<"studata2.dat打开失败！";
		exit(0);
	}
	fnumt.seekg(0L,ios::beg);
	for(i=0;!fnumt.eof();i++)
	{
		fnumt.read((char*)&stu,sizeof(stu));
	}
	fnumt.clear();
	fnumt.seekg(0L,ios::beg);
	i=i-1;
	if(i==0)
	{
		cout<<"暂无学生！";
		exit(0);
	}
	numt=new char*[i];
	for(j=0;j<i;j++)
	{
		numt[j]=new char[10];
    }
	for(j=0;j<i;j++)
	{
		fnumt.read((char*)&stu,sizeof(stu));
		strcpy(numt[j],stu.number);
	}
	for(j=0;j<i-1;j++)
	{
		for(k=0;k<i-j-1;k++)
		{
			if(strcmp(numt[k],numt[k+1])>0)
			{
				strcpy(mm,numt[k]);
				strcpy(numt[k],numt[k+1]);
				strcpy(numt[k+1],mm);
			}
		}
	}
	for(j=0;j<i;j++)
	{
	    fnumt.clear();
	    fnumt.seekg(0L,ios::beg);
		fnumt.read((char*)&stu,sizeof(stu));	
	    while(!fnumt.eof())	
	    {
	      if(strcmp(stu.number,numt[j])==0)
	      {
	      	fnumt1.write((char*)&stu,sizeof(stu));
	        break;
	      }
	      fnumt.read((char*)&stu,sizeof(stu));
	    }
    }
	fnumt.clear();
	fnumt.close();
	fnumt1.close();
	fnumt.open("studata.dat",ios::out|ios::binary);
	fnumt1.open("studata2.dat",ios::in|ios::binary);
	if(fnumt.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	}
	if(fnumt1.fail())
	{
		cout<<"studata2.dat打开失败！";
		exit(0);
	}
	fnumt.seekp(0L,ios::beg);
	fnumt1.seekg(0L,ios::beg);
	fnumt1.read((char*)&stu2,sizeof(stu2));	
	while(!fnumt1.eof())
	{	
	      fnumt.write((char*)&stu2,sizeof(stu2));
		  fnumt1.read((char*)&stu2,sizeof(stu2));	
	}
	fnumt.close();
	fnumt1.close();
	for(j=0;j<i;j++)
	{
		delete []numt[j];
    }
	delete []numt;
}



void show::change()
{
	int m=1;
	char numm[10];
	long changenum;
	fstream filechange;
	filechange.open("studata.dat",ios::in|ios::out|ios::binary);
	if(filechange.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	} 
	cout<<"输入要修改的同学的学号：";
	cin>>numm;
    filechange.seekg(0L,ios::beg);
    filechange.read((char*)&stu,sizeof(stu));
	while(m!=0&&(!filechange.eof()))
	{
		if(strcmp(stu.number,numm)==0)
		{
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
	        m=0;
			changenum=filechange.tellg();
			break;	
		}
		filechange.read((char*)&stu,sizeof(stu));
	}
	if(m!=0)
	{
		cout<<"无此学生！";
		exit(0);
	}
	filechange.clear();
	filechange.seekp(changenum-sizeof(stu),ios::beg);
	filechange.write((char*)&stu,sizeof(stu));
	filechange.close();
}


void show::otherinput()//奖罚信息录入 
{
	int m=1;
	char o[10];
	char pp[100];
	long oin;
	fstream fileotherinput;
	fileotherinput.open("studata.dat",ios::in|ios::out|ios::binary);
	if(fileotherinput.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	} 
	cout<<"输入要录入的同学的学号：";
	cin>>o;
    fileotherinput.read((char*)&stu,sizeof(stu));
	while((m!=0)&&(!fileotherinput.eof()))
	{
		if(strcmp(stu.number,o)==0)
		{
	        cout<<"输入学生的奖罚情况：";
	        cin>>pp;
	        strcpy(stu.other,pp);
	        m=0;
			oin=fileotherinput.tellg();
			break;	
		}
		fileotherinput.read((char*)&stu,sizeof(stu));
	}
	if(m!=0)
	{
		cout<<"无此学生！";
		exit(0);
	}
	fileotherinput.clear();
	fileotherinput.seekp(oin-sizeof(stu),ios::beg);
	fileotherinput.write((char*)&stu,sizeof(stu));
	fileotherinput.close();
}


void show::deleteone()//删除一人信息
{
	int m=0;
	char*numm;
	info stu1;
	fstream filedelet,file1;
	filedelet.open("studata.dat",ios::in|ios::out|ios::binary);
	if(filedelet.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	}
	file1.open("studata1.dat",ios::in|ios::out|ios::binary);
	if(file1.fail())
	{
		cout<<"studata1.dat打开失败！";
		exit(0);
	}
	cout<<"输入要删除的同学的学号：";
	cin>>numm;
    filedelet.seekg(0L,ios::beg);
    filedelet.read((char*)&stu,sizeof(stu));
	while(!filedelet.eof())
	{
		stu1=stu;
		if(strcmp(stu1.number,numm)!=0)
		{
	        file1.write((char*)&stu1,sizeof(stu1));
		}
		filedelet.read((char*)&stu,sizeof(stu));
	}
	filedelet.clear();
	file1.clear();
	filedelet.close();
	filedelet.open("studata.dat",ios::out|ios::binary);
	if(filedelet.fail())
	{
		cout<<"studata.dat打开失败！";
		exit(0);
	}
	filedelet.seekp(0L,ios::beg);
	file1.seekg(0L,ios::beg);
	file1.read((char*)&stu,sizeof(stu));
	while(!file1.eof())
	{
	    filedelet.write((char*)&stu,sizeof(stu));
	    file1.read((char*)&stu,sizeof(stu));
	}
	file1.clear();
	filedelet.clear();
	file1.close();
	filedelet.close();
}



void show::deleteall()//删除全部信息 
{
	int i=-1;
	cout<<"是否删除所有学生信息，确定请按1，否则任意键继续";
	cin>>i;
	if(i==1)
	{
	  fstream filedall,file11,file22;
	  filedall.open("studata.dat",ios::out|ios::binary);
	  file11.open("studata1.dat",ios::out|ios::binary);
	  file22.open("studata2.dat",ios::out|ios::binary);
	  filedall.close();
	  file11.close();
	  file22.close();
    }
    else
       exit(0);
}
