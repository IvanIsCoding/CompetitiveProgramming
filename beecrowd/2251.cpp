// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2251
#include <cmath>
#include <cstdio>
int main() {
    int n, count = 1;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("Teste %d\n", count++);
        printf("%.0f\n\n", pow(2, n) - 1.0);
    }
    return 0;
}
