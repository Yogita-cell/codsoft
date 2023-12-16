#include<iostream>
using namespace std;
int main()
{
char ch;
int x,y;
cout<<"\n Enter choice +,-,*,/";
cin>>ch;
cout<<"\n Enter Two Value";
cin>>x>>y;
switch(ch)
{
case '+':
cout<<"\n Addition ="<<x+y;
break;
case '-':
cout<<"\n Substraction ="<<x-y;
break;
case '*':
cout<<"\n Multiplication ="<<x*y;
break;
case '/':
cout<<"\n Division ="<<x/y;
break;
default:
cout<<"\n Invalid oprator";
return 0;
}
}