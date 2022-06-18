// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2359
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 1001
#define MP make_pair
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
using namespace std;
typedef pair<int, int> ii;
int processado[MAXN], n, m, q;
vector<ii> grafo[MAXN];
int main() {
    while (scanf("%d %d %d", &n, &m, &q) != EOF) {
        for (int i = 1; i <= n; i++) {
            processado[i] = 0;
            grafo[i].clear();
        }
        int resp = 0;
        while (m--) {
            int u, v, peso;
            getint(u);
            getint(v);
            getint(peso);
            grafo[u].push_back(MP(v, peso));
            grafo[v].push_back(MP(u, peso));
        }
        priority_queue<ii, vector<ii>, greater<ii> > Dijkstra;
        while (q--) {
            int u;
            getint(u);
            Dijkstra.push(MP(0, u));
        }
        while (!Dijkstra.empty()) {
            ii davez = Dijkstra.top();
            Dijkstra.pop();
            int v = davez.second, percorrido = davez.first;
            if (processado[v]) continue;
            processado[v] = 1;
            resp = percorrido;
            for (int i = 0; i < grafo[v].size(); i++) {
                if (processado[grafo[v][i].first]) continue;
                Dijkstra.push(
                    MP(grafo[v][i].second + percorrido, grafo[v][i].first));
            }
        }
        printf("%d\n", resp);
    }
    return 0;
}
