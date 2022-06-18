// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2107
#include <cstdio>
int X[5], Y[5], Z[5];
inline int simplifica(int k) {
    if (k == 0) return 0;
    if (k > 0) return 1;
    return -1;
}
char mesmo_semiplano(int A, int B, int C, int D, int E) {
    int cof1 =
        Y[A] * (Z[B] - Z[C]) - Z[A] * (Y[B] - Y[C]) + Y[B] * Z[C] - Y[C] * Z[B];
    int cof2 =
        X[A] * (Z[B] - Z[C]) - Z[A] * (X[B] - X[C]) + X[B] * Z[C] - X[C] * Z[B];
    cof2 *= -1;
    int cof3 =
        X[A] * (Y[B] - Y[C]) - Y[A] * (X[B] - X[C]) + X[B] * Y[C] - X[C] * Y[B];
    int cof4 = X[A] * (Y[B] * Z[C] - Y[C] * Z[B]) -
               Y[A] * (X[B] * Z[C] - X[C] * Z[B]) +
               Z[A] * (X[B] * Y[C] - X[C] * Y[B]);
    cof4 *= -1;
    int val1 = X[D] * cof1 + Y[D] * cof2 + Z[D] * cof3 + cof4;
    int val2 = X[E] * cof1 + Y[E] * cof2 + Z[E] * cof3 + cof4;
    if (simplifica(val1) * simplifica(val2) == -1) return 'S';
    return 'N';
}
int main() {
    while (scanf("%d %d %d", &X[0], &Y[0], &Z[0]) != EOF) {
        for (int i = 1; i <= 4; i++) {
            scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
        }
        printf("%c", mesmo_semiplano(1, 2, 3, 0, 4));
        printf("%c", mesmo_semiplano(0, 2, 3, 1, 4));
        printf("%c", mesmo_semiplano(0, 1, 3, 2, 4));
        printf("%c", mesmo_semiplano(0, 1, 2, 3, 4));
        printf("\n");
    }
    return 0;
}
