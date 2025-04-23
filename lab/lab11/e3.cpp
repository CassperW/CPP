#include <iostream>
#include <memory>
using namespace std;

class B; // 前向声明

class A {
public:
    shared_ptr<B> pb;
    A() { cout << "Constructor A" << endl; }
    ~A() { cout << "Destructor A" << endl; }
};

class B {
public:
    weak_ptr<A> pa;
    B() { cout << "Constructor B" << endl; }
    ~B() { cout << "Destructor B" << endl; }
};

int main() {
    shared_ptr<A> spa = make_shared<A>();
    shared_ptr<B> spb = make_shared<B>();

    spa->pb = spb;
    spb->pa = spa;  

    return 0;
}
