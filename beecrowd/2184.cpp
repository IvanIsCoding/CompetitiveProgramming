// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2184
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#define MAXN 100010
#define MAXK 1001
#define MAXQ 5001
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
vector<ii> grafo[MAXN];
int dp[MAXQ][MAXK], custo[MAXQ], recompensa[MAXQ];
int pai[MAXN], superpai[MAXN], ligapai[MAXN], ligasuperpai[MAXN], nivel[MAXN],
    segmento, referencia;
int n, k, q;
int solve(int obj, int aguenta) {
    if (obj > q || aguenta <= 0) return 0;
    if (dp[obj][aguenta] != -1) return dp[obj][aguenta];
    int retorna = solve(obj + 1, aguenta);
    if (custo[obj] <= aguenta) {
        int coloca = recompensa[obj] + solve(obj + 1, aguenta - custo[obj]);
        return dp[obj][aguenta] = max(coloca, retorna);
    }
    return dp[obj][aguenta] = retorna;
}
void dfs_pai(int x) {
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i].first, peso = grafo[x][i].second;
        if (!pai[v]) {
            pai[v] = x;
            nivel[v] = nivel[x] + 1;
            ligapai[v] = peso;
            dfs_pai(v);
        }
    }
}
void dfs_superpai(int x, int p) {
    if (nivel[x] % segmento == 0) {
        p = x;
    }
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i].first, peso = grafo[x][i].second;
        if (!superpai[v]) {
            superpai[v] = p;
            if (p != x)
                ligasuperpai[v] = max(ligasuperpai[x], peso);
            else
                ligasuperpai[v] = peso;
            dfs_superpai(v, p);
        }
    }
}
int LCA(int u, int v) {
    while (superpai[u] != superpai[v]) {
        if (nivel[u] > nivel[v]) {
            u = superpai[u];
        } else
            v = superpai[v];
    }
    while (u != v) {
        if (nivel[u] > nivel[v]) {
            u = pai[u];
        } else
            v = pai[v];
    }
    return u;
}
int POMEKON(int u, int v) {
    int resp = 0;
    while (superpai[u] != superpai[v]) {
        if (nivel[u] > nivel[v]) {
            resp = max(resp, ligasuperpai[u]);
            u = superpai[u];
        } else {
            resp = max(resp, ligasuperpai[v]);
            v = superpai[v];
        }
    }
    while (u != v) {
        if (nivel[u] > nivel[v]) {
            resp = max(resp, ligapai[u]);
            u = pai[u];
        } else {
            resp = max(resp, ligapai[v]);
            v = pai[v];
        }
    }
    return resp;
}
int DIST(int u, int v) {
    return nivel[u] + nivel[v] - 2 * nivel[LCA(u, v)] + 1;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        grafo[u].push_back(MP(v, peso));
        grafo[v].push_back(MP(u, peso));
    }
    pai[1] = 1;
    superpai[1] = 1;
    dfs_pai(1);
    for (int i = 1; i <= n; i++) {
        referencia = max(referencia, nivel[i]);
    }
    segmento = sqrt(referencia);
    dfs_superpai(1, 1);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        custo[i] = DIST(u, v);
        recompensa[i] = POMEKON(u, v);
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1;
        }
    }
    // for(int i=1;i<=q;i++){
    //	printf("C[i] = %d R[i] = %d\n",custo[i],recompensa[i]);
    // }
    int resp = solve(1, k);
    if (resp == 0) resp = -1;
    printf("%d\n", resp);
    return 0;
}
