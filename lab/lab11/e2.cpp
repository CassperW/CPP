#include "matrix.h"
using namespace std;
int main() {
    Matrix a(3, 4);
    Matrix b(3, 4);

    // 设置 a 和 b 的部分元素
    a.at(1, 2) = 3;
    b.at(2, 3) = 4;

    Matrix c = a + b;
    Matrix d = a;

    cout << "a is:\n";
    a.print();

    cout << "\nb is:\n";
    b.print();

    cout << "\nc is:\n";
    c.print();

    cout << "\nBefore assignment, d is:\n";
    d.print();

    d = b;

    cout << "\nAfter assignment, d is:\n";
    d.print();

    return 0;
}
