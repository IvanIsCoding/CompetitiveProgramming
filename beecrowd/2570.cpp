// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2570
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
int cor_coluna[MAXN], cor_linha[MAXN], ultima_linha[MAXN], ultima_coluna[MAXN],
    atual, n, m, q, qtd[4];
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        cor_linha[i] = -1;
        ultima_linha[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        cor_coluna[i] = -1;
        ultima_coluna[i] = -1;
    }
    for (int i = 1; i <= q; i++) {
        char op;
        int pos;
        scanf(" %c %d", &op, &pos);
        if (op == 'L') {
            ultima_linha[pos] = i;
            cor_linha[pos] = atual;
        } else {
            ultima_coluna[pos] = i;
            cor_coluna[pos] = atual;
        }
        atual = (atual + 1) % 4;
    }
    for (int i = 1; i <= n; i++) {
        int thelast = ultima_linha[i];
        int tot = m;
        int vaipara = cor_linha[i];
        for (int j = 1; j <= m; j++) {
            if (ultima_coluna[j] > thelast && cor_coluna[j] != vaipara) {
                tot--;
                if (cor_coluna[j] != -1) {
                    qtd[cor_coluna[j]]++;
                }
            }
        }
        if (vaipara != -1) qtd[vaipara] += tot;
    }
    printf("R%d H%d C%d P%d\n", qtd[0], qtd[1], qtd[2], qtd[3]);
    return 0;
}
