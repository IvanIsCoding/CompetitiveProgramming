// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1692
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 2 * 1e3 + 2;
vector<int> grafo[MAXN];
int processado[MAXN], n, k, aux, diametro;
void dfs(int x, int percorrido) {
    processado[x] = 1;
    if (percorrido > diametro) {
        diametro = percorrido;
        aux = x;
    }
    for (int i = 0; i < grafo[x].size(); i++) {
        int u = grafo[x][i];
        if (!processado[u]) {
            dfs(u, percorrido + 1);
        }
    }
}
int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= 2 * n; i++) {
            grafo[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a].push_back(n + i);
            grafo[n + i].push_back(b);
            grafo[b].push_back(n + i);
            grafo[n + i].push_back(a);
        }
        aux = -1;
        diametro = 0;
        memset(processado, 0, sizeof(processado));
        dfs(1, 0);
        diametro = 0;
        memset(processado, 0, sizeof(processado));
        dfs(aux, 0);
        int maximo = 0;
        if (diametro < 2 * k) {
            printf("Impossible revenge!\n");
            continue;
        }
        if (k % 2 == 0) {
            for (int verticedavez = 1; verticedavez <= n; verticedavez++) {
                memset(processado, 0, sizeof(processado));
                queue<ii> bfs;
                int distanciacuro = 0, total = 0;
                bfs.push(MP(0, verticedavez));
                while (!bfs.empty()) {
                    ii davez = bfs.front();
                    bfs.pop();
                    int v = davez.second, percorrido = davez.first;
                    if (processado[v]) continue;
                    processado[v] = 1;
                    if (percorrido > k) break;
                    if (percorrido == k && v <= n) distanciacuro++;
                    if (v <= n) total++;
                    for (int i = 0; i < grafo[v].size(); i++) {
                        int u = grafo[v][i];
                        bfs.push(MP(percorrido + 1, u));
                    }
                }
                if (distanciacuro <= 1) continue;
                maximo = max(maximo, total);
            }
        } else if (k % 2 == 1) {
            for (int verticedavez = n + 1; verticedavez < 2 * n;
                 verticedavez++) {
                memset(processado, 0, sizeof(processado));
                queue<ii> bfs;
                int distanciacuro = 0, total = 0;
                bfs.push(MP(0, verticedavez));
                while (!bfs.empty()) {
                    ii davez = bfs.front();
                    bfs.pop();
                    int v = davez.second, percorrido = davez.first;
                    if (processado[v]) continue;
                    processado[v] = 1;
                    if (percorrido > k) break;
                    if (percorrido == k && v <= n) distanciacuro++;
                    if (v <= n) total++;
                    for (int i = 0; i < grafo[v].size(); i++) {
                        int u = grafo[v][i];
                        bfs.push(MP(percorrido + 1, u));
                    }
                }
                if (distanciacuro <= 1) continue;
                // printf("%d com %d\n",verticedavez,total);
                maximo = max(maximo, total);
            }
        }
        printf("%d\n", maximo);
    }
    return 0;
}
