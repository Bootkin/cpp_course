#include <cstdio>
#include <cmath>

int main()
{
    std::puts("please enter a , b and c for 'ax^2 + bx + c =0':");

    float a = 0;
    float b = 0;
    float c = 0;

    std::scanf("%f %f %f", &a, &b, &c);

    float D = (b * b - 4 * a * c);
    if (D < 0)
    {
        std::printf("No solution");
    }
    else
    {
        if (D == 0)
        {
            float x = (-b / (2 * a));
            std::printf("solution: %f\n", x);
        }
        else
        {
            float x1 = ((-(sqrt(D)) - b) / (2 * a));
            float x2 = (((sqrt(D)) - b) / (2 * a));
            std::printf("first solution: %f\n", x1);
            std::printf("second solution: %f\n", x2);
        }
    }
}