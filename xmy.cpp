/*学生信息管理
基本要求：
定义学生（student）类，其中至少包括姓名、性别、学号、班级和联系电话。
功能要求：
              1、设计菜单实现功能选择；      
              2、输入功能：输入学生信息，并保存到文件中；
              3、能按照学生的学号排序
              4、能根据学号修改学生信息
              5、能根据学号删除学生信息
              6、查询功能：
                    1）能够根据学号查询学生信息；
                    2）能够根据姓名、学号、班级等查询学生信息
	                3）按照班级统计学生人数。*/
					
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void show()
{
	cout<<"1.输入学生信息"<<endl;
	cout<<"2.按照学号排序"<<endl;
	cout<<"3.修改学生信息"<<endl;
	cout<<"4.删除学生信息"<<endl;
	cout<<"5.查询学生信息"<<endl;
	cout<<"6.统计班级人数"<<endl; 
}

class Student
{
public:
	Student(char *con_name="0", char *con_sex="0", int con_num=0, int con_class=0, char *con_tel="0")
	{
		strcpy(m_name,con_name);
		strcpy(m_sex,con_sex);
		strcpy(m_tel,con_tel);
		m_num=con_num;
		m_class=con_class;
	}
	
	
	void set_student()
	{
		cin>>m_name>>m_sex>>m_num>>m_class>>m_tel;
	} 
	
	void get_student()
	{
		cout<<m_name<<" "<<m_sex<<" "<<m_num<<" "<<m_class<<" "<<m_tel<<endl;
	}
	char* get_name()
	{
		return m_name;
	}
	int get_num()
	{
		return m_num;
	} 
	int get_class()
	{
		return m_class;
	}
	

private:
	char m_name[20];
	char m_sex[5];
	int m_num;
	int m_class;
	char m_tel[15];
}; 

void input()
{
	cout<<"请输入您要输入的学生数量："; 
	int n;
	cin>>n;
	Student *ps=new Student [n];
	cout<<"请依次输入姓名、性别、学号、班级、联系电话（空格分隔）:"<<endl;
	for(int i=0;i<n;i++)
	{
		ps[i].set_student();
	}
	
	fstream fs;
	fs.open("d:\\student.txt",ios::out | ios::app);
	for(int i=0;i<n;i++)
	{
		fs.write( (char *)&ps[i], sizeof(Student) );
	}
	fs.close();
	
	delete [] ps;  
}

void rank()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();

	for(int i=0;i<n;i++)
	{
		int max=i, j;
		for(j=i+1;j<n;j++)
			if(ps[j].get_num()<ps[i].get_num()) 
				max=j;
		Student t;
		t=ps[i];
		ps[i]=ps[max];
		ps[max]=t;
	}
	
	fs.open("d:\\student.txt",ios::out);
	fs.seekp(0);
	for(int i=0;i<n;i++)
	{
		fs.write( (char *)&ps[i], sizeof(Student) );
	}
	fs.close();
	
	delete [] ps;
}

void change()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();
	
	cout<<"请输入该学生的学号："; 
	int num;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		int t;
		if(ps[i].get_num()==num) 
		{
			cout<<"该学生的姓名、性别、学号、班级、联系电话为："<<endl;
			ps[i].get_student(); 
			t=i;
			cout<<"请输入要修改的学生信息（ 姓名、性别、学号、班级、联系电话 <空格分隔> ）："<<endl; 
			ps[t].set_student();
		}
	}
	
	fs.open("d:\\student.txt",ios::out);
	fs.seekp(0);
	for(int i=0;i<n;i++)
	{
		fs.write( (char *)&ps[i], sizeof(Student) );
	}
	fs.close();
	
	delete [] ps;
}

void remove()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();
	
	cout<<"请输入该学生的学号："; 
	int num;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		if(ps[i].get_num()==num) 
		{
			cout<<"该学生的姓名、性别、学号、班级、联系电话为："<<endl;
			ps[i].get_student(); 
			ps[i]=ps[i+1];
		}
	}
	cout<<"删除成功！"<<endl; 
	
	fs.open("d:\\student.txt",ios::out);
	fs.seekp(0);
	for(int i=0;i<n-1;i++)
	{
		fs.write( (char *)&ps[i], sizeof(Student) );
	}
	fs.close();
	
	delete [] ps;
}

void search_name()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();
	
	cout<<"请输入该学生的姓名："; 
	char name[20];
	cin>>name;
	for(int i=0;i<n;i++)
	{
		if(strcmp(ps[i].get_name(), name)==0) 
		{
			cout<<"该学生的姓名、性别、学号、班级、联系电话为："<<endl;
			ps[i].get_student(); 
		}
	}
	
	delete [] ps;
}

void search_num()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();
	
	cout<<"请输入该学生的学号："; 
	int num;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		if(ps[i].get_num()==num) 
		{
			cout<<"该学生的姓名、性别、学号、班级、联系电话为："<<endl;
			ps[i].get_student(); 
		}
	}
	
	delete [] ps;
}

void search_class()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();
	
	cout<<"请输入您要查询的班级："; 
	int nclass;
	cin>>nclass;
	cout<<"该班学生的姓名、性别、学号、班级、联系电话为："<<endl;
	for(int i=0;i<n;i++)
	{
		if(ps[i].get_class()==nclass) 
		{	
			ps[i].get_student(); 
		}
	}
	
	delete [] ps;
}

void class_number()
{
	fstream fs;
	fs.open("d:\\student.txt",ios::in);
	fs.seekg(0,ios::end);
	int size=fs.tellg();
	int n=size/sizeof(Student);
	Student *ps=new Student [n];
	fs.seekg(0,ios::beg);
	for(int i=0;i<n;i++)
	{
		fs.read( (char *)&ps[i], sizeof(Student) );
		//ps[i].get_student();
	}
	fs.close();
	
	cout<<"请输入您要统计的班级："; 
	int nclass;
	cin>>nclass;
	cout<<"该班学生的姓名、性别、学号、班级、联系电话为："<<endl;
	int t=0;
	for(int i=0;i<n;i++)
	{ 
		if(ps[i].get_class()==nclass) 
		{	
			ps[i].get_student(); 
			t++;
		}
	}
	cout<<"该班总人数为："<<t<<endl; 
	
	delete [] ps;	
}
 
int menu()
{
	putchar(10);
	int n;
	cout<<"请输入要执行的命令（1~6）："; 
	cin>>n;
	switch(n)
	{
		case 1: input();return menu();
		case 2:	rank();return menu();
		case 3: change();return menu();
		case 4: remove();return menu();
		case 5:
		{
			cout<<"1.按姓名查询"<<endl;
			cout<<"2.按学号查询"<<endl;
			cout<<"3.按班级查询"<<endl; 
			int t;
			cout<<"请输入要执行的命令（1~3）：";
			cin>>t; 
			switch(t)
			{
				case 1: search_name();break;
				case 2: search_num();break;
				case 3: search_class();break;
				default: cout<<"输入错误！"<<endl;break;
			};return menu();
		}
		case 6: class_number();return menu();
		default:cout<<"输入错误！"<<endl;break;	
	}
}
 
int main()
{
	show();
	menu();
	return 0;
}
