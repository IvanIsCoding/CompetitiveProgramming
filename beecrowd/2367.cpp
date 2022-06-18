// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2367
#include <cstdio>
#define MAXN 1001010
int dp[MAXN], proibido[MAXN], n, m;
int solve() {
    for (int i = 0; i <= n; i++) {
        if (dp[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i + j]++;
                proibido[i + j] = j;
            }
        } else if (dp[i] == 1) {
            dp[i + proibido[i]]++;
            proibido[i + proibido[i]] = proibido[i];
        }
    }
    return dp[n];
}
int main() {
    scanf("%d %d", &n, &m);
    if (solve())
        printf("Paula\n");
    else
        printf("Carlos\n");
    return 0;
}
