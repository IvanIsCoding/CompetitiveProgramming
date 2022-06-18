// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2377
#include <cstdio>
int main() {
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    printf("%d\n", ((a / b) * d) + a * c);
    return 0;
}
