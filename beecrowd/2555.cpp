// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2555
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1001;
const double NEG = -1e9;
double dp[MAXN][MAXN], vetor[MAXN], valor[MAXN];
int n, k;
double solve(int pergunta, int trapacas) {
    if (trapacas == -1) return NEG;
    if (pergunta == n + 1) return 0.0;
    if (dp[pergunta][trapacas] >= 0) return dp[pergunta][trapacas];
    return dp[pergunta][trapacas] =
               max(vetor[pergunta] *
                       (valor[pergunta] + solve(pergunta + 1, trapacas)),
                   valor[pergunta] + solve(pergunta + 1, trapacas - 1));
}
int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &valor[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &vetor[i]);
            vetor[i] *= 0.01;
        }
        memset(dp, -1, sizeof(dp));
        printf("%.2lf\n", solve(1, k));
    }
    return 0;
}
