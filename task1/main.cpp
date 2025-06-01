#include <iostream>
#include "func1.h"  

int main() {
    int input_1, input_2;  

    std::cout << "Введите число больше 100: ";
    std::cin >> input_1;

    if (input_1 <= 100) {
        std::cerr << "Ошибка: число должно быть больше 100.\n";  
        return 1; 
    }
    // Вычисление факториала с помощью функции factorial()
    std::vector<int> fact = factorial(input_1);
    std::cout << "Факториал числа " << input_1 << ":\n";
    printNumber(fact); 

    std::cout << "Введите число больше 64: ";
    std::cin >> input_1;

    if (input_1 <= 64) {
        std::cerr << "Ошибка: число должно быть больше 64.\n";
        return 1;
    }
    // Вычисление степени двойки с помощью функции powerOfTwo()
    std::vector<int> pow2 = powerOfTwo(input_1);
    std::cout << "2^" << input_1 << ":\n";
    printNumber(pow2);

    std::cout << "Введите два числа больше 64: ";
    std::cin >> input_1 >> input_2;
    if (input_1 <= 64 || input_2 <= 64) {
        std::cerr << "Ошибка: оба числа должны быть больше 64.\n";
        return 1; 
    }
    // Вычисление суммы 2^input1 + 2^input2
    std::vector<int> sumPow = add(powerOfTwo(input_1), powerOfTwo(input_2));
    std::cout << "2^" << input_1 << " + 2^" << input_2 << ":\n";
    printNumber(sumPow);

    std::cout << "Введите два числа больше 64 (первое больше второго): ";
    std::cin >> input_1 >> input_2;
    // Проверка корректности ввода (должны быть input_1 > input_2 > 64)
    if (input_1 <= 64 || input_2 <= 64 || input_1 <= input_2) {
        std::cerr << "Ошибка: оба числа должны быть больше 64, и первое число должно быть больше второго.\n";
        return 1; 
    }
    // Вычисление разности 2^input1 - 2^input2
    std::vector<int> diffPow = subtract(powerOfTwo(input_1), powerOfTwo(input_2));
    std::cout << "2^" << input_1 << " - 2^" << input_2 << ":\n";
    printNumber(diffPow);

    std::cout << "Введите число больше 100: ";
    std::cin >> input_1;
 
    if (input_1 <= 100) {
        std::cerr << "Ошибка: число должно быть больше 100.\n";
        return 1; 
    }
    // Вычисление input_1-го числа Фибоначчи
    std::vector<int> fib = fibonacci(input_1);
    std::cout << "Число Фибоначчи под номером " << input_1 << ":\n";
    printNumber(fib);

    return 0;  
}
