// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1640
#include <cstdio>
#include <queue>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int processado[10010], temhotel[10010], n, h, m;
vector<ii> grafo[10010];
int main() {
    while (scanf("%d", &n) && n) {
        int possivel = 0;
        scanf("%d", &h);
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            temhotel[i] = 0;
            processado[i] = 601;
        }
        while (h--) {
            int davez;
            scanf("%d", &davez);
            temhotel[davez] = 1;
        }
        scanf("%d", &m);
        while (m--) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            grafo[u].push_back(MP(v, peso));
            grafo[v].push_back(MP(u, peso));
        }
        priority_queue<iii, vector<iii>, greater<iii> > Dijkstra;
        Dijkstra.push(MP(0, MP(0, 1)));
        while (!Dijkstra.empty()) {
            iii davez = Dijkstra.top();
            Dijkstra.pop();
            int hoteis = davez.first, minutos = davez.second.first,
                cidade = davez.second.second;
            if (cidade == n) {
                printf("%d\n", hoteis);
                possivel = 1;
                break;
            }
            if (processado[cidade] <= minutos) continue;
            processado[cidade] = minutos;
            for (int i = 0; i < grafo[cidade].size(); i++) {
                int proxima = grafo[cidade][i].first,
                    tempo = grafo[cidade][i].second;
                if (minutos + tempo <= 600) {
                    Dijkstra.push(MP(hoteis, MP(minutos + tempo, proxima)));
                }
            }
            if (temhotel[cidade]) Dijkstra.push(MP(hoteis + 1, MP(0, cidade)));
        }
        if (!possivel) printf("-1\n");
    }
    return 0;
}
