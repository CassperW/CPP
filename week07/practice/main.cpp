#include <iostream>

// Declare the overloaded functions
bool vabs(int* p, size_t n);
bool vabs(float* p, size_t n);
bool vabs(double* p, size_t n);

int main() {
    // Define function pointers for each overload
    bool (*vabs_int_ptr)(int*, size_t) = vabs;
    bool (*vabs_float_ptr)(float*, size_t) = vabs;
    bool (*vabs_double_ptr)(double*, size_t) = vabs;

    // Test with int array
    int intArray[] = {-1, -2, -3};
    std::cout << "Address of vabs(int*, size_t): " << (void*)vabs_int_ptr << std::endl;
    vabs(intArray, 3);
    for (int i : intArray) std::cout << i << " ";
    std::cout << std::endl;

    // Test with float array
    float floatArray[] = {-1.1f, -2.2f, -3.3f};
    std::cout << "Address of vabs(float*, size_t): " << (void*)vabs_float_ptr << std::endl;
    vabs(floatArray, 3);
    for (float f : floatArray) std::cout << f << " ";
    std::cout << std::endl;

    // Test with double array
    double doubleArray[] = {-1.1, -2.2, -3.3};
    std::cout << "Address of vabs(double*, size_t): " << (void*)vabs_double_ptr << std::endl;
    vabs(doubleArray, 3);
    for (double d : doubleArray) std::cout << d << " ";
    std::cout << std::endl;

    return 0;
}