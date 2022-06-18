// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2470
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 50500
#define MAXL 21
int pai[MAXN], nivel[MAXN], carta[MAXN], par[MAXN], n, resposta, acessado[MAXN];
int ancestral[MAXN][MAXL];
vector<int> lista[MAXN];
void dfs(int u) {
    for (int i = 0; i < lista[u].size(); i++) {
        int v = lista[u][i];
        if (nivel[v] == -1) {
            nivel[v] = nivel[u] + 1;
            pai[v] = u;
            dfs(v);
        }
    }
}
int LCA(int u, int v) {
    if (nivel[u] < nivel[v]) swap(u, v);
    for (int i = MAXL - 1; i >= 0; i--) {
        if (ancestral[u][i] != -1 && nivel[ancestral[u][i]] >= nivel[v]) {
            u = ancestral[u][i];
        }
    }
    if (u == v) return u;
    for (int i = MAXL - 1; i >= 0; i--) {
        if (ancestral[u][i] != ancestral[v][i] && ancestral[u][i] != -1) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    return pai[u];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (carta[x]) {
            par[i] = carta[x];
            par[carta[x]] = i;
        }
        carta[x] = i;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    memset(pai, -1, sizeof(pai));
    memset(nivel, -1, sizeof(nivel));
    nivel[1] = 0;
    dfs(1);
    for (int i = 1; i <= n; i++) ancestral[i][0] = pai[i];
    for (int j = 1; j < MAXL; j++) {
        for (int i = 1; i <= n; i++) {
            if (ancestral[i][j - 1] != -1) {
                ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (acessado[i]) continue;
        resposta += nivel[i] + nivel[par[i]] - 2 * nivel[LCA(i, par[i])];
        acessado[i] = 1;
        acessado[par[i]] = 1;
    }
    printf("%d\n", resposta);
}
