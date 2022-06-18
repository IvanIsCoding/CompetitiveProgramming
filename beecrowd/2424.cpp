// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2424
#include <cstdio>
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a >= 0 && b >= 0 && a <= 432 && b <= 468) {
        printf("dentro\n");
    } else {
        printf("fora\n");
    }
    return 0;
}
