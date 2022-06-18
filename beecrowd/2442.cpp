// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2442
#include <cstdio>
#define MAXN 100010
#define MAXA 110
long long vetor[MAXN], frutas[MAXA], resp, n, k;
int main() {
    scanf("%lld %lld", &n, &k);
    while (k--) {
        int i;
        scanf("%d", &i);
        frutas[i]++;
    }
    for (int i = 1; i <= n; i++) {
        char c;
        scanf(" %c", &c);
        if (c == 'C')
            vetor[i] = 1;
        else
            vetor[i] = -1;
    }
    for (long long davez = 1; davez <= 100; davez++) {
        long long atual = davez;
        for (int i = 1; i <= n && atual > 0; i++) {
            atual += vetor[i];
            resp += atual * frutas[davez];
        }
    }
    printf("%lld\n", resp);
    return 0;
}
