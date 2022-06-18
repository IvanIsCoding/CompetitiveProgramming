// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2428
#include <cstdio>
int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if (a / b == c / d || a / b == d / c || a / c == b / d || a / c == d / b ||
        a / d == b / c || a / d == c / b)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
