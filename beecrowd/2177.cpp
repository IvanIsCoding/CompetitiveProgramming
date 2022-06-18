// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2177
#include <cstdio>
int main() {
    long long x, y, pontos, contador = 0;
    scanf("%lld %lld %lld", &x, &y, &pontos);
    for (long long i = 1; i <= pontos; i++) {
        long long u, v, t;
        scanf("%lld %lld %lld", &u, &v, &t);
        if ((x - u) * (x - u) + (y - v) * (y - v) < t * t) {
            if (contador) printf(" ");
            printf("%lld", i);
            contador++;
        }
    }
    if (contador == 0) printf("-1");
    printf("\n");
    return 0;
}
