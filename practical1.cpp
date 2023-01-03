#include <iostream>
using namespace std;

class Complex
{
	public:
		float real,img;
		Complex(){}
		Complex operator+(Complex);
		Complex operator*(Complex);
		friend ostream &operator<<(ostream &,Complex&);
		friend istream &operator>>(istream &,Complex&);
};

Complex Complex::operator+(Complex obj)
{
	Complex temp;
	temp.real = real + obj.real;
	temp.img = img + obj.img;
	return temp;
}

istream &operator>>(istream &is,Complex &obj)
{
	is>>obj.real;
	is>>obj.img;
	return is;
}

ostream &operator<<(ostream &outt,Complex &obj)
{
	outt<<""<<obj.real;
	outt<<"+"<<obj.img<<"i";
	return outt;
}

Complex Complex::operator*(Complex obj)
{
	Complex temp;
	temp.real = real*obj.real - img*obj.img;
	temp.img = real*obj.img + img*obj.real;
	return temp;
}

int main()
{
	Complex a,b,c,d;
	cout<<"\nEnter first Complex Number\n";
	cout<<"\nEnter real and imaginary:\t";
	cin>>a;
	cout<<"\nEnter second Complex Number\n";
	cout<<"\nEnter real and imaginary:\t";
	cin>>b;
	cout<<"\n\tArithmetic Operations:";
	c = a+b;
	cout<<"\n\tAddition =";
	cout<<c;
	d = a*b;
	cout<<"\n\tMultiplication =";
	cout<<d;
	cout<<endl;
	return 0;
}
