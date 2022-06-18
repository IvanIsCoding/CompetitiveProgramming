// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2565
#include <cmath>
#include <cstdio>
#define MAXN 101
#define EPS 1e-7
int n;
double vetor[MAXN];
double func(double val) {
    double resp = 0;
    for (int i = 1; i <= n; i++) resp += fabs(vetor[i] - val);
    return resp;
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &vetor[i]);
        }
        double ini = 0, fim = 100.0;
        while (fim - ini > EPS) {
            double meio1 = ini + (fim - ini) / 3;
            double meio2 = fim - (fim - ini) / 3;
            if (func(meio1) > func(meio2)) {
                ini = meio1 + EPS;
            } else
                fim = meio2 - EPS;
        }
        printf("%.2lf\n", func(ini));
    }
    return 0;
}
