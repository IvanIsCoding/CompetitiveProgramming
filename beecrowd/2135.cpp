// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2135
#include <cstdio>
int vetor[101], soma[101];
int main() {
    int n, instancia = 1;
    while (scanf("%d", &n) != EOF) {
        int possivel = 0;
        printf("Instancia %d\n", instancia++);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vetor[i]);
            soma[i] = soma[i - 1] + vetor[i];
            if (!possivel && soma[i - 1] == vetor[i]) {
                printf("%d\n", vetor[i]);
                possivel = 1;
            }
        }
        if (!possivel) printf("nao achei\n");
        printf("\n");
    }
    return 0;
}
