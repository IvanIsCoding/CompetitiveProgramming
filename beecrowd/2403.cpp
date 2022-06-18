// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2403
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100100
int n, m, grau[MAXN];
vector<int> lista, grafo[MAXN];
priority_queue<int, vector<int>, greater<int> > fila;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        grau[y]++;
        grafo[x].push_back(y);
    }
    for (int i = 0; i < n; i++)
        if (!grau[i]) fila.push(i);
    while (!fila.empty()) {
        int atual = fila.top();
        fila.pop();
        lista.push_back(atual);
        for (int i = 0; i < grafo[atual].size(); i++) {
            int v = grafo[atual][i];
            grau[v]--;
            if (!grau[v]) fila.push(v);
        }
    }
    if (lista.size() < n)
        printf("*\n");
    else
        for (int i = 0; i < lista.size(); i++) printf("%d\n", lista[i]);
    return 0;
}
