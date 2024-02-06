#include <iostream>
using namespace std;
void analyze_pointer(int *ptr)
{
    cout<<"Memory Address of the pointer is: "<<ptr<<endl;
    cout<<"The Value pointer by the pointer is: "<<*ptr<<endl;

}

int main(void)
{
    int* ptr= new int(10);
    int i = 20;
    analyze_pointer(&i);
    cout<< endl;
    analyze_pointer(ptr);
    delete ptr;
return 0;
}
