// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2246
#include <cstdio>
#define MAXN 201
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int matriz[MAXN][MAXN], contador, resp, processado[MAXN][MAXN], n, m;
inline int valido(int x, int y, int cor) {
    return x >= 1 && x <= n && y >= 1 && y <= m && matriz[x][y] == cor &&
           !processado[x][y];
}
void dfs(int x, int y) {
    // printf("%d %d\n",x,y);
    contador++;
    processado[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valido(nx, ny, matriz[x][y])) dfs(nx, ny);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    resp = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (processado[i][j]) continue;
            contador = 0;
            dfs(i, j);
            if (contador < resp) resp = contador;
        }
    }
    printf("%d\n", resp);
    return 0;
}
