#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "RUS");
    double x; // Давление (бар)
    double q; // Результат
    printf("Введите параметр X (давление (бар)): ");
    scanf("%lf", &x);

    //Расчет q в зависимости от диапазона X
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
    printf("\nРезультаты расчета:\n");
    printf("Q(x) = %.2lf\n", q);

    return 0;
}