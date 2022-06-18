// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2553
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MP make_pair
using namespace std;
const int NEG = -41;
const int MAXN = 41;
const int MAXV = 801;
int n, ing_v, ing_a, custo_v[MAXN], custo_a[MAXN], dp[MAXN][MAXV][MAXV];
int solve(int davez, int ing1, int ing2) {
    if (ing1 < 0 || ing2 < 0) return NEG;
    if (davez == n + 1) return 0;
    if (dp[davez][ing1][ing2] >= 0) return dp[davez][ing1][ing2];
    return dp[davez][ing1][ing2] =
               max(1 + solve(davez + 1, ing1 + custo_v[davez],
                             ing2 + custo_a[davez]),
                   solve(davez + 1, ing1, ing2));
}
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &ing_v, &ing_a);
        for (int i = 1; i <= n; i++) scanf("%d %d", &custo_v[i], &custo_a[i]);
        printf("%d\n", solve(1, ing_v, ing_a));
    }
    return 0;
}
