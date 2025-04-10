#include <iostream>
#include <cstdlib> // for std::abs
#include <cmath>   // for std::fabs

// Overloaded function for int array
bool vabs(int* p, size_t n) {
    if (p == nullptr || n == 0) return false; // Check for valid pointer and size
    for (size_t i = 0; i < n; ++i) {
        p[i] = std::abs(p[i]); // Compute absolute value for int
    }
    return true;
}

// Overloaded function for float array
bool vabs(float* p, size_t n) {
    if (p == nullptr || n == 0) return false; // Check for valid pointer and size
    for (size_t i = 0; i < n; ++i) {
        p[i] = std::fabs(p[i]); // Compute absolute value for float
    }
    return true;
}

// Overloaded function for double array
bool vabs(double* p, size_t n) {
    if (p == nullptr || n == 0) return false; // Check for valid pointer and size
    for (size_t i = 0; i < n; ++i) {
        p[i] = std::fabs(p[i]); // Compute absolute value for double
    }
    return true;
}