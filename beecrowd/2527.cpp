// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2527
#include <cstdio>
#define MAXN 1010
int vis[MAXN][6 * MAXN], n, m;
double dp[MAXN][6 * MAXN];
double solve(int davez, int valor) {
    if (valor <= 0) return 1.0;
    if (davez == n + 1) return 0.0;
    if (vis[davez][valor]) return dp[davez][valor];
    vis[davez][valor] = 1;
    return dp[davez][valor] =
               (solve(davez + 1, valor - 1) + solve(davez + 1, valor - 2) +
                solve(davez + 1, valor - 3) + solve(davez + 1, valor - 4) +
                solve(davez + 1, valor - 5) + solve(davez + 1, valor - 6)) /
               6.0;
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 0; j <= m; j++) {
                vis[i][j] = 0;
            }
        }
        printf("%.4lf\n", solve(1, m));
    }
    return 0;
}
