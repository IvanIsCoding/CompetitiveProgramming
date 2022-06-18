// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2369
#include <cstdio>
int main() {
    int a;
    scanf("%d", &a);
    if (a <= 10)
        printf("7\n");
    else if (a <= 30)
        printf("%d\n", a - 3);
    else if (a <= 100)
        printf("%d\n", 27 + (a - 30) * 2);
    else
        printf("%d\n", 167 + (a - 100) * 5);
    return 0;
}
