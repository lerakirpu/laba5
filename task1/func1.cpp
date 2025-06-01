#include "func1.h"
#include <algorithm>
#include <iostream>

std::vector<int> multiply(const std::vector<int>& num1, const std::vector<int>& num2) {
    std::vector<int> result(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            int mul = num1[i] * num2[j];
            int sum = mul + result[i + j + 1];

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }

    return result;
}

std::vector<int> add(const std::vector<int>& num1, const std::vector<int>& num2) {
    std::vector<int> result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--];
        if (j >= 0) sum += num2[j--];
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int> subtract(const std::vector<int>& num1, const std::vector<int>& num2) {
    std::vector<int> result;
    int borrow = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0) {
        int diff = num1[i--] - borrow;
        if (j >= 0) diff -= num2[j--];
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int> factorial(int n) {
    std::vector<int> result = {1};

    for (int i = 2; i <= n; ++i) {
        std::vector<int> num;
        int temp = i;
        while (temp > 0) {
            num.push_back(temp % 10);
            temp /= 10;
        }
        std::reverse(num.begin(), num.end());
        result = multiply(result, num);
    }

    return result;
}

std::vector<int> powerOfTwo(int exponent) {
    std::vector<int> result = {1};

    for (int i = 0; i < exponent; ++i) {
        result = multiply(result, {2});
    }

    return result;
}

std::vector<int> fibonacci(int n) {
    if (n == 0) return {0};
    if (n == 1) return {1};

    std::vector<int> a = {0};
    std::vector<int> b = {1};
    std::vector<int> c;

    for (int i = 2; i <= n; ++i) {
        c = add(a, b);
        a = b;
        b = c;
    }

    return b;
}

void printNumber(const std::vector<int>& number) {
    for (int digit : number) {
        std::cout << digit;
    }
    std::cout << std::endl;
}
