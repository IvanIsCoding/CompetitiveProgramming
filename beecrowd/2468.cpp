// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2468
#include <cstdio>
#define MAXN 100010
typedef long long ll;
ll pai[MAXN], peso[MAXN], filhos[MAXN];
ll resposta;
ll find(ll x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] < peso[y]) {
        pai[x] = y;
        filhos[y] += filhos[x];
    } else if (peso[x] > peso[y]) {
        pai[y] = x;
        filhos[x] += filhos[y];
    } else {
        pai[x] = y;
        peso[y]++;
        filhos[y] += filhos[x];
    }
}
int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        pai[i] = i;
        filhos[i] = 1LL;
    }
    for (ll i = 1; i < n; i++) {
        ll u, v, cor;
        scanf("%lld %lld %lld", &u, &v, &cor);
        if (!cor) join(u, v);
    }
    for (ll i = 1; i <= n; i++) {
        if (pai[i] != i) continue;
        resposta += ((n - filhos[i]) * filhos[i]);
    }
    printf("%lld\n", resposta / 2LL);
    return 0;
}
