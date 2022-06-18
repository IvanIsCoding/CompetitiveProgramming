// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2299
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1001], c, f, n, d, teste;
int main() {
    while (scanf("%d %d", &c, &f) && (c || f)) {
        memset(dp, 0, sizeof(dp));
        while (f--) {
            scanf("%d %d", &n, &d);
            for (int i = c; i >= n; i--) {
                dp[i] = max(dp[i], dp[i - n] + d);
            }
        }
        int resp = 0;
        for (int i = 0; i <= c; i++) resp = max(resp, dp[i]);
        printf("Teste %d\n%d\n\n", ++teste, resp);
    }
    return 0;
}
