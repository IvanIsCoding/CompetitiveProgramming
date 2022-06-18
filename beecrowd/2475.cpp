// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2475
#include <cstdio>
#define MAXN 10001
#define MAXA 501
typedef long long ll;
const ll INF = 1e16;
ll C[MAXN];
ll soma[MAXN];
ll F[MAXA][MAXN];
int P[MAXA][MAXN];
inline ll custo(ll i, ll j) {
    return i > j ? 0 : (soma[j] - soma[i - 1]) * (j - i + 1);
}
void solve(int g, int l1, int l2, int p1, int p2) {
    if (l1 > l2) return;
    ll lm = (l1 + l2) / 2;
    P[g][lm] = -1;
    F[g][lm] = INF;
    for (ll k = p1; k <= p2; k++) {
        ll novo_custo = F[g - 1][k] + custo(k + 1, lm);
        if (novo_custo < F[g][lm]) {
            F[g][lm] = novo_custo;
            P[g][lm] = k;
        }
    }
    solve(g, l1, lm - 1, p1, P[g][lm]);
    solve(g, lm + 1, l2, P[g][lm], p2);
}
int main() {
    int G, L;
    scanf("%d %d", &L, &G);
    for (int i = 1; i <= L; i++) {
        scanf("%lld", &C[i]);
        soma[i] = soma[i - 1] + C[i];
    }
    for (int l = 0; l <= L; l++) {
        F[1][l] = custo(1, l);
        P[1][l] = 0;
    }
    for (int g = 2; g <= G; g++) {
        solve(g, 0, L, 0, L);
    }
    printf("%lld\n", F[G][L]);
    return 0;
}
