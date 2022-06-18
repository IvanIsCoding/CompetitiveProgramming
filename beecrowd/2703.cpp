// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2703
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> trinca;
typedef pair<int, int> ii;
const int MAXN = 1e5 + 10;
const int MAXL = 20;
int pai[MAXN], ancestral[MAXN][MAXL], liga[MAXN][MAXL], nivel[MAXN], custo, n,
    m, q;
vector<trinca> Kruskal, arestas;
vector<ii> grafo[MAXN];
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    pai[y] = x;
}
void dfs(int v, int p) {
    for (int i = 1; i < MAXL; i++) {
        int u = ancestral[v][i - 1];
        if (u != -1) {
            ancestral[v][i] = ancestral[u][i - 1];
            liga[v][i] = max(liga[v][i - 1], liga[u][i - 1]);
        }
    }
    for (int i = 0; i < grafo[v].size(); i++) {
        int u = grafo[v][i].first, w = grafo[v][i].second;
        if (u == p) continue;
        nivel[u] = nivel[v] + 1;
        ancestral[u][0] = v;
        liga[u][0] = w;
        dfs(u, v);
    }
}
int LCA(int u, int v) {
    if (nivel[u] < nivel[v]) swap(u, v);
    int resp = 0;
    for (int i = MAXL - 1; i >= 0; i--) {
        int p = ancestral[u][i];
        if (p != -1 && nivel[p] >= nivel[v]) {
            resp = max(resp, liga[u][i]);
            u = p;
        }
    }
    if (u == v) return resp;
    for (int i = MAXL - 1; i >= 0; i--) {
        if (ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]) {
            resp = max(resp, liga[u][i]);
            resp = max(resp, liga[v][i]);
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    return max(max(liga[u][0], liga[v][0]), resp);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        memset(ancestral[i], -1, sizeof(ancestral[i]));
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Kruskal.push_back(make_tuple(w, u, v));
        arestas.push_back(make_tuple(u, v, w));
    }
    sort(Kruskal.begin(), Kruskal.end());
    sort(arestas.begin(), arestas.end());
    for (int i = 0; i < m; i++) {
        int u = get<1>(Kruskal[i]), v = get<2>(Kruskal[i]),
            w = get<0>(Kruskal[i]);
        if (find(u) != find(v)) {
            custo += w;
            grafo[u].push_back(ii(v, w));
            grafo[v].push_back(ii(u, w));
            join(u, v);
        }
    }
    dfs(1, -1);
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int w = get<2>(
            *lower_bound(arestas.begin(), arestas.end(), make_tuple(u, v, 0)));
        printf("%d\n", custo - LCA(u, v) + w);
    }
    return 0;
}
