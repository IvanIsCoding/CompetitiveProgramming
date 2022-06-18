// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2441
#include <cstdio>
#define MAXN 601
int vetor[MAXN];
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i < 200; i++) {
        vetor[a + i] = 1;
        vetor[b + i] = 1;
        vetor[c + i] = 1;
    }
    int resposta = 0;
    for (int i = 0; i < 600; i++) {
        if (vetor[i] == 0) resposta++;
    }
    printf("%d\n", resposta * 100);
    return 0;
}
