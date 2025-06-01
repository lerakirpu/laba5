#include "func2.h"
#include <iostream>

int divide(int dividend, int divisor)
{
    // Обработка деления на ноль
    if (divisor == 0)
    {
        return -1;
    }

    // Определение знака результата
    bool isNegative = (dividend < 0) ^ (divisor < 0);

    // Работаем с положительными числами
    unsigned int u_dividend = dividend;
    unsigned int u_divisor = divisor;

    if (dividend < 0)
    {
        u_dividend = -dividend; // Преобразуем делимое в положительное число
    }
    if (divisor < 0)
    {
        u_divisor = -divisor; // Преобразуем делитель в положительное число
    }

    unsigned int result = 0;

    // Алгоритм деления
    for (int i = 31; i >= 0; --i)
    {
        // Проверяем, можно ли вычесть (u_divisor << i) из u_dividend
        if ((u_dividend >> i) >= u_divisor)
        {
            // Если можно, добавляем соответствующий бит в результат
            result += (1 << i);
            // Вычитаем (u_divisor << i) из u_dividend
            u_dividend -= (u_divisor << i);
        }
    }

    if (result > 2147483647)
    { // Если результат превышает область значений Int
        if (isNegative)
        {
            return -2147483648; // Минимальное значение int
        }
        else
        {
            return 2147483647; // Максимальное значение int
        }
    }

    // Возвращаем результат с учетом знака
    if (isNegative)
    {
        return -static_cast<int>(result);
    }
    else
    {
        return static_cast<int>(result);
    }
}
