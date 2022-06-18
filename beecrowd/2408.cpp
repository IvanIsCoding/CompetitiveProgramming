// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2408
#include <cstdio>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >= c) {
        if (b >= c) {
            printf("%d\n", b);
        } else {
            printf("%d\n", c);
        }
    } else if (b >= a && b >= c) {
        if (a >= c) {
            printf("%d\n", a);
        } else {
            printf("%d\n", c);
        }
    } else {
        if (a >= b) {
            printf("%d\n", a);
        } else {
            printf("%d\n", b);
        }
    }
    return 0;
}
