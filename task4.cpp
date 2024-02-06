#include <iostream>
using namespace std;

void swap_address(int &a,int&b)
{
    int temp=0;
    temp =a;
    a=b;
    b=temp;
}

void swap_pointers(int** a,int** b)
{
    int temp = **a;
    **a  = **b ;
    **b  = temp;
}
int main()
{
	int a=5, b=10; 
    swap_address(a,b);
    cout<<"Swapped Values are: "<<a<<','<<b;

	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
	
	int **ppa=&pa; //ppa and ppb are called double pointers or pointers-to-pointers.
	int **ppb=&pb;

    swap_pointers(&pa,&pb);
    cout<<"\nSwapped Values are: "<<a<<','<<b;





}