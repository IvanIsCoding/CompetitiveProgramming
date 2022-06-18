// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2088
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 17
#define MAXL 65546
using namespace std;
double dp[MAXN][MAXL], dist[MAXN][MAXN];
int n, visitado[MAXN][MAXL], X[MAXN], Y[MAXN];
double tsp(int pos, int bitmask) {
    if (bitmask == (1 << (n + 1)) - 1) return dist[pos][0];
    if (visitado[pos][bitmask] != -1) return dp[pos][bitmask];
    visitado[pos][bitmask] = 1;
    double ans = 1000000000;
    for (int nxt = 0; nxt <= n; nxt++) {
        if (nxt != pos && !(bitmask & (1 << nxt))) {
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
        }
    }
    return dp[pos][bitmask] = ans;
}
int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i <= n; i++) {
            scanf("%d %d", &X[i], &Y[i]);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dist[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]);
            }
        }
        memset(visitado, -1, sizeof(visitado));
        printf("%.2lf\n", tsp(0, 1));
    }
    return 0;
}
