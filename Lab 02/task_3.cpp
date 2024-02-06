#include <iostream>
using namespace std;

struct Area
{
    private:
    string unit;
    float area_value;

    public:

    Area(string uni, float value)
    {
        unit = uni;
        area_value= value;
    }

    float half_area()
    {
        return area_value/2;

    }
    float quarter_area()
    {
        return area_value/4;
    }

    void display()
    {
        cout<<"The Unit is: "<<unit<<endl;
        cout<<"The value is: "<<area_value;
    }
};

int main()
{
    Area* shape= new Area("cm^2",100);
    cout<<"The Half area is: "<<(*shape).half_area()<<endl;
    cout<<"The Quarter Area is: "<<(*shape).quarter_area()<<endl;

    (*shape).display();

    delete shape;
}