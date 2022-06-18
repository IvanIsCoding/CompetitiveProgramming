// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2173
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 10010
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int pai[MAXN], peso[MAXN];
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] < peso[y])
        pai[x] = y;
    else if (peso[x] > peso[y])
        pai[y] = x;
    else {
        peso[y]++;
        pai[x] = y;
    }
}
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        vector<iii> Kruskal;
        int conjuntos = n, maximo = 0, minimo = 0;
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            Kruskal.PB(MP(peso, MP(u, v)));
        }
        sort(Kruskal.begin(), Kruskal.end());
        for (int i = 0; i < m && conjuntos != 1; i++) {
            if (find(Kruskal[i].second.first) !=
                find(Kruskal[i].second.second)) {
                minimo += Kruskal[i].first;
                join(Kruskal[i].second.first, Kruskal[i].second.second);
                conjuntos--;
            }
        }
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
        }
        conjuntos = n;
        for (int i = m - 1; i >= 0 && conjuntos != 1; i--) {
            if (find(Kruskal[i].second.first) !=
                find(Kruskal[i].second.second)) {
                maximo += Kruskal[i].first;
                join(Kruskal[i].second.first, Kruskal[i].second.second);
            }
        }
        printf("%d\n", maximo - minimo);
    }
    return 0;
}
