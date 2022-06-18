// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2079
#include <cstdio>
#include <vector>
#define MAXN 6001
using namespace std;
vector<int> grafo[MAXN];
int processado[MAXN], total, TC, n;
int dfs(int v) {
    processado[v] = 1;
    int filhos_marcados = 0;
    for (int i = 0; i < grafo[v].size(); i++) {
        int u = grafo[v][i];
        if (!processado[u]) {
            filhos_marcados += dfs(u);
        }
    }
    if (filhos_marcados == 0) {
        total++;
        return 1;
    }
    return 0;
}
int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        total = 0;
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            processado[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }
        dfs(1);
        printf("%d\n", total);
    }
    return 0;
}
