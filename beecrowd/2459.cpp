// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2459
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 110
#define MAXM 5000
int pai[MAXN], peso[MAXN], n, f, r, resposta;
pair<int, pair<int, int> > ferrovias[MAXM], rodovias[MAXM];
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
        pai[x] = y;
        peso[y]++;
    }
}
int main() {
    scanf("%d %d %d", &n, &f, &r);
    for (int i = 1; i <= n; i++) pai[i] = i;
    for (int i = 0; i < f; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        ferrovias[i] = make_pair(peso, make_pair(u, v));
    }
    for (int i = 0; i < r; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        rodovias[i] = make_pair(peso, make_pair(u, v));
    }
    sort(ferrovias, ferrovias + f);
    sort(rodovias, rodovias + r);
    for (int i = 0; i < f; i++) {
        if (find(ferrovias[i].second.first) !=
            find(ferrovias[i].second.second)) {
            resposta += ferrovias[i].first;
            join(ferrovias[i].second.first, ferrovias[i].second.second);
        }
    }
    for (int i = 0; i < r; i++) {
        if (find(rodovias[i].second.first) != find(rodovias[i].second.second)) {
            resposta += rodovias[i].first;
            join(rodovias[i].second.first, rodovias[i].second.second);
        }
    }
    printf("%d\n", resposta);
    return 0;
}
