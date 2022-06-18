// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2425
#include <cstdio>
#define MAXN 1010
int caixas[11], c, n, resposta, disponivel, t, d;
int min() {
    int indice = 0;
    for (int i = 1; i < c; i++) {
        if (caixas[i] < caixas[indice]) indice = i;
    }
    return indice;
}
int main() {
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t, &d);
        disponivel = min();
        if (t > caixas[disponivel])
            caixas[disponivel] = t + d;
        else {
            if (caixas[disponivel] - t > 20) resposta++;
            caixas[disponivel] += d;
        }
    }
    printf("%d\n", resposta);
    return 0;
}
