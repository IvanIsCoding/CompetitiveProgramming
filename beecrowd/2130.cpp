// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2130
#include <algorithm>
#include <cstdio>
#define MAXN 110
#define LIMIT 999999
using namespace std;
int matriz[MAXN][MAXN][MAXN];
int main() {
    int n, m, c, instacia = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("Instancia %d\n", instacia++);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++)
                    matriz[i][j][k] = (i == j) ? 0 : LIMIT;
        while (m--) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            matriz[u][v][0] = min(peso, matriz[u][v][0]);
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    matriz[i][j][k] =
                        min(matriz[i][j][k - 1],
                            matriz[i][k][k - 1] + matriz[k][j][k - 1]);
                }
            }
        }
        scanf("%d", &c);
        while (c--) {
            int inicio, fim, escalas;
            scanf("%d %d %d", &inicio, &fim, &escalas);
            printf("%d\n", matriz[inicio][fim][escalas] != LIMIT
                               ? matriz[inicio][fim][escalas]
                               : -1);
        }
        printf("\n");
    }
    return 0;
}
