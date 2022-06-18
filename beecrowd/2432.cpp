// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2432
#include <cstdio>
#define MAXN 100010
typedef long long ll;
ll n, m, resposta;
ll vetor[MAXN];
ll busca(ll valor) {
    if (valor > vetor[n]) return 0;
    ll ini = 1, fim = n, meio;
    while (ini < fim) {
        meio = (ini + fim) / 2;
        if (vetor[meio] >= valor)
            fim = meio;
        else
            ini = meio + 1;
    }
    return n + 1 - fim;
}
int main() {
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        ll davez;
        scanf("%lld", &vetor[i]);
        vetor[i] *= vetor[i];
    }
    while (m--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        // printf("%lld %lld %lld\n",x,y,busca(x*x + y*y));
        resposta += busca(x * x + y * y);
    }
    printf("%lld\n", resposta);
    return 0;
}
