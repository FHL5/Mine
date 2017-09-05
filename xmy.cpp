/*ѧ����Ϣ����
����Ҫ��
����ѧ����student���࣬�������ٰ����������Ա�ѧ�š��༶����ϵ�绰��
����Ҫ��
              1����Ʋ˵�ʵ�ֹ���ѡ��      
              2�����빦�ܣ�����ѧ����Ϣ�������浽�ļ��У�
              3���ܰ���ѧ����ѧ������
              4���ܸ���ѧ���޸�ѧ����Ϣ
              5���ܸ���ѧ��ɾ��ѧ����Ϣ
              6����ѯ���ܣ�
                    1���ܹ�����ѧ�Ų�ѯѧ����Ϣ��
                    2���ܹ�����������ѧ�š��༶�Ȳ�ѯѧ����Ϣ
	                3�����հ༶ͳ��ѧ��������*/
					
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void show()
{
	cout<<"1.����ѧ����Ϣ"<<endl;
	cout<<"2.����ѧ������"<<endl;
	cout<<"3.�޸�ѧ����Ϣ"<<endl;
	cout<<"4.ɾ��ѧ����Ϣ"<<endl;
	cout<<"5.��ѯѧ����Ϣ"<<endl;
	cout<<"6.ͳ�ư༶����"<<endl; 
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
	cout<<"��������Ҫ�����ѧ��������"; 
	int n;
	cin>>n;
	Student *ps=new Student [n];
	cout<<"�����������������Ա�ѧ�š��༶����ϵ�绰���ո�ָ���:"<<endl;
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
	
	cout<<"�������ѧ����ѧ�ţ�"; 
	int num;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		int t;
		if(ps[i].get_num()==num) 
		{
			cout<<"��ѧ�����������Ա�ѧ�š��༶����ϵ�绰Ϊ��"<<endl;
			ps[i].get_student(); 
			t=i;
			cout<<"������Ҫ�޸ĵ�ѧ����Ϣ�� �������Ա�ѧ�š��༶����ϵ�绰 <�ո�ָ�> ����"<<endl; 
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
	
	cout<<"�������ѧ����ѧ�ţ�"; 
	int num;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		if(ps[i].get_num()==num) 
		{
			cout<<"��ѧ�����������Ա�ѧ�š��༶����ϵ�绰Ϊ��"<<endl;
			ps[i].get_student(); 
			ps[i]=ps[i+1];
		}
	}
	cout<<"ɾ���ɹ���"<<endl; 
	
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
	
	cout<<"�������ѧ����������"; 
	char name[20];
	cin>>name;
	for(int i=0;i<n;i++)
	{
		if(strcmp(ps[i].get_name(), name)==0) 
		{
			cout<<"��ѧ�����������Ա�ѧ�š��༶����ϵ�绰Ϊ��"<<endl;
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
	
	cout<<"�������ѧ����ѧ�ţ�"; 
	int num;
	cin>>num;
	for(int i=0;i<n;i++)
	{
		if(ps[i].get_num()==num) 
		{
			cout<<"��ѧ�����������Ա�ѧ�š��༶����ϵ�绰Ϊ��"<<endl;
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
	
	cout<<"��������Ҫ��ѯ�İ༶��"; 
	int nclass;
	cin>>nclass;
	cout<<"�ð�ѧ�����������Ա�ѧ�š��༶����ϵ�绰Ϊ��"<<endl;
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
	
	cout<<"��������Ҫͳ�Ƶİ༶��"; 
	int nclass;
	cin>>nclass;
	cout<<"�ð�ѧ�����������Ա�ѧ�š��༶����ϵ�绰Ϊ��"<<endl;
	int t=0;
	for(int i=0;i<n;i++)
	{ 
		if(ps[i].get_class()==nclass) 
		{	
			ps[i].get_student(); 
			t++;
		}
	}
	cout<<"�ð�������Ϊ��"<<t<<endl; 
	
	delete [] ps;	
}
 
int menu()
{
	putchar(10);
	int n;
	cout<<"������Ҫִ�е����1~6����"; 
	cin>>n;
	switch(n)
	{
		case 1: input();return menu();
		case 2:	rank();return menu();
		case 3: change();return menu();
		case 4: remove();return menu();
		case 5:
		{
			cout<<"1.��������ѯ"<<endl;
			cout<<"2.��ѧ�Ų�ѯ"<<endl;
			cout<<"3.���༶��ѯ"<<endl; 
			int t;
			cout<<"������Ҫִ�е����1~3����";
			cin>>t; 
			switch(t)
			{
				case 1: search_name();break;
				case 2: search_num();break;
				case 3: search_class();break;
				default: cout<<"�������"<<endl;break;
			};return menu();
		}
		case 6: class_number();return menu();
		default:cout<<"�������"<<endl;break;	
	}
}
 
int main()
{
	show();
	menu();
	return 0;
}
