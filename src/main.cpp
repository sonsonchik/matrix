#include "matrix.h"
#include <iostream>

/**
 * @brief Демонстрационная программа для библиотеки матриц
 */
int main() {
    std::cout << "=== Matrix Calculator Demo ===" << std::endl;
    
    try {
        // 1. Демонстрация создания матриц
        std::cout << "\n1. Creating matrices:" << std::endl;
        
        Matrix A = create_matrix(2, 3);
        A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
        A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
        
        Matrix B = create_matrix(2, 3);
        B.data[0][0] = 7; B.data[0][1] = 8; B.data[0][2] = 9;
        B.data[1][0] = 10; B.data[1][1] = 11; B.data[1][2] = 12;
        
        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);
        
        std::cout << "Matrix B:" << std::endl;
        print_matrix(B);
        
        // 2. Демонстрация сложения
        std::cout << "\n2. Matrix addition A + B:" << std::endl;
        Matrix sum = matrix_add(A, B);
        print_matrix(sum);
        
        // 3. Демонстрация транспонирования
        std::cout << "\n3. Transpose of A:" << std::endl;
        Matrix A_transposed = matrix_transpose(A);
        print_matrix(A_transposed);
        
        // 4. Демонстрация умножения
        std::cout << "\n4. Matrix multiplication:" << std::endl;
        Matrix C = create_matrix(3, 2);
        C.data[0][0] = 1; C.data[0][1] = 2;
        C.data[1][0] = 3; C.data[1][1] = 4;
        C.data[2][0] = 5; C.data[2][1] = 6;
        
        std::cout << "Matrix C (3x2):" << std::endl;
        print_matrix(C);
        
        Matrix product = matrix_multiply(A, C);
        std::cout << "Matrix A × C:" << std::endl;
        print_matrix(product);
        
        // 5. Демонстрация создания из массива
        std::cout << "\n5. Matrix from array:" << std::endl;
        double arr[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
        Matrix D = matrix_from_array(arr, 2, 3);
        print_matrix(D);
        
        // 6. Демонстрация обработки ошибок
        std::cout << "\n6. Error handling demonstration:" << std::endl;
        try {
            Matrix invalid = create_matrix(-1, 5);
            (void)invalid;
        } catch (const std::exception& e) {
            std::cout << "Caught expected error: " << e.what() << std::endl;
        }
        
        // Освобождение памяти
        free_matrix(A);
        free_matrix(B);
        free_matrix(sum);
        free_matrix(A_transposed);
        free_matrix(C);
        free_matrix(product);
        free_matrix(D);
        
        std::cout << "\n=== Demo completed successfully! ===" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}