// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2664
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXT = 52;
const int MOD = 1e9 + 7;
int N, M, T;
int dp[MAXT][MAXN];
int solve(int pos, int val) {
    if (dp[pos][val] != -1) return dp[pos][val];
    if (val < M || val > N) return dp[pos][val] = 0;
    if (pos == T) return dp[pos][val] = 1;
    int ret = (solve(pos + 1, val - 1) + solve(pos + 1, val + 1)) % MOD;
    return dp[pos][val] = ret;
}
int main() {
    int resp = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &T, &M, &N);
    for (int i = M; i <= N; i++) {
        resp = (resp + solve(1, i)) % MOD;
    }
    printf("%d\n", resp);
    return 0;
}
