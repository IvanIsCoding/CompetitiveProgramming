// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2458
#include <cstdio>
using namespace std;
#define MAXN 550
int n;
char matriz[MAXN][MAXN];
bool visitado[MAXN][MAXN];
int elegivel(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n || visitado[x][y]) return 0;
    return 1;
}
int dfs(int x, int y) {
    if (!elegivel(x, y)) return 0;
    int retornar = 1;
    visitado[x][y] = true;
    if (elegivel(x - 1, y) && matriz[x - 1][y] == 'V')
        retornar += dfs(x - 1, y);
    if (elegivel(x + 1, y) && matriz[x + 1][y] == 'A')
        retornar += dfs(x + 1, y);
    if (elegivel(x, y - 1) && matriz[x][y - 1] == '>')
        retornar += dfs(x, y - 1);
    if (elegivel(x, y + 1) && matriz[x][y + 1] == '<')
        retornar += dfs(x, y + 1);
    return retornar;
}
int main() {
    scanf("%d", &n);
    int resposta = n * n;
    for (int i = 0; i < n; i++) scanf("%s", matriz[i]);
    for (int i = 0; i < n; i++) {
        if (matriz[0][i] == 'A') resposta -= dfs(0, i);
        if (matriz[i][0] == '<') resposta -= dfs(i, 0);
        if (matriz[n - 1][i] == 'V') resposta -= dfs(n - 1, i);
        if (matriz[i][n - 1] == '>') resposta -= dfs(i, n - 1);
    }
    printf("%d\n", resposta);
    return 0;
}
