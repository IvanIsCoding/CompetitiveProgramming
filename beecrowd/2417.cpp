// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2417
#include <cstdio>
int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if (a * 3 + b == d * 3 + e) {
        if (c == f) {
            printf("=\n");
        } else if (c > f) {
            printf("C\n");
        } else {
            printf("F\n");
        }
    } else if (a * 3 + b > d * 3 + e) {
        printf("C\n");
    } else {
        printf("F\n");
    }
    return 0;
}
