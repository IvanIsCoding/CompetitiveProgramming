// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1751
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 100010
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
vector<ii> grafo[MAXN];
int tem_amigos[MAXN], processado_amigo[MAXN], processado_custo[MAXN],
    processado_maior[MAXN], n, f;
int dfs_amigo(int v) {
    processado_amigo[v] = 1;
    for (int i = 0; i < grafo[v].size(); i++) {
        int u = grafo[v][i].first;
        if (!processado_amigo[u]) {
            tem_amigos[v] |= dfs_amigo(u);
        }
    }
    return tem_amigos[v];
}
int dfs_custo(int v) {
    processado_custo[v] = 1;
    int retornar = 0;
    for (int i = 0; i < grafo[v].size(); i++) {
        int u = grafo[v][i].first, peso = grafo[v][i].second;
        if (tem_amigos[u] && !processado_custo[u]) {
            retornar += peso + dfs_custo(u);
        }
    }
    return retornar;
}
int dfs_maior(int v) {
    processado_maior[v] = 1;
    int retornar = 0;
    for (int i = 0; i < grafo[v].size(); i++) {
        int u = grafo[v][i].first, peso = grafo[v][i].second;
        if (tem_amigos[u] && !processado_maior[u]) {
            retornar = max(retornar, peso + dfs_maior(u));
        }
    }
    return retornar;
}
int main() {
    scanf("%d %d", &n, &f);
    for (int i = 1; i < n; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        grafo[u].push_back(MP(v, peso));
        grafo[v].push_back(MP(u, peso));
    }
    for (int i = 1; i <= f; i++) {
        int davez;
        scanf("%d", &davez);
        tem_amigos[davez] = 1;
    }
    dfs_amigo(1);
    printf("%d\n", dfs_custo(1) - dfs_maior(1));
    return 0;
}
