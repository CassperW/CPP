// complex.h
#pragma once 

#include <iostream>
#include <cmath>   
#include <iomanip> 

// --- Complex 类定义 ---
class Complex {
private:
    double realPart;      // 实部
    double imaginaryPart; // 虚部

public:
    // 构造函数，带有默认值 (0 + 0i)
    Complex(double r = 0.0, double i = 0.0) : realPart(r), imaginaryPart(i) {}

    // 输入输出
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

    // 算术运算符 (Complex <op> Complex)
    friend const Complex operator+(const Complex& lhs, const Complex& rhs);
    friend const Complex operator-(const Complex& lhs, const Complex& rhs);
    friend const Complex operator*(const Complex& lhs, const Complex& rhs);

    // 算术运算符 (Complex <op> double)
    friend const Complex operator-(const Complex& lhs, double rhs_real);
    friend const Complex operator*(const Complex& lhs, double rhs_real);

    // 算术运算符 (double <op> Complex) - 为了对称性
    friend const Complex operator-(double lhs_real, const Complex& rhs);
    friend const Complex operator*(double lhs_real, const Complex& rhs);

    // 共轭运算符
    friend const Complex operator~(const Complex& c);

    // 比较运算符
    friend bool operator==(const Complex& lhs, const Complex& rhs);
    friend bool operator!=(const Complex& lhs, const Complex& rhs); // 确保这个 friend 声明存在

    double getReal() const { return realPart; }
    double getImaginary() const { return imaginaryPart; }
};

// 输出流运算符定义: a+bi 或 a-bi 格式
inline std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.realPart;
    os << (c.imaginaryPart >= 0 ? "+" : "") << c.imaginaryPart << "i";
    return os;
}

// 输入流运算符定义: 期望用户输入 实部 和 虚部，用空格隔开
inline std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.realPart >> c.imaginaryPart;
    return is;
}

// 加法运算符定义 (Complex + Complex)
inline const Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.realPart + rhs.realPart, lhs.imaginaryPart + rhs.imaginaryPart);
}

// 减法运算符定义 (Complex - Complex)
inline const Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.realPart - rhs.realPart, lhs.imaginaryPart - rhs.imaginaryPart);
}

// 减法运算符定义 (Complex - double)
inline const Complex operator-(const Complex& lhs, double rhs_real) {
    return Complex(lhs.realPart - rhs_real, lhs.imaginaryPart);
}

// 减法运算符定义 (double - Complex)
inline const Complex operator-(double lhs_real, const Complex& rhs) {
    return Complex(lhs_real - rhs.realPart, -rhs.imaginaryPart);
}


// 乘法运算符定义 (Complex * Complex)
// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
inline const Complex operator*(const Complex& lhs, const Complex& rhs) {
    double real = lhs.realPart * rhs.realPart - lhs.imaginaryPart * rhs.imaginaryPart;
    double imag = lhs.realPart * rhs.imaginaryPart + lhs.imaginaryPart * rhs.realPart;
    return Complex(real, imag);
}

// 乘法运算符定义 (double * Complex)
inline const Complex operator*(double lhs_real, const Complex& rhs) {
    return Complex(lhs_real * rhs.realPart, lhs_real * rhs.imaginaryPart);
}

// 乘法运算符定义 (Complex * double)
inline const Complex operator*(const Complex& lhs, double rhs_real) {
     return Complex(lhs.realPart * rhs_real, lhs.imaginaryPart * rhs_real);
}

// 共轭运算符定义 (~)
// (a + bi) 的共轭是 (a - bi)
inline const Complex operator~(const Complex& c) {
    return Complex(c.realPart, -c.imaginaryPart);
}

// 相等运算符定义 (==)
// 两个复数相等当且仅当它们的实部和虚部都分别相等
inline bool operator==(const Complex& lhs, const Complex& rhs) {
    // 注意：对于浮点数比较，直接用 == 可能有精度问题。
    return (lhs.realPart == rhs.realPart) && (lhs.imaginaryPart == rhs.imaginaryPart);
}

// 不等运算符定义 (!=)
// 可以直接利用 == 的结果
inline bool operator!=(const Complex& lhs, const Complex& rhs) {
    return !(lhs == rhs);
}