// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2683
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tripla;
const int MAXN = 1e3 + 10;
int pai[MAXN], peso[MAXN], n, r1, r2;
vector<tripla> Kruskal;
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
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
    scanf("%d", &n);
    for (int i = 1; i < MAXN; i++) {
        pai[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int a, b, peso;
        scanf("%d %d %d", &a, &b, &peso);
        Kruskal.push_back(make_tuple(peso, a, b));
    }
    sort(Kruskal.begin(), Kruskal.end());
    for (int i = 0; i < n; i++) {
        int u = get<1>(Kruskal[i]), v = get<2>(Kruskal[i]),
            peso = get<0>(Kruskal[i]);
        if (find(u) != find(v)) {
            join(u, v);
            r1 += peso;
        }
    }
    for (int i = 1; i < MAXN; i++) {
        pai[i] = i;
    }
    reverse(Kruskal.begin(), Kruskal.end());
    for (int i = 0; i < n; i++) {
        int u = get<1>(Kruskal[i]), v = get<2>(Kruskal[i]),
            peso = get<0>(Kruskal[i]);
        if (find(u) != find(v)) {
            join(u, v);
            r2 += peso;
        }
    }
    printf("%d\n%d\n", r2, r1);
    return 0;
}
