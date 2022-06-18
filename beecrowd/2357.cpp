// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2357
#include <cstdio>
#define MAXN 100001
int pai[MAXN], peso[MAXN], n, m, seguro;
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] > peso[y]) {
        pai[y] = x;
    } else if (peso[y] > peso[x]) {
        pai[x] = y;
    } else {
        pai[x] = y;
        peso[y]++;
    }
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
        }
        seguro = 1;
        for (int i = 1; i <= m; i++) {
            int u, v;
            getint(u);
            getint(v);
            if (!seguro) continue;
            if (find(u) == find(v)) seguro = 0;
            join(u, v);
        }
        if (seguro)
            printf("Seguro\n");
        else
            printf("Inseguro\n");
    }
    return 0;
}
