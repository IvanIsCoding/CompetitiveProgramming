// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2386
#include <cstdio>
int main() {
    int n, resposta = 0, a;
    scanf("%d %d", &a, &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (a * x >= 40000000) resposta++;
    }
    printf("%d\n", resposta);
    return 0;
}
