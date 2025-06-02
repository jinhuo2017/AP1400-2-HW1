#ifndef AP_HW1_H
#define AP_HW1_H

#include <vector>
#include <cstddef>

namespace algebra {
    // 定义 Matrix 类型别名
    using Matrix = std::vector<std::vector<double>>;

    // 函数声明
    Matrix zeros(size_t n, size_t m);
    Matrix ones(size_t n, size_t m);
    Matrix random(size_t n, size_t m, double min, double max);
    void show(const Matrix& matrix);
    Matrix multiply(const Matrix& matrix, double c);
    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);
}

#endif //AP_HW1_H