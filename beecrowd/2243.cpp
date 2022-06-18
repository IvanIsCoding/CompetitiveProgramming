// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2243
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 100010
int resp, dp[MAXN][2], n, vetor[MAXN];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &vetor[i]);
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) dp[i][0] = min(vetor[i], dp[i - 1][0] + 1);
    dp[n][1] = 1;
    for (int i = n - 1; i >= 1; i--) dp[i][1] = min(vetor[i], dp[i + 1][1] + 1);
    for (int i = 1; i <= n; i++) resp = max(resp, min(dp[i][0], dp[i][1]));
    printf("%d\n", resp);
    return 0;
}
