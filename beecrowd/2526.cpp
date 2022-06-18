// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2526
#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
#define MAXN 1000010
#define ANTES 0
#define DEPOIS 1
typedef long long ll;
ll bit[MAXN][2], vetor[MAXN], n;
void update(ll id, ll pos, ll delta) {
    while (pos < MAXN) {
        bit[pos][id] += delta;
        pos += LSOne(pos);
    }
}
ll read(ll id, ll pos) {
    ll ans = 0;
    while (pos > 0) {
        ans += bit[pos][id];
        pos -= LSOne(pos);
    }
    return ans;
}
ll query(ll id, ll a, ll b) {
    if (a > b) return 0;
    return read(id, b) - read(id, a - 1);
}
int main() {
    while (scanf("%lld", &n) != EOF) {
        memset(bit, 0, sizeof(bit));
        for (ll i = 1; i <= n; i++) {
            scanf("%lld", &vetor[i]);
            update(DEPOIS, vetor[i], 1);
        }
        ll resp = 0;
        for (ll i = 1; i <= n; i++) {
            ll davez =
                query(ANTES, vetor[i] + 1, n) * query(DEPOIS, 1, vetor[i] - 1);
            resp += davez;
            update(ANTES, vetor[i], 1);
            update(DEPOIS, vetor[i], -1);
        }
        printf("%lld\n", resp);
    }
    return 0;
}
