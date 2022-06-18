// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1617
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 101
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
const int INF = 1e8;
int dist[MAXN], nafila[MAXN], usado[MAXN][MAXN], anterior[MAXN], n, m;
vector<ii> grafo[MAXN];
int main() {
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
        }
        memset(usado, 0, sizeof(usado));
        for (int i = 1; i <= m; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            grafo[u].push_back(MP(v, peso));
            grafo[v].push_back(MP(u, peso));
        }
        queue<int> SPFA;
        for (int i = 1; i <= n; i++) dist[i] = INF;
        SPFA.push(1);
        dist[1] = 0;
        anterior[1] = 1;
        nafila[1] = 1;
        int resp = 0;
        while (!SPFA.empty()) {
            int v = SPFA.front();
            SPFA.pop();
            nafila[v] = 0;
            for (ii davez : grafo[v]) {
                int u = davez.first, peso = davez.second;
                if (dist[v] + peso < dist[u]) {
                    dist[u] = dist[v] + peso;
                    anterior[u] = v;
                    if (!nafila[u]) {
                        SPFA.push(u);
                        nafila[u] = 1;
                    }
                }
            }
        }
        if (dist[n] == INF) {
            printf("Pernoite.\n");
            continue;
        }
        resp += dist[n];
        for (int i = n; i != 1;) {
            usado[anterior[i]][i] = 1;
            i = anterior[i];
        }
        for (int i = 1; i <= n; i++) dist[i] = INF;
        SPFA.push(1);
        dist[1] = 0;
        anterior[1] = 1;
        nafila[1] = 1;
        while (!SPFA.empty()) {
            int v = SPFA.front();
            SPFA.pop();
            nafila[v] = 0;
            for (ii davez : grafo[v]) {
                int u = davez.first, peso = davez.second;
                if (usado[v][u]) continue;
                if (usado[u][v]) peso *= -1;
                if (dist[v] + peso < dist[u]) {
                    dist[u] = dist[v] + peso;
                    anterior[u] = v;
                    if (!nafila[u]) {
                        SPFA.push(u);
                        nafila[u] = 1;
                    }
                }
            }
        }
        if (dist[n] == INF) {
            printf("Pernoite.\n");
            continue;
        }
        resp += dist[n];
        printf("%d\n", resp);
    }
    return 0;
}
