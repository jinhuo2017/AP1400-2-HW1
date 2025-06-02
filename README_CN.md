# 高级编程 - 作业 1

<p align="center"> <b>作业 1 - 2022 年春季学期 <br> 截止日期：伊斯法罕月 1 日（周日）晚上 11:59</b> </p>
## 概述
在本次作业中，我们将为 C++ 实现一个**线性代数**库。
在这个库中，我们将实现不同的函数，让用户能够轻松地处理和操作不同的**矩阵**。
我们将在 `hw1.cpp` 和 `hw1.h` 中实现所有函数。请记住，应将所有声明放在 `.h` 文件中，所有实现放在 `.cpp` 文件中。
为了在 C++ 中表示矩阵，我们需要一个二维向量。我们使用以下代码行来简化语法：

```cpp
using Matrix = std::vector<std::vector<double>>;
```

从现在起，我们可以使用关键字 **Matrix** 来代替每次都定义二维向量。
所以，请将上述代码行添加到你的代码中。
**注意**：将所有函数定义在一个名为 `algebra` 的命名空间中。

# 函数

现在，让我们讨论每个函数以及应该如何实现它们。

- **zeros**
  实现此函数，使其创建一个 `n x m` 的矩阵，所有元素都等于零。
  
  ```cpp
  Matrix zeros(size_t n, size_t m)
  ```

- **ones**
  实现此函数，使其创建一个 `n x m` 的矩阵，所有元素都等于一。
  
  ```cpp
  Matrix ones(size_t n, size_t m)
  ```

- **random**
  实现此函数，使其创建一个 `n x m` 的矩阵，所有元素都是介于 `min` 和 `max` 之间的随机数。
  
  ```cpp
  Matrix random(size_t n, size_t m, double min, double max)
  ```
  
  **注意**：生成随机数时，不允许使用 `rand` 和 `srand` 函数。请使用 C++11 中首次引入的 `<random>` 库。

- **show**
  实现此函数，使其以美观的方式显示矩阵。
  
  ```cpp
  void show(const Matrix& matrix)
  ```
  
  **注意**：显示矩阵时，请使用 `<iomanip>` 库。显示数字时，矩阵的每个元素应精确到小数点后三位。

- **multiply** - *标量乘法*
  实现此函数，使其将 `matrix` 与常量标量 `c` 相乘。
  
  ```cpp
  Matrix multiply(const Matrix& matrix, double c)
  ```

- **multiply** - *矩阵乘法*
  实现此函数，使其将 `matrix1` 与 `matrix2` 相乘。（这**不是**逐元素相乘）
  
  ```cpp
  Matrix multiply(const Matrix& matrix1, const Matrix& matrix2)
  ```

- **sum** - *标量加法*
  实现此函数，使其将常量 `c` 加到 `matrix` 的每个元素上。
  
  ```cpp
  Matrix sum(const Matrix& matrix, double c)
  ```

- **sum** - *矩阵加法*
  实现此函数，使其将两个矩阵相加。
  
  ```cpp
  Matrix sum(const Matrix& matrix1, const Matrix& matrix2)
  ```

- **transpose**
  实现此函数，使其生成输入 `matrix` 的转置矩阵。
  
  ```cpp
  Matrix transpose(const Matrix& matrix)
  ```

- **minor**
  实现此函数，使其创建输入 `matrix` 相对于第 `n` 行和第 `m` 列的子式矩阵。
  
  ```cpp
  Matrix minor(const Matrix& matrix, size_t n, size_t m)
  ```
  
  **注意**：C++ 中的索引从 0 开始，例如：
  
  <br>
  <p align="center">
  <img src="resources/minor.png" alt="minor"
  title="minor" width="300" align="middle" />
  </p>
  <br>

- **determinant**
  实现此函数，使其计算输入 `matrix` 的行列式。
  
  ```cpp
  double determinant(const Matrix& matrix)
  ```
  
  *你只能使用子式法来计算行列式，不允许使用其他方法（如上三角法等）。*

- **inverse**
  实现此函数，使其生成 `matrix` 的逆矩阵。
  
  ```cpp
  Matrix inverse(const Matrix& matrix)
  ```

- **concatenate**
  实现此函数，使其沿指定轴连接 `matrix1` 和 `matrix2`。（`axis = 0`：上下连接 | `axis = 1`：左右连接）
  
  ```cpp
  Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis = 0)
  ```
  
  <br>
  <p align="center">
  <img src="resources/concatenate.png" alt="concatenate"
  title="concatenate" width="500" align="middle" />
  </p>
  <br>

- **初等行变换**
  我们要为库实现初等行变换（ERO）功能。如你所知，有三种初等行变换：
  `1)` 交换两行。
  `2)` 将一行乘以一个常数。
  `3)` 将一行乘以一个常数并加到另一行上。
  因此，让我们定义以下三个函数来实现这些操作：

- **swap**
  交换第 `r1` 行和第 `r2` 行。
  
  ```cpp
  Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2)
  ```

- **multiply**
  将第 `r` 行的每个元素乘以常数 `c`。
  
  ```cpp
  Matrix ero_multiply(const Matrix& matrix, size_t r, double c)
  ```

- **sum**
  将第 `r1` 行乘以 `c` 后加到第 `r2` 行上。
  
  ```cpp
  Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2)
  ```

- **上三角矩阵**
  实现此函数，使其使用初等行变换计算 `matrix` 的上三角形式。
  
  ```cpp
  Matrix upper_triangular(const Matrix& matrix)
  ```
  
  **注意**：要得到上三角矩阵，你必须使用主对角线上的元素将主对角线下方的所有元素置为零。考虑以下示例：
  
  <br/>
  <br/>
  <p align="center">
  <img src="resources/upper_triangular1.png" alt="upper_triangular1"
  title="upper_triangular1" width="600" align="middle" />
  </p>
  <br/>
  <br/>
  使用同样的方法，用 `j` 将 `l` 置为零，如下所示。
  <br/>
  <br/>
  
  <p align="center">
  <img src="resources/upper_triangular2.png" alt="upper_triangular2"
  title="upper_triangular2" width="500" align="middle" />
  </p>
  <br/>
  <br/>
  ***附加题**：如果主对角线上遇到零，例如上述示例中的 `a` 或 `j`，会发生什么情况？解决这个问题。*
  *最后一个单元测试是针对附加题的。如果测试失败，不用过于担心。*
  # 注意事项
  - 定义函数时，应始终考虑其使用的各个方面。本次作业中你编写的是一个库，可能会被其他人使用。因此，要记住他们可能不会总是正确使用你的函数。例如，他们可能会尝试计算非奇异矩阵的逆矩阵，或者尝试将两个维度不匹配的矩阵相乘。
  你应该跟踪这些可能在函数中出现的错误行为，并在这些情况下抛出 `logic_error` 异常。
  如果你不熟悉如何抛出异常，只需在网上搜索相关信息。别担心，这将是作业中最简单的部分 :stuck_out_tongue_winking_eye:
  - 除了逻辑错误，还应考虑用户可能会尝试使用空矩阵调用你的函数。（例如，空矩阵的行列式为 1）。在所有实现中都要牢记这一点。
  # 最后
  如前所述，将所有实现放在 `hw1.cpp` 和 `hw1.h` 中。不要修改其他文件。如果你想测试代码，只能使用 `main.cpp` 中的 `debug` 部分，这将在助教课程中进行讲解。
  ```cpp
  if (true) // 设为 false 以运行单元测试 
  { 
  // 调试部分 
  } 
  else 
  { 
  ::testing::InitGoogleTest(&argc, argv); 
  std::cout << "正在运行测试 ..." << std::endl; 
  int ret{RUN_ALL_TESTS()}; 
  if (!ret) 
  std::cout << "<<<成功>>>" << std::endl; 
  else 
  std::cout << "失败" << std::endl; 
  } 
  return 0;
  ```
  <br/>

<p align="center"> <b>祝你好运</b> </p>
