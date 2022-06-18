// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2435
#include <cstdio>
int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &d, &e, &f);
    if (b / (c * 1.0) < (e / (f * 1.0)))
        printf("%d\n", a);
    else
        printf("%d\n", d);
    return 0;
}
