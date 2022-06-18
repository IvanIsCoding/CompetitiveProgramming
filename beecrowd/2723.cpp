// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2723
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
int dp[MAXN][7][7], n, vetor[MAXN], TC;
inline int solve(int i, int a, int b) {
    int c = min(a, b);
    a -= c;
    b -= c;
    if (a < b) swap(a, b);
    if (a - b > 5) return 0;
    if (dp[i][a][b] != -1) {
        return dp[i][a][b];
    }
    if (i == n + 1) return dp[i][a][b] = 1;
    return dp[i][a][b] =
               solve(i + 1, a + vetor[i], b) || solve(i + 1, a, b + vetor[i]);
}
int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vetor[i]);
        }
        if (solve(1, 0, 0))
            printf("Feliz Natal!\n");
        else
            printf("Ho Ho Ho!\n");
    }
    return 0;
}
