// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2454
#include <cstdio>
int main() {
    int p, r;
    scanf("%d %d", &p, &r);
    if (p == 1) {
        if (r == 0)
            printf("B\n");
        else
            printf("A\n");
    } else
        printf("C\n");
    return 0;
}
