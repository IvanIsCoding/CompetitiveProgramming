// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2524
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 10;
int n, m, vetor[MAXN], dp[MAXN][MAXN];
int mod(int x) {
    if (x < 0) x += n;
    return x % n;
}
int solve(int davez, int aguenta) {
    if (davez == m + 1) {
        if (aguenta == 0) return 0;
        return -5 * MAXN;
    }
    if (dp[davez][aguenta] != -1) return dp[davez][aguenta];
    return dp[davez][aguenta] =
               max(solve(davez + 1, aguenta),
                   1 + solve(davez + 1, mod(aguenta + vetor[davez])));
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= m; i++) {
            scanf("%d", &vetor[i]);
            vetor[i] %= n;
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(1, 0));
    }
    return 0;
}
