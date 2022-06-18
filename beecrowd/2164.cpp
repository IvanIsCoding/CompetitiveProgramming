// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2164
#include <cstdio>
#define MAXN 60
double sequencia[MAXN];
double funcao(int x) {
    if (x == 0) return sequencia[0] = 0;
    if (x == 1) return sequencia[1] = 1;
    if (sequencia[x] != 0) return sequencia[x];
    return sequencia[x] = funcao(x - 1) + funcao(x - 2);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%.1lf\n", funcao(n));
    return 0;
}
