// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2224
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 16
#define MAXL 65546
#define LIMIT 1e9
using namespace std;
double dp[MAXL], dist[MAXN][MAXN];
int n, X[MAXN], Y[MAXN];
double func(int bitmask) {
    if (dp[bitmask] >= 0) return dp[bitmask];
    double ans = LIMIT;
    for (int i = 0; i < n; i++) {
        if (bitmask & (1 << i)) continue;
        for (int j = 0; j < n; j++) {
            if (j != i && !(bitmask & (1 << j))) {
                ans =
                    min(ans, dist[i][j] + func(bitmask | (1 << i) | (1 << j)));
            }
        }
    }
    return dp[bitmask] = ans;
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        memset(dp, -1.0, sizeof(dp));
        dp[(1 << n) - 1] = 0.0;
        for (int i = 0; i < n; i++) scanf("%d %d", &X[i], &Y[i]);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                dist[i][j] = dist[j][i] = hypot(X[i] - X[j], Y[i] - Y[j]);
            }
        printf("%.2lf\n", func(0));
    }
    return 0;
}
