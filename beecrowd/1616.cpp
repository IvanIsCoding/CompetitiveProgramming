// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1616
#include <cstdio>
typedef long long ll;
const int MAXN = 1e3 + 1;
const ll MOD = 1e9 + 7;
ll dp[MAXN][MAXN], fatorial[MAXN];
int main() {
    int a, b;
    fatorial[0] = 1;
    fatorial[1] = 1;
    for (ll i = 2; i < MAXN; i++) {
        fatorial[i] = (fatorial[i - 1] * i) % MOD;
    }
    for (int i = 1; i < MAXN; i++) {
        dp[1][i] = 1;
        dp[i][i] = fatorial[i];
    }
    for (ll i = 2; i < MAXN; i++) {
        for (ll j = i + 1; j < MAXN; j++) {
            dp[i][j] = (i * (dp[i][j - 1] + dp[i - 1][j - 1])) % MOD;
        }
    }
    while (scanf("%d %d", &a, &b) && (a || b)) {
        printf("%lld\n", dp[b][a]);
    }
    return 0;
}
