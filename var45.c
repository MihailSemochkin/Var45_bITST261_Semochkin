#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double input_data() // Функция ввода данных
{
    double x;
    printf("Введите параметр X (давление в бар): ");
    scanf("%lf", &x);
    return x;
}

double calculate_Q(double x) // Функция вычисления Q
{
    double q = 0.0;
    if (x < 4)
    {
        q = 3 * (x - 4) + 10;
    }
    else if (x >= 4 && x <= 9)
    {
        q = 2 * sqrt(x - 6.5 + 2) + 45;
    }
    else
    {
        q = pow((x - 9), 2) / 1.0 + 55;
    }
    return q;
}

void check(double x, double q) // Функция проверки
{
    double UCL = 57.83;
    printf("\nРезультаты расчета:\n");
    printf("Q(x) = %.2lf\n", q);
    if (x < 1 || x > 15)
    {
        printf("\nВНИМАНИЕ! Давление Х (%.2lf) вне допустимого диапазона (1...15).\n", x);
        printf("Состояние: Отклонение технологического режима.\n");
    }
    else if (q > UCL)
    {
        printf("\nВНИМАНИЕ! Значение Q (%.2lf) превышает UCL (%.2lf).\n", q, UCL);
        printf("Состояние: Отклонение технологического режима.\n");
    }
    else
    {
        printf("\nЗначение в норме.\n");
        printf("Состояние: Штатный режим.\n");
    }

}
int main()
{
    setlocale(LC_ALL, "RUS");

    double x = input_data();

    double q = calculate_Q(x);

    check(x, q);

    return 0;
}
