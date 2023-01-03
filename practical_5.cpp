// Online C++ compiler to run C++ program online
#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

template<typename T>
void sort(T a[],int n)
{
    int pos;
    T temp;
    for(int i=0;i<n;i++)
    {
        pos = i;
        for(int j =i+1;j<n;j++)
        {
            if(a[j]<a[pos])
                pos = j;
        }
        if(pos!=i)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
    cout<<"Sorted Elements are:";
    for(int k=0;k<n;k++)
    {
        cout<<"\n"<<a[k];
    }
}

int main() {
    int ch,no,ele,fno;
    while(1)
    {
        cout<<"\nMenu\n1]Int Sorting\n2]Char Sorting\n3]Float Sorting\n4]Exit";
        cout<<"\nEnter Choice";
        cin>>ch;
        switch(ch)
        {
            case 1:    
                cout<<"\nInteger Sorting\n";
                cout<<"\nEnter no of Elements to be Sorted\n";
                cin>>no;
                int sor1[100];
                cout<<"\nEnter Elements\n";
                for(int i;i<no;i++)
                {
                    cin>>sor1[i];
                }
                sort<int>(sor1,no);
                break;
            case 2:
                cout<<"\nCharacter Sorting\n";
                cout<<"\nEnter no of Elements to be Sorted\n";
                cin>>ele;
                char sor2[100];
                cout<<"\nEnter Elements\n";
                for(int i=0;i<ele;i++)
                {
                    cin>>sor2[i];
                }
                sort<char>(sor2,ele);
                break;
            case 3:
                cout<<"\nFloating type Sorting\n";
                cout<<"\nEnter no of Elements to be Sorted\n";
                cin>>fno;
                float sor3[100];
                cout<<"\nEnter Elements\n";
                for(int i=0;i<fno;i++)
                {
                    cin>>sor3[i];
                }
                sort<float>(sor3,fno);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}