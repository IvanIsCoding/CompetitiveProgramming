// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2131
#include <cstdio>
#include <queue>
#include <vector>
#define PB push_back
#define MAXN 110
using namespace std;
int color[MAXN], ok[MAXN], n, m, instancia;
vector<int> graph[MAXN];
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            color[i] = -1;
            ok[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].PB(v);
            graph[v].PB(u);
        }
        queue<int> bfs;
        bool isbipartite = true;
        bfs.push(1);
        color[1] = 1;
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            if (ok[v]) continue;
            ok[v] = 1;
            int check = color[v];
            for (int i = 0; i < graph[v].size() && isbipartite; i++) {
                int u = graph[v][i];
                if (color[u] == check)
                    isbipartite = false;
                else {
                    color[u] = !check;
                    bfs.push(u);
                }
            }
            if (!isbipartite) break;
        }
        printf("Instancia %d\n", ++instancia);
        printf("%s\n\n", isbipartite ? "sim" : "nao");
    }
    return 0;
}
