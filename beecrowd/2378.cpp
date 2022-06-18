// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2378
#include <cstdio>
int main() {
    int n, c, i, total = 0, excedeu = 0;
    scanf("%d %d", &n, &c);
    for (i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        total += b;
        total -= a;
        if (total > c) {
            excedeu = 1;
        }
    }
    if (excedeu == 0)
        printf("N\n");
    else
        printf("S\n");
    return 0;
}
