// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2471
#include <cstdio>
#define MAXN 52
int matriz[MAXN][MAXN];
int soma[MAXN][MAXN];
int acumulada[MAXN][MAXN];
int n;
int main() {
    scanf("%d", &n);
    for (int linha = 1; linha <= n; linha++) {
        for (int coluna = 1; coluna <= n; coluna++) {
            scanf("%d", &matriz[linha][coluna]);
            soma[linha][coluna] =
                soma[linha][coluna - 1] + matriz[linha][coluna];
        }
    }
    for (int coluna = 1; coluna <= n; coluna++) {
        for (int linha = 1; linha <= n; linha++) {
            acumulada[linha][coluna] =
                acumulada[linha - 1][coluna] + matriz[linha][coluna];
        }
    }
    int moore = 0, escolhida = -1;
    for (int linha = 1; linha <= n; linha++) {
        if (moore == 0) {
            escolhida = soma[linha][n];
            moore = 1;
        } else if (soma[linha][n] == escolhida) {
            moore++;
        } else
            moore--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (soma[i][n] != escolhida && acumulada[n][j] != escolhida) {
                printf("%d %d\n",
                       (2 * escolhida - acumulada[n][j] - soma[i][n]) / 2 +
                           matriz[i][j],
                       matriz[i][j]);
            }
        }
    }
    return 0;
}
