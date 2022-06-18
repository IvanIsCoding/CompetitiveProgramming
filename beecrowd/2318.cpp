// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2318
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 3;
inline int max(int a, int b, int c) { return max(a, max(b, c)); }
int matriz[MAXN][MAXN], soma[MAXN], acumulada[MAXN], diag1, dig2, x[MAXN],
    y[MAXN], zeros;
void exibe() {
    for (int linha = 0; linha < MAXN; linha++) {
        printf("%d", matriz[linha][0]);
        for (int coluna = 1; coluna < MAXN; coluna++) {
            printf(" %d", matriz[linha][coluna]);
        }
        printf("\n");
    }
}
int checa() {
    memset(soma, 0, sizeof(soma));
    memset(acumulada, 0, sizeof(acumulada));
    for (int linha = 0; linha < MAXN; linha++) {
        for (int coluna = 0; coluna < MAXN; coluna++) {
            if (matriz[linha][coluna] < 0) return 0;
            soma[linha] += matriz[linha][coluna];
        }
    }
    for (int linha = 0; linha < MAXN; linha++) {
        for (int coluna = 0; coluna < MAXN; coluna++) {
            acumulada[coluna] += matriz[linha][coluna];
        }
    }
    diag1 = matriz[0][0] + matriz[1][1] + matriz[2][2];
    dig2 = matriz[2][0] + matriz[1][1] + matriz[0][2];
    if (diag1 != dig2) return 0;
    for (int i = 0; i < MAXN; i++) {
        if (soma[i] != diag1) return 0;
        if (acumulada[i] != diag1) return 0;
    }
    return 1;
}
void solve1() {
    memset(soma, 0, sizeof(soma));
    for (int linha = 0; linha < MAXN; linha++) {
        for (int coluna = 0; coluna < MAXN; coluna++) {
            soma[linha] += matriz[linha][coluna];
        }
    }
    int exemplo = max(soma[0], soma[1], soma[2]);
    matriz[x[0]][y[0]] = exemplo - soma[x[0]];
}
void solve2() {
    memset(soma, 0, sizeof(soma));
    memset(acumulada, 0, sizeof(acumulada));
    for (int linha = 0; linha < MAXN; linha++) {
        for (int coluna = 0; coluna < MAXN; coluna++) {
            soma[linha] += matriz[linha][coluna];
        }
    }
    for (int linha = 0; linha < MAXN; linha++) {
        for (int coluna = 0; coluna < MAXN; coluna++) {
            acumulada[coluna] += matriz[linha][coluna];
        }
    }
    int exemplo = max(soma[0], soma[1], soma[2]);
    if (x[0] != x[1]) {
        matriz[x[0]][y[0]] = exemplo - soma[x[0]];
        matriz[x[1]][y[1]] = exemplo - soma[x[1]];
    } else {
        matriz[x[0]][y[0]] = exemplo - acumulada[y[0]];
        matriz[x[1]][y[1]] = exemplo - acumulada[y[1]];
    }
}
int main() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] == 0) {
                x[zeros] = i;
                y[zeros++] = j;
            }
        }
    }
    if (zeros == 0) {
        exibe();
        return 0;
    }
    if (zeros == 1) {
        solve1();
        exibe();
        return 0;
    }
    if (zeros == 2) {
        solve2();
        exibe();
        return 0;
    }
    for (int chute = 1; chute <= 20000; chute++) {
        matriz[x[0]][y[0]] = matriz[x[1]][y[1]] = 0;
        matriz[x[2]][y[2]] = chute;
        solve2();
        if (checa()) {
            exibe();
            return 0;
        }
    }
    return 0;
}
