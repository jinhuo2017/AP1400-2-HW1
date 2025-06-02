#include "hw1.h"
#include "../include/hw1.h"

#include <vector>
#include <random>
#include <iomanip>
#include <iostream>

namespace algebra {
    Matrix zeros(size_t n, size_t m) {
        // 创建一个 n x m 的矩阵，所有元素初始化为 0.0
        return Matrix(n, std::vector<double>(m, 0.0));
    }

    Matrix ones(size_t n, size_t m) {
        // 创建一个 n x m 的矩阵，所有元素初始化为 1.0
        return Matrix(n, std::vector<double>(m, 1.0));
    }

    // 所有元素都是介于 `min` 和 `max` 之间的随机数
    Matrix random(size_t n, size_t m, double min, double max) {

        if (min > max) {
            throw std::logic_error("Invalid arguments: min cannot be greater than max");
        }

        // 初始化随机数引擎和分布
        std::random_device rd; // 随机种子
        std::mt19937 gen(rd());  // 使用 Mersenne Twister 引擎
        std::uniform_real_distribution<double> dis(min, max);  // 均匀分布

        // 创建矩阵并填充随机数
        Matrix matrix(n, std::vector<double>(m));
        for (auto& row : matrix) {
            for (auto& elem : row) {
                elem = dis(gen);
            }
        }

        return matrix;
    }


    void show(const Matrix& matrix) {
        std::cout << std::fixed << std::setprecision(3);  // 固定小数点，保留 3 位
        for (const auto& row : matrix) {
            for (const auto& elem : row) {
                std::cout << std::setw(8) << elem << " ";  // 设置宽度为 8，对齐美观
            }
            std::cout << std::endl;  // 每行结束换行
        }
    }

    Matrix multiply(const Matrix& matrix, double c) {
        Matrix res = matrix;
        for (auto& row : res) {
            for (auto& elem : row) {
                elem *= c;
            }
        }
        return res;
    }

    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2) {
        // 检查空矩阵
        if (matrix1.empty() || matrix2.empty()) {
            return Matrix{};
        }

        // 检查维度是否匹配：A B * B C = A C
        size_t cols_mat1 = matrix1[0].size();
        size_t rows_mat2 = matrix2.size();
        if (cols_mat1 != rows_mat2) {
            throw std::logic_error("两个矩阵的维度不匹配");
        }

        size_t rows_res = matrix1.size();
        size_t cols_res = matrix2[0].size();
        Matrix res = zeros(rows_res, cols_res);
        for (size_t i = 0; i < rows_res; i++) {
            for (size_t j = 0; j < cols_res; j++) {
                for (size_t k = 0; k < cols_mat1; k++) {
                    res[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        return res;

    }
}