// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2295
#include <cstdio>
int main() {
    double a, g, ra, rg;
    scanf("%lf %lf %lf %lf", &a, &g, &ra, &rg);
    if (ra / a > rg / g)
        printf("A\n");
    else
        printf("G\n");
    return 0;
}
