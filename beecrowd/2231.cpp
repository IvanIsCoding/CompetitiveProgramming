// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2231
#include <algorithm>
#include <cstdio>
using namespace std;
int temperatura[10000], n, m;
int main() {
    int i, maximo, minimo, soma, teste = 1;
    while (scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        soma = 0;
        for (i = 0; i < m; i++) {
            scanf("%d", &temperatura[i]);
            soma += temperatura[i];
        }
        maximo = soma;
        minimo = soma;
        for (i = m; i < n; i++) {
            scanf("%d", &temperatura[i]);
            soma = soma + temperatura[i] - temperatura[i - m];
            maximo = max(maximo, soma);
            minimo = min(minimo, soma);
        }
        printf("Teste %d\n%d %d\n\n", teste++, minimo / m, maximo / m);
    }
    return 0;
}
