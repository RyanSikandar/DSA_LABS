#include <iostream>
using namespace std;

int main()
{
    // cout<<"Integer:"<<sizeof(int)<<endl;
    // cout<<"Long:"<<sizeof(long)<<endl;
    // cout<<"Float:"<<sizeof(float)<<endl;
    // cout<<"Double:"<<sizeof(double)<<endl;
    // cout<<"Character:"<<sizeof(char)<<endl;

    int a=5;
    int *p= &a;
    int result =p*2;
    cout<<result;
}