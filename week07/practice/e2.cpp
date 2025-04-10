#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the generic Compare template function
template <typename T>
int Compare(const T &a, const T &b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

// Step 2: Define the explicit specialization for struct stuinfo
struct stuinfo {
    string name;
    int age;
};

// Explicit specialization of Compare for stuinfo
template <>
int Compare<stuinfo>(const stuinfo &a, const stuinfo &b) {
    if (a.age > b.age) return 1;
    if (a.age < b.age) return -1;
    return 0;
}

// Step 3: Test the program
int main() {
    // Test with integers
    int int1 = 5, int2 = 10;
    cout << "Compare of two integers: " << Compare(int1, int2) << endl;

    // Test with floats
    float float1 = 7.5f, float2 = 3.2f;
    cout << "Compare of two floats: " << Compare(float1, float2) << endl;

    // Test with characters
    char char1 = 'c', char2 = 'a';
    cout << "Compare of two characters: " << Compare(char1, char2) << endl;

    // Test with structs
    stuinfo stu1 = {"Alice", 25}, stu2 = {"Bob", 20};
    cout << "Compare of two structs: " << Compare(stu1, stu2) << endl;

    return 0;
}