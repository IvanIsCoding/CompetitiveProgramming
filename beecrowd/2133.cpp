// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2133
#include <algorithm>
#include <cstdio>
#include <map>
#define MAXN 1048577
using namespace std;
int fatores[MAXN], maior[MAXN], expoentes[MAXN];
int main() {
    fatores[1] = 1;
    maior[1] = 1;
    expoentes[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        // printf("%d\n",i);
        if (fatores[i] == 0) {
            // printf("Entrou\n");
            fatores[i] = 1;
            maior[i] = 1;
            for (int j = 2 * i; j < MAXN; j += i) {
                int aux = j, pot = 0;
                while (aux % i == 0) {
                    pot++;
                    aux /= i;
                }
                fatores[j]++;
                maior[j] = max(maior[j], pot);
                expoentes[j] += int(pot >= 2);
            }
        }
    }
    int instancia = 1, n;
    while (scanf("%d", &n) != EOF) {
        if (fatores[n] >= 4) {
            printf("Instancia %d\nsim\n\n", instancia++);
            continue;
        }
        if (fatores[n] >= 3 && expoentes[n] >= 1) {
            printf("Instancia %d\nsim\n\n", instancia++);
            continue;
        }
        if (fatores[n] >= 2 && (expoentes[n] >= 2 || maior[n] >= 5)) {
            printf("Instancia %d\nsim\n\n", instancia++);
            continue;
        }
        if (fatores[n] >= 1 && maior[n] >= 8) {
            printf("Instancia %d\nsim\n\n", instancia++);
            continue;
        }
        printf("Instancia %d\nnao\n\n", instancia++);
        continue;
    }
    return 0;
}
