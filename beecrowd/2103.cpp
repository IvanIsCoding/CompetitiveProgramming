// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2103
#include <cstdio>
#include <vector>
#define MAXN 10001
#define MODULO 1300031
using namespace std;
typedef pair<int, int> ii;
vector<ii> grafo[MAXN];
int processado_filhos[MAXN], processado_contar[MAXN], filhos[MAXN], resp, n, TC;
void dfs_filhos(int x) {
    processado_filhos[x] = 1;
    filhos[x] = 1;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i].first;
        if (!processado_filhos[v]) {
            dfs_filhos(v);
            filhos[x] += filhos[v];
        }
    }
}
void dfs_contar(int x) {
    processado_contar[x] = 1;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i].first, peso = grafo[x][i].second;
        if (!processado_contar[v]) {
            resp += ((n - filhos[v]) * (filhos[v]) % MODULO) * peso;
            resp %= MODULO;
            dfs_contar(v);
        }
    }
}
int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            processado_filhos[i] = 0;
            processado_contar[i] = 0;
        }
        resp = 0;
        for (int i = 1; i < n; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            grafo[u].push_back(make_pair(v, peso));
            grafo[v].push_back(make_pair(u, peso));
        }
        dfs_filhos(1);
        dfs_contar(1);
        printf("%d\n", resp);
    }
    return 0;
}
