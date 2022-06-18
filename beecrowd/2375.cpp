// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2375
#include <cstdio>
int main() {
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d %d %d", &b, &c, &d);
    if (a <= b && a <= c && a <= d)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
