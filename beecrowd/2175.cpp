// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2175
#include <cstdio>
int main() {
    double otavio, bruno, flavio;
    scanf("%lf %lf %lf", &otavio, &bruno, &flavio);
    if (otavio < bruno && otavio < flavio)
        printf("Otavio\n");
    else if (bruno < otavio && bruno < flavio)
        printf("Bruno\n");
    else if (flavio < otavio && flavio < bruno)
        printf("Ian\n");
    else
        printf("Empate\n");
    return 0;
}
