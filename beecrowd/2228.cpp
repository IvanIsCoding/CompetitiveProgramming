// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2228
#include <cstdio>
#define MAXN 110
#define MAXL 11000
int tab[MAXN][MAXL], n, x, y, soma, valores[MAXN], teste = 1;
bool verdade;
void dp(int obj, int valor) {
    if (verdade) return;
    if (tab[obj][valor] != -1) return;
    tab[obj][valor] = 1;
    if (valor == soma) {
        verdade = true;
        return;
    }
    if (obj > n || valor > soma) return;
    dp(obj + 1, valor + valores[obj]);
    dp(obj + 1, valor);
}
int main() {
    while (scanf("%d %d %d", &x, &y, &n)) {
        if (n == 0 && x == 0 && y == 0) break;
        printf("Teste %d\n", teste++);
        verdade = false;
        soma = (x + y);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &valores[i]);
            soma += valores[i];
        }
        if (soma % 2) {
            printf("N\n\n");
            continue;
        }
        for (int i = 1; i <= n + 3; i++)
            for (int j = 0; j <= soma + 10; j++) tab[i][j] = -1;
        soma /= 2;
        soma -= x;
        dp(1, 0);
        if (verdade)
            printf("S\n\n");
        else
            printf("N\n\n");
    }
    return 0;
}
