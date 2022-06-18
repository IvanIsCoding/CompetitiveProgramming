// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2550
#include <algorithm>
#include <cstdio>
#include <vector>
#define MP make_pair
#define MAXN 1010
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int pai[MAXN], peso[MAXN], n, m, conjunto;
inline int find(int x) {
    while (pai[x] != x) x = pai[x];
    return x;
}
void join(int x, int y) {
    if (peso[x] < peso[y]) {
        pai[x] = y;
    } else if (peso[x] > peso[y]) {
        pai[y] = x;
    } else {
        peso[y]++;
        pai[x] = y;
    }
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        vector<iii> Kruskal;
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            Kruskal.push_back(MP(peso, MP(u, v)));
        }
        sort(Kruskal.begin(), Kruskal.end());
        conjunto = n;
        int custo = 0;
        for (int i = 0; i < m; i++) {
            int u = find(Kruskal[i].second.first);
            int v = find(Kruskal[i].second.second);
            if (u != v) {
                custo += Kruskal[i].first;
                join(u, v);
                conjunto--;
            }
        }
        if (conjunto != 1)
            printf("impossivel\n");
        else
            printf("%d\n", custo);
    }
    return 0;
}
