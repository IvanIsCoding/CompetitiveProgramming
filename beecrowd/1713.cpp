// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1713
#include <cstdio>
#define MAXN 100
#define MODULO 10000
struct Matrix {
    int mat[MAXN][MAXN];
};
int ordem, ini, fim, tam;
Matrix identity, base;
Matrix multiplication(Matrix A, Matrix B) {
    Matrix answer;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            answer.mat[i][j] = 0;
            for (int k = 0; k < ordem; k++) {
                answer.mat[i][j] =
                    (answer.mat[i][j] + (A.mat[i][k] * B.mat[k][j] % MODULO)) %
                    MODULO;
            }
        }
    }
    return answer;
}
Matrix exponentiation(int expo) {
    if (expo == 0) return identity;
    if (expo == 1) return base;
    if (expo % 2 == 0) {
        Matrix temp = exponentiation(expo / 2);
        return multiplication(temp, temp);
    }
    return multiplication(base, exponentiation(expo - 1));
}
int main() {
    while (scanf("%d %d", &ordem, &tam) != EOF) {
        scanf("%d %d", &ini, &fim);
        ini--;
        fim--;
        for (int i = 0; i < ordem; i++) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            for (int j = 0; j < ordem; j++) {
                base.mat[i][j] = 0;
            }
            base.mat[i][a - 1]++;
            base.mat[i][b - 1]++;
            base.mat[i][c - 1]++;
            base.mat[i][d - 1]++;
        }
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                identity.mat[i][j] = (i == j);
            }
        }
        Matrix exibir = exponentiation(tam);
        printf("%d\n", exibir.mat[ini][fim]);
    }
    return 0;
}
