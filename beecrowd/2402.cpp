// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2402
#include <cstdio>
typedef unsigned long long llu;
int main() {
    llu n, i;
    scanf("%llu", &n);
    if (n % 2 == 0) {
        printf("S\n");
        return 0;
    }
    for (i = 3LLU; i * i <= n; i += 2)
        if (!(n % i)) {
            printf("S\n");
            return 0;
        }
    printf("N\n");
    return 0;
}
