// tests/test_matrix.cpp
#include <cassert>
#include <iostream>
#include "../src/matrix.h"  // Подключаем заголовочный файл с матрицами

/**
 * @brief Тест сложения матриц (нормальный случай)
 */
void test_matrix_addition() {
    std::cout << "Running test_matrix_addition... ";
    
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    // Заполнение тестовыми данными
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;
    
    Matrix result = matrix_add(A, B);
    
    // Проверка результата
    assert(result.rows == 2 && result.cols == 2);
    assert(result.data[0][0] == 6);   // 1+5
    assert(result.data[0][1] == 8);   // 2+6
    assert(result.data[1][0] == 10);  // 3+7
    assert(result.data[1][1] == 12);  // 4+8
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    
    std::cout << "PASSED\n";
}

/**
 * @brief Тест обработки ошибок при сложении
 */
void test_invalid_addition() {
    std::cout << "Running test_invalid_addition... ";
    
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3); // Несовместимые размеры!
    
    try {
        Matrix result = matrix_add(A, B);
        assert(false); // Не должно сюда попасть!
    } catch (const std::exception& e) {
        assert(std::string(e.what()) == "Matrix dimensions mismatch");
    }
    
    free_matrix(A);
    free_matrix(B);
    
    std::cout << "PASSED\n";
}

/**
 * @brief Тест умножения матриц
 */
void test_matrix_multiplication() {
    std::cout << "Running test_matrix_multiplication... ";
    
    Matrix A = create_matrix(2, 3);
    Matrix B = create_matrix(3, 2);
    
    // Заполнение матриц тестовыми данными
    // A = [[1, 2, 3], [4, 5, 6]]
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    
    // B = [[7, 8], [9, 10], [11, 12]]
    B.data[0][0] = 7;  B.data[0][1] = 8;
    B.data[1][0] = 9;  B.data[1][1] = 10;
    B.data[2][0] = 11; B.data[2][1] = 12;
    
    Matrix result = matrix_multiply(A, B);
    
    // Проверка: result[0][0] = 1*7 + 2*9 + 3*11 = 7 + 18 + 33 = 58
    assert(result.data[0][0] == 58);
    assert(result.data[0][1] == 64);  // 1*8 + 2*10 + 3*12 = 8 + 20 + 36 = 64
    assert(result.data[1][0] == 139); // 4*7 + 5*9 + 6*11 = 28 + 45 + 66 = 139
    assert(result.data[1][1] == 154); // 4*8 + 5*10 + 6*12 = 32 + 50 + 72 = 154
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    
    std::cout << "PASSED\n";
}

// Добавь другие тесты: вычитание, транспонирование, определитель и т.д.