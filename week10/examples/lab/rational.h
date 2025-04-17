// rational.h
#pragma once
#include <iostream>

class Rational {
private:
    static int id;
    int numerator;
    int denominator;

public:
    // 构造函数仍然允许从 int 隐式转换 (用于 Rational a = 10;)
    Rational(int n = 0, int d = 1) : numerator(n), denominator(d) {
        std::cout << "Construct_" << id++ << ", n:" << numerator << ",d:" << denominator << std::endl;
    }

    int getN() const { return numerator; }
    int getD() const { return denominator; }

    friend std::ostream &operator<<(std::ostream &os, const Rational &rhs) {
        os << rhs.numerator << "/" << rhs.denominator;
        return os;
    }
};

int Rational::id = 1;

// 原始版本: Rational * Rational
const Rational operator*(const Rational &lhs, const Rational &rhs) {
    // std::cout << "Using operator*(Rational, Rational)" << std::endl; // 调试信息
    return Rational(lhs.getN() * rhs.getN(), lhs.getD() * rhs.getD());
}

// 新增重载版本: Rational * int
const Rational operator*(const Rational &lhs, int rhs_int) {
    // std::cout << "Using operator*(Rational, int)" << std::endl; // 调试信息
    // 直接使用整数进行计算，避免为 rhs_int 创建 Rational 对象
    return Rational(lhs.getN() * rhs_int, lhs.getD()); 
}

// 新增重载版本: int * Rational (为了对称性和处理像 2 * a 这样的情况)
const Rational operator*(int lhs_int, const Rational &rhs) {
    // std::cout << "Using operator*(int, Rational)" << std::endl; // 调试信息
     // 直接使用整数进行计算，避免为 lhs_int 创建 Rational 对象
    return Rational(lhs_int * rhs.getN(), rhs.getD());
}