// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2382
#include <cstdio>
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    d *= 2;
    printf("%c\n", a * a + b * b + c * c <= d * d ? 'S' : 'N');
    return 0;
}
