// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2300
#include <cstdio>
#include <vector>
#define MAXN 110
using namespace std;
int pai[MAXN], peso[MAXN], conjuntos, n, m, teste;
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    conjuntos--;
    if (peso[x] < peso[y])
        pai[x] = y;
    else if (peso[x] > peso[y])
        pai[y] = x;
    else {
        pai[x] = y;
        peso[y]++;
    }
}
int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        printf("Teste %d\n", ++teste);
        conjuntos = n;
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 0;
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            join(u, v);
        }
        if (conjuntos == 1)
            printf("normal\n\n");
        else
            printf("falha\n\n");
    }
    return 0;
}
