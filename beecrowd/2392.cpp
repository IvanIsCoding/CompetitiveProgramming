// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2392
#include <cstdio>
int vetor[10000], n, sapos;
int main() {
    scanf("%d %d", &n, &sapos);
    for (int i = 0; i < sapos; i++) {
        int inicial, distancia;
        scanf("%d %d", &inicial, &distancia);
        for (int k = inicial; k > 0; k -= distancia) vetor[k] = 1;
        for (int k = inicial; k <= n; k += distancia) vetor[k] = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d\n", vetor[i]);
    return 0;
}
