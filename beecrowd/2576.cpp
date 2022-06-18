// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2576
#include <cstdio>
#include <deque>
#include <vector>
#define MAXN 10010
using namespace std;
typedef pair<int, int> ii;
int processado1[MAXN], processado2[MAXN], pai[MAXN], peso[MAXN];
vector<int> grafo[MAXN], transposto[MAXN];
int bibi, bibika;
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] < peso[y]) {
        pai[x] = y;
    } else if (peso[x] > peso[y]) {
        pai[y] = x;
    } else {
        pai[x] = y;
        peso[y]++;
    }
}
int main() {
    int c, s, a, b;
    scanf("%d %d %d %d", &c, &s, &a, &b);
    while (s--) {
        int u, v;
        scanf("%d %d", &u, &v);
        join(u, v);
        grafo[u].push_back(v);
        transposto[v].push_back(u);
    }
    if (find(a) != find(b)) {
        printf("Bibibibika\n");
        return 0;
    }
    deque<ii> fila1, fila2;
    fila1.push_back(ii(0, a));
    while (!fila1.empty()) {
        ii davez = fila1.front();
        fila1.pop_front();
        int v = davez.second, dist = davez.first;
        if (processado1[v]) continue;
        processado1[v] = 1;
        if (v == b) {
            bibi = dist;
            break;
        }
        for (int u : grafo[v]) {
            if (!processado1[u]) fila1.push_front(ii(dist, u));
        }
        for (int u : transposto[v]) {
            if (!processado1[u]) fila1.push_back(ii(dist + 1, u));
        }
    }
    fila2.push_back(ii(0, b));
    while (!fila2.empty()) {
        ii davez = fila2.front();
        fila2.pop_front();
        int v = davez.second, dist = davez.first;
        if (processado2[v]) continue;
        processado2[v] = 1;
        if (v == a) {
            bibika = dist;
            break;
        }
        for (int u : grafo[v]) {
            if (!processado2[u]) fila2.push_front(ii(dist, u));
        }
        for (int u : transposto[v]) {
            if (!processado2[u]) fila2.push_back(ii(dist + 1, u));
        }
    }
    if (bibi < bibika) {
        printf("Bibi: %d\n", bibi);
    } else if (bibi > bibika) {
        printf("Bibika: %d\n", bibika);
    } else {
        printf("Bibibibika\n");
    }
    return 0;
}
