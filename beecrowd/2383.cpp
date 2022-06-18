// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2383
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300;
int dp[MAXN][MAXN], N, K;
int solve(int tam, int resta) {
    if (dp[tam][resta] != -1) return dp[tam][resta];
    if (tam == 0 || resta == 1) return dp[tam][resta] = tam;
    int best = tam;
    for (int testa = 1; testa <= tam; testa++) {
        best = min(best, 1 + max(solve(testa - 1, resta - 1),
                                 solve(tam - testa, resta)));
    }
    return dp[tam][resta] = best;
}
int main() {
    cin >> N >> K;
    int logaritmo = (int)ceil(log2(N));
    if (K >= logaritmo) {
        cout << logaritmo << endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(N, K) << endl;
    return 0;
}
