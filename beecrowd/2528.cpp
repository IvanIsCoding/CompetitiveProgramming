// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2528
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 1001
using namespace std;
vector<int> grafo[MAXN];
int n, m, c, r, e, processado[MAXN], dist[MAXN];
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            processado[i] = 0;
            dist[i] = MAXN;
        }
        while (m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        scanf("%d %d %d", &c, &r, &e);
        queue<int> bfs;
        bfs.push(c);
        dist[c] = 0;
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            if (v == e) continue;
            if (v == r) {
                printf("%d\n", dist[v]);
                break;
            }
            for (int i = 0; i < grafo[v].size(); i++) {
                int u = grafo[v][i];
                if (!processado[u]) {
                    processado[u] = 1;
                    dist[u] = dist[v] + 1;
                    bfs.push(u);
                }
            }
        }
    }
    return 0;
}
