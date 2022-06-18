// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2187
#include <cstdio>
int main() {
    int n, teste = 1;
    while (scanf("%d", &n) && n) {
        printf("Teste %d\n", teste++);
        printf("%d ", n / 50);
        n %= 50;
        printf("%d ", n / 10);
        n %= 10;
        printf("%d ", n / 5);
        n %= 5;
        printf("%d\n\n", n);
    }
    return 0;
}
