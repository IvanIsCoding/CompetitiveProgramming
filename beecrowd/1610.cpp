// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1610
#include <cstdio>
#include <vector>
#define MAXN 30100
using namespace std;
int n, m, casos, grau[MAXN];
vector<int> lista, grafo[MAXN];
int main() {
    scanf("%d", &casos);
    while (casos--) {
        lista.clear();
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            grau[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            grau[y]++;
            grafo[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
            if (!grau[i]) lista.push_back(i);
        int ini = 0;
        while (ini < lista.size()) {
            int atual = lista[ini++];
            for (int i = 0; i < grafo[atual].size(); i++) {
                int v = grafo[atual][i];
                if (!--grau[v]) lista.push_back(v);
            }
        }
        if (lista.size() < n)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
    return 0;
}
