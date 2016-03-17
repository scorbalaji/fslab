#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;
class student
{
public:
	string sem,usn,name,branch,buffer;
	int count,rrn_list[100];
	void read();
	void pack();
	void write();
	void unpack();
	void create_rrn();
	void insert();
	void search(int rrn);
};
void student::read()
{
	cout<<"usn";
	cin>>usn;
	cout<<"name";
	cin>>name;
	cout<<"branch";
	cin>>branch;
	cout<<"semester";
	cin>>sem;
}
void student::pack()
{
	string sem;
	stringstream out;
	buffer.erase();
	buffer=usn +'|'+name+'|'+branch+'|'+sem+'$'+'\n';
}
void student::write()
{
int pos;
fstream file;
count=0;
file.open("4.txt",ios::out|ios::app);
pos=file.tellp();
file<<buffer;
file.close();
rrn_list[++count]=pos;
}
void student::create_rrn()
{
	fstream file;
	int pos;
	count=0;
	file.open("4.txt",ios::in);
	while(!file.eof())
	{
		pos=file.tellg();
		//buffer.erase();
		getline(file,buffer);
		if(buffer.empty())
			continue;
		rrn_list[++count]=pos;

	}
	file.close();
}
void student::search(int rrn)
{
	int pos=1;
	fstream file;
	if(rrn>count)
	cout<<"record not found \n";
		else
		{
			buffer.erase();
			file.open("4.txt");
			pos=rrn_list[rrn];
			file.seekp(pos,ios::beg);
			getline(file,buffer);
			cout<<"buffer is:"<<buffer;

		}
}
int main()
{
	int ch,rrn;
	student s;
	//s.create_rrn();
	while(1)
	{
		cout<<"\n 1.add 2.search 3.enter \n enter your choice \n";
		cin>>ch;
		switch(ch)
		{
		case 1: cout<<"enter date \n";
		s.read();
		s.pack();
		s.write();
		break;
		case 2: cout<<"enter the rrn \n";
		cin>>rrn;
		s.search(rrn);
		break;
		//default:exit(0);

			}
}
}



