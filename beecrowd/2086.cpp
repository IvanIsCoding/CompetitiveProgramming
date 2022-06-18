// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2086
#include <algorithm>
#include <cstdio>
#define MAXN 101
using namespace std;
int matriz[MAXN][MAXN], n, m, q;
int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                matriz[i][j] = 2001;
            }
            matriz[i][i] = 0;
        }
        while (m--) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            matriz[u][v] = peso;
            matriz[v][u] = peso;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    matriz[i][j] =
                        min(matriz[i][j], max(matriz[i][k], matriz[k][j]));
                }
            }
        }
        scanf("%d", &q);
        while (q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", matriz[u][v]);
        }
    }
    return 0;
}
