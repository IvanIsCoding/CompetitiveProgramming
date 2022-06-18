// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2182
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 10010
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
using namespace std;
int pai[MAXN], ruas[MAXN], buracos[MAXN];
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y, int esburacados) {
    x = find(x);
    y = find(y);
    if (x < y) swap(x, y);
    pai[y] = x;
    if (x != y) {
        buracos[x] += buracos[y];
        ruas[x] += ruas[y];
    }
    ruas[x]++;
    buracos[x] += esburacados;
}
int main() {
    int n, m;
    getint(n);
    getint(m);
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
    }
    while (m--) {
        int u, v, buracos;
        getint(u);
        getint(v);
        getint(buracos);
        join(u, v, buracos);
    }
    for (int i = n; i >= 1; i--) {
        if (buracos[find(i)] == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    int resp = 1, respruas = ruas[find(1)], respburacos = buracos[find(1)];
    for (int i = 2; i <= n; i++) {
        int auxruas = ruas[find(i)], auxburacos = buracos[find(i)];
        if (auxburacos * respruas <= respburacos * auxruas) {
            resp = i;
            respruas = auxruas;
            respburacos = auxburacos;
        }
    }
    printf("%d\n", resp);
    return 0;
}
