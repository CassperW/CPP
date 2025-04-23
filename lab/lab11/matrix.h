#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix {
private:
    int rows, cols;
    shared_ptr<float[]> data;

public:
    // 构造函数
    Matrix(int r, int c) : rows(r), cols(c), data(new float[r * c]()) {}

    // 复制构造函数（共享数据）
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // 赋值运算符（共享数据）
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    // 元素访问
    float& at(int r, int c) {
        return data[r * cols + c];
    }

    float at(int r, int c) const {
        return data[r * cols + c];
    }

    // 加法运算符
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("Matrix dimensions must match for addition");

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // 输出函数
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << fixed << setprecision(0) << at(i, j) << " ";
            }
            cout << endl;
        }
    }
};
