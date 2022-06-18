// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2409
#include <cstdio>
int main() {
    int a, b, c, d, e;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d", &d, &e);
    if (a >= b && a >= c) {
        if ((b <= d && c <= e) || (b <= e && c <= d)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    } else if (b >= a && b >= c) {
        if ((a <= d && c <= e) || (a <= e && c <= d)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    } else {
        if ((b <= d && a <= e) || (b <= e && a <= d)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
