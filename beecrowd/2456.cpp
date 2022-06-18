// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2456
#include <cstdio>
int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if (a >= b && b >= c && c >= d && d >= e) {
        printf("D\n");
    } else if (a <= b && b <= c && c <= d && d <= e) {
        printf("C\n");
    } else {
        printf("N\n");
    }
    return 0;
}
