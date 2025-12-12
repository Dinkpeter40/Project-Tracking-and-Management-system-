#include <iostream>
#include<math.h>

using namespace std;
int factorial(int n)//factorial function
{
    if (n<0)
        return 0;
    else if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}
int sumofN(int n)//factorial and sum function 
{
    if(n>=1)
        return n+(n-1);
}
int sum(int x, int y)//sum function
{
    return x+y;
}

int callbyvalue(int& x)//function call by value and by reference example 
{
      x=40;
      return x;
}

int def(int x, int y=5)//default function
{
    return x+y;
}

int def1(int x)
{
    return x;
}
int z=90;//this for global variable example
int main()
{
    int x;
    int z=10;
    int y;
    cout<< "enter the number: ";
    cin>>x;
   // cout<<"The sum is: "<<def(x);//default para
    //callbyvalue(x);
    //cout<<x;
    //cout<<"enter the number: ";
    //cin>>y;
    //cout<<sum(x,y);
    cout<<"The factorial is: " << factorial(x)<< endl;
    cout<<"And Your sum could be "<<sumofN(x);
    //cout<<"Enter the number to get square root: ";
    //cin>>x;
    //cout<<sqrt(x);
    //cout<<z<<endl;
    //cout<<::z;
    return 0;
}