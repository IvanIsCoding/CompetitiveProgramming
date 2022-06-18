// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2666
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 1e4 + 10;
vector<ii> grafo[MAXN];
int qtd[MAXN], paga, N, C;
void dfs(int v, int p, int f) {
    for (ii aresta : grafo[v]) {
        int u = aresta.first;
        int peso = aresta.second;
        if (u == p) continue;
        dfs(u, v, peso);
    }
    if (v == 1) return;
    paga += f * (qtd[v] / C);
    if (qtd[v] % C != 0) paga += f;
    qtd[p] += qtd[v];
}
int main() {
    scanf("%d %d", &N, &C);
    for (int i = 1; i <= N; i++) cin >> qtd[i];
    for (int i = 1; i < N; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        grafo[u].push_back(ii(v, peso));
        grafo[v].push_back(ii(u, peso));
    }
    dfs(1, -1, -1);
    cout << 2 * paga << endl;
    return 0;
}
