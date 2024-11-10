#include<iostream>
using namespace std;

void fibonacciNonRecursive(int num)
{
    int a = 0 , b = 1,c;
    if( num <= 0)
    {
        cout<<"Wrong input"<<endl;
        return;
    }
    else if( num == 1)
    {
        cout<<a;
        return;
    }
    cout<< a <<" "<< b <<" ";
    for(int i=2;i<num;i++)
    {
        int c = a+b;
        a = b;
        b = c;
        cout<<c<<" ";
    }
}

int fibonacciRecursive(int num)
{
    if(num <= 1)
        return num;
    return fibonacciRecursive(num-1) + fibonacciRecursive(num-2);
}

int main()
{
    cout<<"Enter the number : "<<endl;
    int num;
    cin>>num;
    cout<<"Fibonacci Non Recursive"<<endl;
    fibonacciNonRecursive(num);
    cout<<endl<<"Fibonacci Recursive "<<endl;
    for(int i = 0;i<num ;i++)
    {
        cout<<fibonacciRecursive(i)<<" ";
    }
    return 0;
}