// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1604
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 100010
using namespace std;
vector<int> grafo[MAXN];
int match[MAXN], processado[MAXN], n;
void dfs(int x) {
    processado[x] = 1;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i];
        if (!processado[v]) {
            dfs(v);
            if (match[v] == -1) {
                match[v] = x;
                match[x] = v;
                return;
            }
        }
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n; i++) {
            match[i] = -1;
            processado[i] = 0;
            grafo[i].clear();
        }
        processado[n % 2] = 1;
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) sort(grafo[i].begin(), grafo[i].end());
        for (int i = 1 + (n % 2); i <= n; i++) {
            if (!processado[i]) dfs(i);
        }
        int possivel = 1;
        for (int i = 1 + (n % 2); i <= n; i++) {
            if (match[i] == -1) {
                possivel = 0;
                break;
            }
        }
        if (!possivel) {
            printf("N\n");
            continue;
        }
        printf("Y\n");
        for (int i = 1 + (n % 2); i <= n; i++) {
            if (i < match[i]) printf("%d %d\n", i, match[i]);
        }
    }
    return 0;
}
