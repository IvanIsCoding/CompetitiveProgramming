// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2545
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 1010;
vector<int> grafo[MAXN];
int grau[MAXN], nivel[MAXN], n;
int main() {
    while (scanf("%d", &n) != EOF) {
        int processado = 0, resp = 0;
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            grau[i] = nivel[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int m, j;
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &j);
                grafo[i].push_back(j);
                grau[j]++;
            }
        }
        queue<int> fila;
        for (int i = 1; i <= n; i++)
            if (grau[i] == 0) {
                nivel[i] = 1;
                fila.push(i);
            }
        while (!fila.empty()) {
            int v = fila.front();
            processado++;
            fila.pop();
            resp = max(resp, nivel[v]);
            for (int i = 0; i < grafo[v].size(); i++) {
                int u = grafo[v][i];
                grau[u]--;
                if (grau[u] == 0) {
                    fila.push(u);
                    nivel[u] = nivel[v] + 1;
                }
            }
        }
        if (processado == n)
            printf("%d\n", resp);
        else
            printf("-1\n");
    }
    return 0;
}
