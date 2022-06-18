// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2401
#include <cstdio>
int vetor[10];
int main() {
    int n, resposta = 1;
    scanf("%d", &n);
    while (n--) {
        int x;
        char op;
        scanf("%d %c", &x, &op);
        if (op == '*')
            vetor[x]++;
        else
            vetor[x]--;
    }
    vetor[3] += 2 * vetor[9];
    vetor[2] += 2 * vetor[4];
    vetor[2] += 3 * vetor[8];
    vetor[2] += vetor[6];
    vetor[3] += vetor[6];
    while (vetor[2]--) resposta *= 2;
    while (vetor[3]--) resposta *= 3;
    while (vetor[5]--) resposta *= 5;
    while (vetor[7]--) resposta *= 7;
    printf("%d\n", resposta);
    return 0;
}
