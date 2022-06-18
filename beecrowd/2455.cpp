// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2455
#include <cstdio>
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a * b == c * d)
        printf("0\n");
    else if (a * b > c * d)
        printf("-1\n");
    else
        printf("1\n");
    return 0;
}
