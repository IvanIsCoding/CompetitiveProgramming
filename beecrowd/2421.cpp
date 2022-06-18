// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2421
#include <cstdio>
int main() {
    int a, b, c, d, e, f;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    scanf("%d %d", &e, &f);
    if (((c <= a && e <= a) && d + f <= b) ||
        ((c <= a && f <= a) && d + e <= b) ||
        ((d <= a && e <= a) && c + f <= b) ||
        ((d <= a && f <= a) && c + e <= b) ||
        ((c <= b && e <= b) && d + f <= a) ||
        ((c <= b && f <= b) && d + e <= a) ||
        ((d <= b && e <= b) && c + f <= a) ||
        ((d <= b && f <= b) && c + e <= a)) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    return 0;
}
