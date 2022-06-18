// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2327
#include <cstdio>
#define MAX_N 1000
int main() {
    int matriz[MAX_N][MAX_N];
    int soma1[MAX_N], soma2[MAX_N];
    int ordem, i, j, diagonal1 = 0, diagonal2 = 0;
    scanf("%d", &ordem);
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            int davez;
            scanf("%d", &davez);
            matriz[i][j] = davez;
            soma1[i] = soma1[i] + matriz[i][j];
            soma2[j] = soma2[j] + matriz[i][j];
            if (i == j) diagonal1 += davez;
            if (i + j + 1 == ordem) diagonal2 += davez;
        }
    }
    int referencia = soma1[0];
    for (i = 0; i < ordem; i++) {
        if (soma1[i] != referencia || soma2[i] != referencia) {
            printf("-1\n");
            return 0;
        }
    }
    if (diagonal1 != referencia || diagonal2 != referencia) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", referencia);
    return 0;
}
