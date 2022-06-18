// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1757
#include <algorithm>
#include <cstdio>
#define MAXN 101
using namespace std;
int matriz[MAXN][MAXN], n, m, TC, custo, distancia[MAXN], processado[MAXN];
int main() {
    scanf("%d", &TC);
    while (TC--) {
        custo = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = 0;
            }
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            matriz[u][v] = matriz[v][u] = 1;
        }
        for (int i = 0; i < n; i++) {
            processado[i] = 0;
            distancia[i] = matriz[0][i];
        }
        processado[0] = 1;
        while (true) {
            int davez = -1;
            int menor = 2;
            for (int i = 0; i < n; i++) {
                if (!processado[i] && distancia[i] < menor) {
                    menor = distancia[i];
                    davez = i;
                }
            }
            if (davez == -1) break;
            processado[davez] = 1;
            custo += menor;
            for (int i = 0; i < n; i++) {
                distancia[i] = min(distancia[i], matriz[davez][i]);
            }
        }
        printf("%d\n", custo);
    }
    return 0;
}
