// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2337
#include <cstdio>
#include <cstring>
#define CARA 0
#define COROA 1
typedef long long ll;
ll dp[41][2], n;
ll solve(ll vez, ll estado) {
    if (dp[vez][estado] != -1) return dp[vez][estado];
    if (vez == n) {
        return 1;
    }
    if (estado == COROA) {
        return dp[vez][estado] = solve(vez + 1, CARA);
    }
    if (estado == CARA) {
        return dp[vez][estado] = solve(vez + 1, CARA) + solve(vez + 1, COROA);
    }
}
int main() {
    while (scanf("%lld", &n) != EOF) {
        memset(dp, -1, sizeof(dp));
        ll emcima = solve(1, CARA) + solve(1, COROA);
        ll embaixo = (1LL << n);
        while (emcima % 2LL == 0 && embaixo % 2LL == 0) {
            emcima /= 2LL;
            embaixo /= 2LL;
        }
        printf("%lld/%lld\n", emcima, embaixo);
    }
    return 0;
}
