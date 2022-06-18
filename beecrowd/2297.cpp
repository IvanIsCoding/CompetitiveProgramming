// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2297
#include <cstdio>
int main() {
    int n, j1, j2, t1 = 0, t2 = 0, i, teste = 1;

    while (scanf("%d", &n) && n) {
        printf("Teste %d\n", teste++);
        t1 = 0;
        t2 = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &j1, &j2);
            t1 += j1;
            t2 += j2;
        }
        if (t1 > t2) {
            printf("Aldo");
        } else {
            printf("Beto");
        }
        printf("\n\n");
    }
    return 0;
}
