// tests/test_main.cpp
#include <iostream>

// Объявления тестовых функций
void test_matrix_addition();
void test_invalid_addition();
void test_matrix_multiplication();
// ... другие тесты ...

int main() {
    std::cout << "=== Starting Unit Tests ===\n";
    
    try {
        test_matrix_addition();
        test_invalid_addition();
        test_matrix_multiplication();
        // ... запуск других тестов ...
        
        std::cout << "=== ALL TESTS PASSED ===\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "TEST FAILED: " << e.what() << "\n";
        return 1;
    }
}