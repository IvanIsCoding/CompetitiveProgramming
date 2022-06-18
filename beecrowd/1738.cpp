// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1738
#include <cstdio>
#include <cstring>
#define MAXN 201
int matriz[MAXN][MAXN][MAXN], n;
int main() {
    while (scanf("%d", &n) && n) {
        for (char caractere = 'a'; caractere <= 'z'; caractere++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    matriz[caractere][i][j] = 0;
                }
                matriz[caractere][i][i] = 1;
            }
        }
        int ini, fim;
        while (scanf("%d %d", &ini, &fim) && (ini || fim)) {
            char empresas[MAXN];
            scanf("%s", empresas);
            for (int i = 0; i < strlen(empresas); i++) {
                matriz[empresas[i]][ini][fim] = 1;
            }
        }
        for (char caractere = 'a'; caractere <= 'z'; caractere++) {
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        matriz[caractere][i][j] |=
                            matriz[caractere][i][k] & matriz[caractere][k][j];
                    }
                }
            }
        }
        while (scanf("%d %d", &ini, &fim) && (ini || fim)) {
            int possivel = 0;
            for (char caractere = 'a'; caractere <= 'z'; caractere++) {
                if (matriz[caractere][ini][fim]) {
                    possivel = 1;
                    printf("%c", caractere);
                }
            }
            if (!possivel) printf("-");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
