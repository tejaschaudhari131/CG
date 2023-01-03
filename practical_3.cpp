#include<iostream>
#include<string.h>

using namespace std;

class publication
{
	private:
		string title;
		float prices;
	public:
	publication()
	{
		title = "";
		prices = 0;
	}
	void get_data()
	{
		cout<<"\nEnter Title:";
		cin.ignore(); //clear input buffer
		getline(cin,title);
		cout<<"\nEnter Price:";
		cin>>prices;
	}
	void put_data()
	{
		cout<<"\n ____________________________________\n";
		cout<<"\nInformation:"<<endl;
		cout<<"\nTitle:"<<title;
		cout<<"\nPrice:"<<prices;
	}
};

class book:public publication
{
	private:
		int pages;
	public:
		book()
		{
			pages=0;
		}
		void get_data()
		{
			publication::get_data();
			cout<<endl;
			cout<<"Enter Page Count:";
			cin>>pages;
		}
		void put_data()
		{
			try
			{
				if(pages==0)
					throw pages;
			}
			catch(int f)
			{
				cout<<"\nError: Pages not valid:"<<f;
				pages = 0;
			}
			cout<<"\nPages are:"<<pages;
			publication::put_data();
		}
};

class tape:public publication
{
	private:
		float playtime;
	public:
		tape()
		{
			playtime = 0.0;
		}
		void get_data()
		{
			publication::get_data();
			cout<<"Enter Playtime of Cassette:";
			cin>>playtime;
		}
		void put_data()		
		{
			try
			{
				if(playtime==0.0)
					throw playtime;
			}
			catch(float r)
			{
				cout<<"\nError: Invalid Playtime:"<<playtime;
				playtime = 0.0;
			}
			cout<<"\nPlaytime is:"<<playtime;
			publication::put_data();
		}
};	

int main()
{
	book b[10];
	tape t[10];
	int choice=0,bookCount=0,tapeCount=0;
	cout<<"\n_________________________";
	do
	{
		cout<<"\n1. Add book";
		cout<<"\n2. Add tape";
		cout<<"\n3. Display book";
		cout<<"\n4. Display tape";
		cout<<"\n5. Exit"<<endl;
		cout<<"\nEnter Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"\n____________\n";
				cout<<"Add Book:\n";
				b[bookCount].get_data();
				bookCount++;
				break;
			}
			case 2:
			{
				cout<<"\n____________\n";				
				cout<<"Add Tape:\n";
				t[tapeCount].get_data();
				tapeCount++;
				break;
			}
			case 3:
			{
				cout<<"\n (books)";
				for(int j = 0;j<bookCount;j++)
				{
					b[j].put_data();
				}
				break;
			}
			case 4:
			{
				cout<<" (tape)";
				for(int j=0; j<tapeCount;j++)
				{
					t[j].put_data();
				}
				break;
			}
			case 5:
			{
				cout<<"********************Program Exit Successfully********************"<<endl;
				//exit(0);
				break;
			}
			default:
			{
				cout<<"\nInvalid";
			}
		}
	}while(choice!=5);
	return 0;
}
