// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2346
#include <cstdio>
#include <set>
#include <vector>
#define MAXN 100010
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
vector<int> grafo[MAXN];
int grau[MAXN], n, m, a, b, deletado[MAXN];
set<ii> conjunto;
int main() {
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        grafo[u].push_back(v);
        grafo[v].push_back(u);
        grau[u]++;
        grau[v]++;
    }
    for (int i = 1; i <= n; i++) {
        conjunto.insert(MP(grau[i], i));
    }
    for (int vez = 0; vez < n && !conjunto.empty(); vez++) {
        ii candidato1 = *(conjunto.begin());
        int v1 = candidato1.second, g1 = candidato1.first;
        if (g1 < a) {
            // printf("%d %d 1\n",v1,g1);
            conjunto.erase(candidato1);
            deletado[v1] = 1;
            for (int i = 0; i < grafo[v1].size(); i++) {
                int p = grafo[v1][i];
                if (deletado[p]) continue;
                conjunto.erase(conjunto.find(MP(grau[p], p)));
                grau[p]--;
                conjunto.insert(MP(grau[p], p));
            }
        }
        if (conjunto.empty()) break;
        ii candidato2 = *(conjunto.rbegin());
        int v2 = candidato2.second, g2 = candidato2.first;
        if ((int)conjunto.size() - g2 - 1 < b) {
            // printf("%d %d 2\n",v2,g2);
            conjunto.erase(candidato2);
            deletado[v2] = 1;
            for (int i = 0; i < grafo[v2].size(); i++) {
                int p = grafo[v2][i];
                if (deletado[p]) continue;
                conjunto.erase(conjunto.find(MP(grau[p], p)));
                grau[p]--;
                conjunto.insert(MP(grau[p], p));
            }
        }
    }
    printf("%d\n", (int)conjunto.size());
    return 0;
}
