#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class Society
{
	int fno,ml;
	char name[30],mobile[15];
	public:
		void getData()
		{
			cout<<"\nEnter a float no.:";
			cin>>fno;
			cout<<"\nEnter a Name:";
			cin>>name;
			cout<<"\nHow many family members Family members:";
			cin>>ml;
			cout<<"\nEnter a mobile no.:";
			cin>>mobile;
		}
		void putData()
		{
			cout<<"\n"<<fno<<"\t"<<name<<"\t"<<ml<<"\t"<<mobile;
		}
		int retfn()
		{
			return fno;
		}
};
int main()
{
	Society s;
	ifstream fin;
	ofstream fout;
	int ch,fn,f;
	do
	{
		system("cls");
		cout<<"$$$$ MENU $$$$";
		cout<<"\n1.Add Member in society ";
		cout<<"\n2.view all Members";
		cout<<"\n3.Search Member";
		cout<<"\n4.Leave society";
		cout<<"\n5.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		
		if(ch==1)
		{
			fout.open("Society.bin",ios::app|ios::binary);
			s.getData();
			fout.write((char*)&s,sizeof(s));
			fout.close();
			cout<<"\nMember added in society";
		}
		else
		 if(ch==2)
		{
			fin.open("Society.bin",ios::binary);
			
			if(fin==0)
			{
				cout<<"\nRecord not found";
				break;
			}
				cout<<"\nFlot_no\tName\tMembers\tPhone";
				while(1)
				{
					fin.read((char*)&s,sizeof(s));
					
					if(fin.eof())
					   break;
					
					s.putData();
				}
			  
			fin.close();
		}
		else
		 if(ch==3)
		{
			fin.open("Society.bin",ios::binary);
			
			if(fin==0)
			{
				cout<<"\nRecord not found";
				break;
			}
			  	cout<<"\nEnter a flot no. to search";
				cin>>fn;
				f=0;
				while(1)
				{
					fin.read((char*)&s,sizeof(s));
					
					if(fin.eof())
					  break;
					  
					if(fn==s.retfn())
					{
						cout<<"\nFlot_no\tName\tMembers\tPhone";
						s.putData();
						f=1;
					}
			    }
			    if(f==0)
			      cout<<"\nFlot not found";
		}
		else
		 if(ch==4)
		 {
		 	fin.open("Society.bin",ios::binary);
		 	if(fin==0)
		 	{
		 		cout<<"\nRecord not found";
		 		break;
			}
			 	cout<<"\nEnter a Float no.:";
		 		cin>>fn;
		 		f=0;
		 		fout.open("Temps.bin",ios::app|ios::binary);
		 		
		 		while(1)
		 		{
		 			fin.read((char*)&s,sizeof(s));
		 			
		 			if(fin.eof())
		 			  break;
		 			  
		 			if(fn==s.retfn())
		 			{
		 				f=1;
					}
					else
					{
						fout.write((char*)&s,sizeof(s));
					}
				}
				if(f==1)
				{
					cout<<"\nLeave Sucsessfully";
				}
				else
				{
					cout<<"\nFloat no. not found";
				}
			 
			  
			fin.close();
			fout.close();
			
			remove("Society.bin");
			rename("Temps.bin","Society.bin");
			
		 }
		 else
		  if(ch==5)
		 {
		 	cout<<"\nThank you!";
		 }
		 else
		   cout<<"\nInvalid choice";
		   
		getch();
	}while(ch!=5);
	
	cout<<"\nDevelop by Shubham Sontakke";
	cout<<"\nEmail : 85prasadjain@gmail.com";
	getch();
	return 0;
}
