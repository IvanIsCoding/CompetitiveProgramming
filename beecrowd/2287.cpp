// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2287
#include <cstdio>
#include <cstring>
int possivel[6][11], digito1[20], digito2[20], n, teste;
int main() {
    while (scanf("%d", &n) && n) {
        memset(possivel, 1, sizeof(possivel));
        for (int vez = 1; vez <= n; vez++) {
            for (char c = 'A'; c <= 'E'; c++) {
                scanf("%d %d", &digito1[c - 'A'], &digito2[c - 'A']);
            }
            for (int digitodavez = 0; digitodavez < 6; digitodavez++) {
                char c;
                scanf(" %c", &c);
                for (int novodigito = 0; novodigito <= 9; novodigito++) {
                    if (novodigito == digito1[c - 'A'] ||
                        novodigito == digito2[c - 'A'])
                        continue;
                    possivel[digitodavez][novodigito] = 0;
                }
            }
        }
        printf("Teste %d\n", ++teste);
        for (int digitodavez = 0; digitodavez < 6; digitodavez++) {
            for (int novodigito = 0; novodigito <= 9; novodigito++) {
                if (possivel[digitodavez][novodigito]) {
                    printf("%d ", novodigito);
                }
            }
        }
        printf("\n\n");
    }
    return 0;
}
