#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class db
{
	int roll;
	char name[10];
	char Class[10];
	char Div[10];
	char dob[10];
	char bg[3],contact[10];
	char phone[13],license[12];

	public:
		static int stdno;
		static void count()
		{
			cout<<"\nNumber of Objects created: "<<stdno<<endl;
		}
		inline void fin()
		{
			cout<<"This is an Inline Function"<<endl;
		}
		
		db()
		{
			roll = 0;
			strcpy(name,"Sachin");
			strcpy(Class,"I");
			strcpy(Div,"A");
			strcpy(dob,"01/01/2001");
			strcpy(bg,"A");
			strcpy(contact,"city");
			strcpy(phone,"+911234567890");
			strcpy(license,"A01010101");
			++stdno;
		}

		db(db *ob)
		{
			strcpy(name,ob->name);
			strcpy(Class,ob->Class);
			strcpy(Div,ob->Div);
			strcpy(dob,ob->dob);
			strcpy(bg,ob->bg);
			strcpy(contact,ob->contact);
			strcpy(phone,ob->phone);
			strcpy(license,ob->license);
			++stdno;
		}

		void getdata()
		{
			cout<<"\nEnter:\n";
			cout<<"Name:";
			cin>>name;
			cout<<"Roll no:";
			cin>>roll;
			cout<<"Class:";
			cin>>Class;
			cout<<"Division:";
			cin>>Div;
			cout<<"DOB:";
			cin>>dob;
			cout<<"Blood Grp:";
			cin>>bg;
			cout<<"Contact:";
			cin>>contact;
			cout<<"Phone:";
			cin>>phone;
			cout<<"License:";
			cin>>license;
		}

		friend void display(db d);

		~db()
		{
			cout<<"\n\n"<<this->name<<"(Object) is destroyed";
		}
};

void display(db d)
{
	cout<<"\n"<<setw(10)<<"\nName:"<<d.name<<setw(10)<<"\nRoll no:"<<d.roll<<setw(10)<<"\nClass:"<<d.Class<<setw(10)<<"\nDivision:"<<d.Div<<setw(10)<<"\nDOB:"<<d.dob<<setw(3)<<"\nBlood Group:"<<d.bg<<setw(10)<<"\nContact:"<<d.contact<<" "<<setw(13)<<"\nPhone:"<<d.phone<<" "<<setw(12)<<"\nLicense:"<<d.license;
}

int db::stdno;

int main()
{
	int n,i;
	db d1,*ptr[5];
	cout<<"\nDefault value";
	display(d1);
	
	d1.getdata();
	display(d1);
	
	db d2(&d1);
	cout<<"\nUse of Copy Constructor";
	display(d2);

	cout<<"\nNumber of Objects you want to create:";
	cin>>n;
	for(i = 0; i < n; i++)
	{
		ptr[i] = new db();
		ptr[i] -> getdata();
	}
	
	for(i = 0; i < n; i++)
	{
	    display(ptr[i]);
	}
	
	/*cout<<"\n"<<setw(10)<<"Name"<<setw(5)<<"Roll no."<<setw(10)<<"Class"<<setw(10)<<"Divsion"<<setw(10)<<"DOB"<<setw(3)<<"Blood Grp"<<setw(10)<<"Contact"<<setw(13)<<"Phone"<<setw(12)<<"license";*/
	for(i = 0; i < n; i++)
	{
		delete(ptr[i]);
	}
	cout<<"\nObjects deleted";
	return 0;
}
	