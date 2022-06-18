// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2191
#include <cstdio>
#define max(A, B) (A > B) ? (A) : (B)
int main() {
    int n, teste = 1;
    while (scanf("%d", &n) && n) {
        int saldo_maximo = 0, saldo = 0, inicio = 0, primeiro = 0, ultimo = 0;
        printf("Teste %d\n", teste++);
        for (int contador = 0; contador < n; contador++) {
            int x, y;
            scanf("%d %d", &x, &y);
            saldo += (x - y);
            if (saldo >= 0) {
                if (saldo > saldo_maximo ||
                    (saldo == saldo_maximo &&
                     ultimo - primeiro < contador - inicio)) {
                    saldo_maximo = saldo;
                    primeiro = inicio + 1;
                    ultimo = contador + 1;
                }
            } else {
                saldo = 0;
                inicio = contador + 1;
            }
        }
        if (!saldo_maximo)
            printf("nenhum\n\n");
        else
            printf("%d %d\n\n", primeiro, ultimo);
    }
    return 0;
}
