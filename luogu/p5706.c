#include<stdio.h>
int main(int argc, char const *argv[])
{
    double t, n;
    scanf("%lf %lf", &t, &n);
    printf("%.3lf\n%.0lf", t / n, n * 2);
    return 0;
}
