#include <iostream>
#include "func2.h"
int main() {
    int dividend, divisor;
    std::cout << "Enter dividend: ";
    std::cin >> dividend;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;
    int result = divide(dividend, divisor);
    if (result == -1){
        std::cout << "Error: You can't divide by zero.";
    }
    else{
        std::cout << "Result of the division: " << result << std::endl;
    }
    return 0;
}
