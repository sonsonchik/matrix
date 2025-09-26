#include "matrix.h"
#include <iostream>
#include <cassert>

/**
 * @brief Тесты для библиотеки матриц
 */
void test_create_and_free() {
    std::cout << "Testing create_matrix and free_matrix..." << std::endl;
    
    // Тест 1: Создание нормальной матрицы
    Matrix m = create_matrix(3, 4);
    assert(m.rows == 3);
    assert(m.cols == 4);
    assert(m.data != nullptr);
    
    // Проверяем инициализацию нулями
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            assert(m.data[i][j] == 0.0);
        }
    }
    
    // Тест 2: Освобождение памяти
    free_matrix(m);
    std::cout << "✓ create_matrix and free_matrix: PASSED" << std::endl;
}

void test_addition() {
    std::cout << "Testing matrix addition..." << std::endl;
    
    // Создаем тестовые матрицы
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;
    
    // Тестируем сложение
    Matrix C = matrix_add(A, B);
    assert(C.data[0][0] == 6);  // 1 + 5
    assert(C.data[0][1] == 8);  // 2 + 6
    assert(C.data[1][0] == 10); // 3 + 7
    assert(C.data[1][1] == 12); // 4 + 8
    
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    std::cout << "✓ matrix_add: PASSED" << std::endl;
}

void test_multiplication() {
    std::cout << "Testing matrix multiplication..." << std::endl;
    
    Matrix A = create_matrix(2, 3);
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    
    Matrix B = create_matrix(3, 2);
    B.data[0][0] = 7; B.data[0][1] = 8;
    B.data[1][0] = 9; B.data[1][1] = 10;
    B.data[2][0] = 11; B.data[2][1] = 12;
    
    Matrix C = matrix_multiply(A, B);
    
    // Добавь отладочный вывод при ошибке
    if (C.data[0][0] != 58) {
        std::cerr << "Error: expected 58, got " << C.data[0][0] << std::endl;
    }
    assert(C.data[0][0] == 58);
    // ... остальные проверки
}

void test_transpose() {
    std::cout << "Testing matrix transpose..." << std::endl;
    
    Matrix A = create_matrix(2, 3);
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    
    Matrix B = matrix_transpose(A);
    assert(B.rows == 3);
    assert(B.cols == 2);
    
    // Проверяем транспонирование
    assert(B.data[0][0] == 1); assert(B.data[0][1] == 4);
    assert(B.data[1][0] == 2); assert(B.data[1][1] == 5);
    assert(B.data[2][0] == 3); assert(B.data[2][1] == 6);
    
    free_matrix(A);
    free_matrix(B);
    std::cout << "✓ matrix_transpose: PASSED" << std::endl;
}

void test_from_array() {
    std::cout << "Testing matrix_from_array..." << std::endl;
    
    double data[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    Matrix A = matrix_from_array(data, 2, 3);
    
    assert(A.rows == 2);
    assert(A.cols == 3);
    assert(A.data[0][0] == 1.1);
    assert(A.data[0][1] == 2.2);
    assert(A.data[0][2] == 3.3);
    assert(A.data[1][0] == 4.4);
    assert(A.data[1][1] == 5.5);
    assert(A.data[1][2] == 6.6);
    
    free_matrix(A);
    std::cout << "✓ matrix_from_array: PASSED" << std::endl;
}

void test_error_handling() {
    std::cout << "Testing error handling..." << std::endl;
    
    // Тест на невалидные размеры
    try {
        Matrix m = create_matrix(-1, 5);
        (void)m;
        assert(false); // Не должно дойти сюда
    } catch (const std::invalid_argument&) {
        // Ожидаемое исключение
    }
    
    // Тест на несовместимость размеров для сложения
    try {
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(3, 3);
        Matrix C = matrix_add(A, B);
        assert(false); // Не должно дойти сюда
        free_matrix(A);
        free_matrix(B);
        free_matrix(C);
    } catch (const std::invalid_argument&) {
        // Ожидаемое исключение
    }
    
    std::cout << "✓ Error handling: PASSED" << std::endl;
}

int main() {
    std::cout << "=== Running Matrix Library Tests ===" << std::endl;
    
    try {
        test_create_and_free();
        test_addition();
        test_multiplication();
        test_transpose();
        test_from_array();
        test_error_handling();
        
        std::cout << "\n=== All tests PASSED! ===" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Test FAILED: " << e.what() << std::endl;
        return 1;
    }
}