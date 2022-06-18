// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2566
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 110;
const int INF = 1e8;
int matriz_a[MAXN][MAXN], dist_a[MAXN], matriz_b[MAXN][MAXN], dist_b[MAXN], n,
    m, processado_a[MAXN], processado_b[MAXN];
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            dist_a[i] = INF;
            dist_b[i] = INF;
            processado_a[i] = 0;
            processado_b[i] = 0;
            for (int j = 1; j <= n; j++) {
                matriz_a[i][j] = matriz_b[i][j] = INF;
            }
            matriz_a[i][i] = matriz_b[i][i] = 0;
        }
        while (m--) {
            int u, v, tipo, peso;
            scanf("%d %d %d %d", &u, &v, &tipo, &peso);
            if (tipo == 0)
                matriz_a[u][v] = peso;
            else
                matriz_b[u][v] = peso;
        }
        processado_a[1] = 0;
        dist_a[1] = 0;
        while (true) {
            int davez = -1;
            int menor = INF;
            for (int i = 1; i <= n; i++) {
                if (processado_a[i]) continue;
                if (dist_a[i] < menor) {
                    menor = dist_a[i];
                    davez = i;
                }
            }
            if (davez == -1) break;
            for (int i = 1; i <= n; i++)
                dist_a[i] = min(dist_a[i], dist_a[davez] + matriz_a[davez][i]);
            processado_a[davez] = 1;
        }
        dist_b[1] = 0;
        processado_b[1] = 0;
        while (true) {
            int davez = -1;
            int menor = INF;
            for (int i = 1; i <= n; i++) {
                if (processado_b[i]) continue;
                if (dist_b[i] < menor) {
                    menor = dist_b[i];
                    davez = i;
                }
            }
            if (davez == -1) break;
            for (int i = 1; i <= n; i++)
                dist_b[i] = min(dist_b[i], dist_b[davez] + matriz_b[davez][i]);
            processado_b[davez] = 1;
        }
        printf("%d\n", min(dist_a[n], dist_b[n]));
    }
    return 0;
}
