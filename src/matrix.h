#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

// Структура матрицы
typedef struct {
    double** data;    // двумерный массив данных
    int rows;         // количество строк
    int cols;         // количество столбцов
} Matrix;

// Базовые операции
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix m);
Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_multiply(Matrix a, Matrix b);
Matrix matrix_transpose(Matrix m);

// Вспомогательные функции
void print_matrix(Matrix m);
Matrix matrix_from_array(double* data, int rows, int cols);

/**
 * @brief Умножение двух матриц.
 * 
 * Вычисляет произведение матриц A и B. Количество столбцов матрицы A должно быть равно количеству строк матрицы B.
 * 
 * @param a Первая матрица (размер M×N)
 * @param b Вторая матрица (размер N×K)
 * @return Matrix Результирующая матрица (размер M×K)
 * @note Время выполнения: O(M*N*K). Для больших матриц используйте специализированные библиотеки (e.g., BLAS).
 * @warning Матрицы должны быть совместимы по размерам!
 * @exception std::invalid_argument Выбрасывается, если cols(a) != rows(b)
 * @see matrix_transpose, matrix_determinant
 */
Matrix matrix_multiply(const Matrix a, const Matrix b);
#endif