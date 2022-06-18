// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2333
#include <cstdio>
#include <map>
#define MAXN 100100
typedef long long ll;
ll vetor[MAXN], n;
ll max(ll x, ll y) {
    if (x > y) return x;
    return y;
}
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &vetor[i]);
    ll maximo_ate_agora = 0LL, maximo_ate_aqui = 0LL, somavetor = 0LL,
       invertido_ate_agora = 0LL, invertido_ate_aqui = 0LL;
    for (int i = 0; i < n; i++) {
        maximo_ate_aqui = max(maximo_ate_aqui + vetor[i], 0);
        maximo_ate_agora = max(maximo_ate_agora, maximo_ate_aqui);
        somavetor += vetor[i];
    }
    for (int i = 0; i < n; i++) {
        invertido_ate_aqui = max(invertido_ate_aqui - vetor[i], 0);
        invertido_ate_agora = max(invertido_ate_agora, invertido_ate_aqui);
    }
    printf("%lld\n", max(maximo_ate_agora, invertido_ate_agora + somavetor));
    return 0;
}
