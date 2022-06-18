// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2423
#include <cstdio>
int main() {
    int a, b, c, a2, b2, c2;
    scanf("%d %d %d", &a, &b, &c);
    a2 = a / 2;
    b2 = b / 3;
    c2 = c / 5;
    if (a2 <= b2 && a2 <= c2) {
        printf("%d\n", a2);
    } else if (b2 <= c2 && b2 <= a2) {
        printf("%d\n", b2);
    } else {
        printf("%d\n", c2);
    }
    return 0;
}
