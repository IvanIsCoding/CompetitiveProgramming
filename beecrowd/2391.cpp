// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2391
#include <cstdio>
#define MAXN 100100
int main() {
    int vetor[MAXN], diferenca[MAXN];
    int n, resposta = 1;
    scanf("%d", &n);
    if (n == 1 || n == 2) {
        printf("1\n");
        return 0;
    }
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);
    for (int i = 1; i < n; i++) diferenca[i] = vetor[i] - vetor[i - 1];
    diferenca[0] = diferenca[1];
    for (int i = 1; i < n; i++)
        if (diferenca[i] != diferenca[i - 1]) {
            resposta++;
            diferenca[i] = diferenca[i + 1];
        }
    printf("%d\n", resposta);
    return 0;
}
