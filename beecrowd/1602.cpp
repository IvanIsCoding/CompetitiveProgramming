// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1602
#include <cstdio>
#define MAXN 2000001
int soma[MAXN], divisores[MAXN];
int main() {
    for (int i = 1; i < MAXN; i++) {
        divisores[i] = 1;
    }
    for (int i = 2; i < MAXN; i++) {
        // printf("Entrou %d\n",i);
        if (divisores[i] == 1) {
            // printf("%d e primo\n",i);
            divisores[i] = 2;
            for (int j = 2 * i; j < MAXN; j += i) {
                int temp = j, potencia = 0;
                while (temp % i == 0) {
                    potencia++;
                    temp = temp / i;
                }
                // printf("%d possui %d fatores %d\n",j,potencia,i);
                divisores[j] *= (potencia + 1);
            }
        }
        soma[i] = soma[i - 1] + int(divisores[divisores[i]] == 2);
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", soma[n]);
    }
    return 0;
}
