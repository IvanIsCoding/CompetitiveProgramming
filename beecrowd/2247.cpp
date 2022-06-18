// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2247
#include <cstdio>
int main() {
    int n, teste = 1;
    while (scanf("%d", &n) && n) {
        printf("Teste %d\n", teste++);
        int saldo = 0;
        while (n--) {
            int x, y;
            scanf("%d %d", &x, &y);
            saldo += x - y;
            printf("%d\n", saldo);
        }
        printf("\n");
    }
    return 0;
}
