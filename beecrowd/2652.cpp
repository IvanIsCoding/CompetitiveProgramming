// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2652
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const ll MOD1 = 1e9 + 9;
const ll prime1 = 999983;
const ll MOD2 = 1e9 + 7;
const ll prime2 = 999979;
const ll invprime1 = 943912055;
const ll invprime2 = 672490127;
const int MAXN = 50;
vector<int> grafo[MAXN];
set<vector<ll> > todas;
ll hash1[MAXN], pot[MAXN];
void dfs(int v, int p) {
    hash1[v] = (invprime1 * prime2) % MOD2;
    vector<ll> ordenado;
    for (int u : grafo[v]) {
        if (u == p) continue;
        dfs(u, v);
        ordenado.push_back(hash1[u]);
    }
    sort(ordenado.begin(), ordenado.end());
    for (int i = 0; i < ordenado.size(); i++) {
        ll davez = ordenado[i];
        if (i % 2 == 0)
            davez ^= prime2;
        else
            davez ^= invprime2;
        hash1[v] += davez * pot[i];
        hash1[v] %= MOD1;
    }
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) grafo[i].clear();
        pot[0] = 1;
        for (int i = 1; i <= N; i++) pot[i] = (pot[i - 1] * prime1) % MOD1;
        for (int i = 2; i <= N; i++) {
            int j;
            scanf("%d", &j);
            grafo[i].push_back(j);
            grafo[j].push_back(i);
        }
        vector<ll> davez;
        for (int i = 1; i <= N; i++) {
            dfs(i, -1);
            davez.push_back(hash1[i]);
        }
        sort(davez.begin(), davez.end());
        todas.insert(davez);
    }
    printf("%d\n", (int)todas.size());
    return 0;
}
