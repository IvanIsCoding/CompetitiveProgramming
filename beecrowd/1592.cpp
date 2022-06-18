// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1592
#include <cstdio>
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
typedef pair<int, ii> iii;
int processado[MAXN], n, m, k, menor[MAXN];
vector<ii> grafo[MAXN];
int main() {
    int TC;
    getint(TC);
    while (TC--) {
        int possivel = 0;
        getint(n);
        getint(m);
        getint(k);
        for (int i = 0; i < n; i++) {
            grafo[i].clear();
            processado[i] = 0;
        }
        while (m--) {
            int u, v, peso;
            getint(u);
            getint(v);
            getint(peso);
            grafo[u].push_back(MP(v, peso));
        }
        priority_queue<iii, vector<iii>, greater<iii> > Dijkstra;
        Dijkstra.push(MP(0, MP(1, 0)));
        while (!Dijkstra.empty()) {
            iii davez = Dijkstra.top();
            Dijkstra.pop();
            int v = davez.second.second, profundidade = davez.second.first,
                percorrido = davez.first;
            if (profundidade > k) continue;
            if (processado[v]) {
                if (profundidade >= menor[v]) continue;
                menor[v] = profundidade;
            } else {
                processado[v] = 1;
                menor[v] = profundidade;
            }
            if (v == n - 1) {
                possivel = 1;
                printf("%d\n", percorrido);
                break;
            }
            for (int i = 0; i < grafo[v].size(); i++) {
                int u = grafo[v][i].first, peso = grafo[v][i].second;
                Dijkstra.push(MP(percorrido + peso, MP(profundidade + 1, u)));
            }
        }
        if (!possivel) printf("-1\n");
    }
    return 0;
}
