// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2405
#include <cstdio>
#include <vector>
#define MAXN 210
using namespace std;
int matriz[MAXN][MAXN], n, m, x, y, k, resposta;
void dfs(int a, int b) {
    if (a <= 0 || b <= 0 || a > n || b > m) return;
    if (matriz[a][b] == 0) {
        matriz[a][b] = 1;
        dfs(a + 1, b);
        dfs(a - 1, b);
        dfs(a, b + 1);
        dfs(a, b - 1);
        dfs(a + 1, b + 1);
        dfs(a + 1, b - 1);
        dfs(a - 1, b + 1);
        dfs(a - 1, b - 1);
    }
}
int main() {
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (int i = 0; i < k; i++) {
        int w, z;
        scanf("%d %d", &w, &z);
        matriz[w][z] = -1;
    }
    dfs(x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matriz[i][j] == 1) resposta++;
        }
    }
    printf("%d\n", resposta);
    return 0;
}
