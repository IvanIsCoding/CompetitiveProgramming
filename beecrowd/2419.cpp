// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2419
#include <cstdio>
#define MAXN 1010
char matriz[MAXN][MAXN];
int main() {
    int n, m, resposta = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", matriz[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matriz[i][j] == '#') {
                resposta +=
                    int(i == 0 || i == n - 1 || j == 0 || j == m - 1 ||
                        matriz[i + 1][j] == '.' || matriz[i - 1][j] == '.' ||
                        matriz[i][j + 1] == '.' || matriz[i][j - 1] == '.');
            }
    printf("%d\n", resposta);
    return 0;
}
