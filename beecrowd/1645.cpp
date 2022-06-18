// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1645
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[102][102], vetor[102], n, k;
ll solve(ll pos, ll tamanho) {
    if (tamanho == k) return 1;
    if (dp[pos][tamanho] != -1) return dp[pos][tamanho];
    dp[pos][tamanho] = 0;
    for (ll nxt = pos + 1; nxt <= n; nxt++) {
        if (vetor[pos] < vetor[nxt])
            dp[pos][tamanho] += solve(nxt, tamanho + 1);
    }
    return dp[pos][tamanho];
}
int main() {
    while (scanf("%lld %lld", &n, &k) && (n || k)) {
        memset(dp, -1, sizeof(dp));
        for (ll i = 1; i <= n; i++) scanf("%lld", &vetor[i]);
        ll resp = 0;
        for (ll i = 1; i <= n; i++) resp += solve(i, 1);
        printf("%lld\n", resp);
    }
    return 0;
}
