#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<double> pd = make_shared<double>(5.0);
    cout << "*pd = " << *pd << endl;

    shared_ptr<double> pshared = make_shared<double>(10.0);
    cout << "*pshared = " << *pshared << endl;

    shared_ptr<string> pstr = make_shared<string>("Hello World!");
    cout << "*pstr = " << *pstr << endl;

    return 0;
}
