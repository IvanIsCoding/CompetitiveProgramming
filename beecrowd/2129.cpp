// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2129
#include <cstdio>
#define MAXN 1000001
typedef long long ll;
ll vetor[MAXN];
int main() {
    vetor[0] = 1LL;
    for (ll i = 1; i < MAXN; i++) {
        vetor[i] = (i * vetor[i - 1]);
        while (!(vetor[i] % 10)) vetor[i] /= 10;
        vetor[i] %= 100000;
    }
    ll instancia = 0, n;
    while (scanf("%lld", &n) != EOF) {
        printf("Instancia %lld\n%lld\n\n", ++instancia, vetor[n] % 10);
    }
    return 0;
}
