// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2329
#include <cstdio>
#define MAX 10000
int main() {
    int pessoas, paes, maximo = 0, vetor[MAX], tamanho, teste;
    scanf("%d %d", &pessoas, &paes);
    for (int i = 0; i < paes; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] > maximo) maximo = vetor[i];
    }
    int ini = 1, fim = maximo, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        teste = 0;
        for (int i = 0; i < paes; i++) teste += vetor[i] / meio;
        if (teste >= pessoas) {
            tamanho = meio;
            ini = meio + 1;
        } else
            fim = meio - 1;
    }
    printf("%d\n", tamanho);
    return 0;
}
