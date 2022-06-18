// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2785
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;
const int INF = 1e9;

int soma[MAXN][MAXN], matriz[MAXN][MAXN], dp[MAXN][MAXN], N;

int calcula(int id, int a, int b) { return soma[id][b] - soma[id][a - 1]; }

int solve(int linha, int pos) {
    if (linha == N + 1) return 0;
    if (dp[linha][pos] != -1) return dp[linha][pos];
    if (pos <= 0 || linha + pos - 1 > N) return dp[linha][pos] = INF;
    int agora = calcula(linha, pos, pos + linha - 1);
    int proxima = min(solve(linha + 1, pos - 1), solve(linha + 1, pos));
    return dp[linha][pos] = agora + proxima;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &matriz[i][j]);
            soma[i][j] = soma[i][j - 1] + matriz[i][j];
        }
    }
    int resposta = solve(1, 1);
    for (int i = 2; i <= N; i++) resposta = min(resposta, solve(1, i));
    printf("%d\n", resposta);
    return 0;
}