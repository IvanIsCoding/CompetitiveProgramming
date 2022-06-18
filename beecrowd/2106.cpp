// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2106
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 18
#define MAXL 262154
#define LIMIT 1000000000
using namespace std;
int dp[MAXL], preco[MAXN][MAXN], n;
int func(int bitmask, int vez) {
    if (vez == n) return 0;
    if (dp[bitmask] != -1) return dp[bitmask];
    int resposta = LIMIT;
    for (int prox = 0; prox < n; prox++) {
        if (!(bitmask & (1 << prox))) {
            resposta = min(resposta, preco[prox][vez] +
                                         func(bitmask | (1 << prox), vez + 1));
        }
    }
    return dp[bitmask] = resposta;
}
int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &preco[i][j]);
            }
        }
        for (int j = 0; j <= (1 << n) - 1; j++) {
            dp[j] = -1;
        }
        printf("%d\n", func(0, 0));
    }
    return 0;
}
