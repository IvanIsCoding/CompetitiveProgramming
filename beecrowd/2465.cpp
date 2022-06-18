// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2465
#include <cstdio>
#define MAXN 102
int matriz[MAXN][MAXN], processado[MAXN][MAXN], n, xo, yo, resp;
void dfs(int x, int y) {
    if (processado[x][y]) return;
    processado[x][y] = 1;
    if (matriz[x + 1][y] >= matriz[x][y]) dfs(x + 1, y);
    if (matriz[x - 1][y] >= matriz[x][y]) dfs(x - 1, y);
    if (matriz[x][y + 1] >= matriz[x][y]) dfs(x, y + 1);
    if (matriz[x][y - 1] >= matriz[x][y]) dfs(x, y - 1);
}
int main() {
    scanf("%d %d %d", &n, &xo, &yo);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    dfs(xo, yo);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            resp += processado[i][j];
        }
    }
    printf("%d\n", resp);
    return 0;
}
