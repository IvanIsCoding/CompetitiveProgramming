// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2562
#include <cstdio>
#define MAXN 1001
int pai[MAXN], peso[MAXN], membros[MAXN], n, m;
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
inline void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[y] > peso[x]) {
        pai[x] = y;
        membros[y] += membros[x];
    } else if (peso[x] > peso[y]) {
        pai[y] = x;
        membros[x] += membros[y];
    } else {
        pai[x] = y;
        peso[y]++;
        membros[y] += membros[x];
    }
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
            membros[i] = 1;
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            join(u, v);
        }
        int meu;
        scanf("%d", &meu);
        printf("%d\n", membros[find(meu)]);
    }
    return 0;
}
