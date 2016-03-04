 //============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<fstream>
#include<string>
#include <iostream>
#include<sstream>
using namespace std;
class student{
	string name;
	string usn;
	string branch;
	int semester;
	string buffer;
	public: void readStudentFromConsole(){
		cin.clear();
		cin.ignore(255,'\n');
		cout<<"Enter The Name\n"<<endl;
		getline(cin,name);
		cout<<"Enter The USN\n"<<endl;
		cin>>usn;
		cout<<"Enter The Branch\n"<<endl;
		cin>>branch;
		cout<<"Enter The Semester\n"<<endl;
		cin>>semester;
	}
	public: void ShowStudent(){
		cout<<"\nName\n"<<endl;
		cout<<name;
		cout<<"\nUSN\n"<<endl;
		cout<<usn;
		cout<<"\nBranch\n"<<endl;
		cout<<branch;
		cout<<"\nSemester\n"<<endl;
		cout<<semester;

	}
	public: void write()
	{
		fstream file;
		file.open("2a.txt",ios::out|ios::app);
		file<<buffer;
		file.close();
	}
	public: int search(string key)
	{
		fstream file;
		int flag=0,pos=0;
		file.open("2a.txt",ios::in);
		while(!file.eof())
		{
			buffer.erase();
			getline(file,buffer);
			unpack();
			if(key==usn)
			{
				flag=1;
				cout<<"found the record is:\n"<<buffer;
				pos=file.tellg();
				cout<<"\n pos ="<<pos;
				return pos;



			}
		}
		if(!flag)
			cout<<"record not found";
		return pos;
	}
	void unpack()
	{
		string sem;
		int ch=1,i=0;
		usn.erase();
		while(buffer[i]!='|')
			usn+=buffer[i++];
		name.erase();
		i++;
		while(buffer[i]!='|')
			name+=buffer[i++];
		branch.erase();
		i++;
		while(buffer[i]!='|')
			branch+=buffer[i++];
		sem.erase();
		i++;
		while(buffer[i]!='$')
			sem+=buffer[i++];
		stringstream out(sem);
		cout<<sem;


	}
	public: void pack(){
		string sem1,temp;
		int i,len;
		stringstream out;
		out<<semester;
		sem1 = out.str();
		temp=usn+'|'+name+'|'+branch+'|'+sem1;
		len=temp.size();
		for(i=len+1;i<100;i++)
		{
			temp +='$';
		}
		buffer=temp;
	}
	void modify(string key)
	{
		int choice;
		cout<<"want to modify ? \n 1.usn 2.name 3.branch 4.semester \n enter yout choice \n";
		cin>>choice;
		switch(choice)
		{
		case 1:cout<<"usn";
		cin>>usn;
		break;
		case 2:
			cout<<"name";
			break;
		case 3: cout<<"branch";
		cin>>branch;
		break;
		case 4: cout<<"semester";
		cin>>semester;
		break;
		default:cout<<"wrong choice";
		buffer.erase();
		pack();
		write();

		}
	}
};


int main() {
	int choice,count,len,i;
	student s;
	string key;
	cout<<"\n 1. add record \n 2. modify \n 3. search \n";
	cin>>choice;

	switch(choice)
	{
	case 1:
		cout<<"how many record"<<endl;
		cin>>count;
		for(i=0;i<count;i++)
		{
			cout<<"data";
			s.readStudentFromConsole();
			s.pack();
			s.write();
		}

		break;
	case 2:
		cout<<"enter the key \n";
		cin>>key;
		s.modify(key);
		break;
	case 3:
		cout<<"enter the usn \n";
		cin>>key;
		i=s.search(key);
		break;
	}
	return 0;
}
