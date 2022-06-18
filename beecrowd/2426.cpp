// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2426
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 550
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n, e, s, m, visitados[MAXN], visitados1[MAXN], visitados2[MAXN];
vi grafo_multiplo[MAXN], grafo_normal[MAXN];
int main() {
    scanf("%d %d %d %d", &n, &e, &s, &m);
    while (m--) {
        int u, v, tipo;
        scanf("%d %d %d", &u, &v, &tipo);
        if (tipo)
            grafo_multiplo[u].PB(v);
        else
            grafo_normal[u].PB(v);
    }
    queue<ii> fila;
    fila.push(MP(e, 0));
    while (!fila.empty()) {
        ii davez = fila.front();
        fila.pop();
        int v = davez.first, d = davez.second;
        if (v == s) {
            printf("%d\n", d);
            return 0;
        }
        if (d % 3 == 0) {
            if (visitados[v]) continue;
            visitados[v] = 1;
            for (int i = 0; i < grafo_multiplo[v].size(); i++)
                fila.push(MP(grafo_multiplo[v][i], d + 1));
        }
        if (d % 3 == 1) {
            if (visitados1[v]) continue;
            visitados1[v] = 1;
            for (int i = 0; i < grafo_normal[v].size(); i++)
                fila.push(MP(grafo_normal[v][i], d + 1));
        }
        if (d % 3 == 2) {
            if (visitados2[v]) continue;
            visitados2[v] = 1;
            for (int i = 0; i < grafo_normal[v].size(); i++)
                fila.push(MP(grafo_normal[v][i], d + 1));
        }
    }
    printf("*\n");
    return 0;
}
