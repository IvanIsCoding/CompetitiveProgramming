// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2452
#include <cstdio>
#include <queue>
#include <set>
#define MAXN 100001
using namespace std;
set<int> visitado;
int resposta, n, m, trabalhando;
int main() {
    queue<pair<int, int> > fila;
    scanf("%d %d", &n, &m);
    visitado.insert(0);
    visitado.insert(n + 1);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        fila.push(make_pair(x, 0));
    }
    while (!fila.empty() && visitado.size() - 2 < n) {
        pair<int, int> davez = fila.front();
        fila.pop();
        resposta = davez.second;
        trabalhando = davez.first;
        visitado.insert(trabalhando);

        if (!visitado.count(trabalhando - 1))
            fila.push(make_pair(trabalhando - 1, resposta + 1));
        if (!visitado.count(trabalhando + 1))
            fila.push(make_pair(trabalhando + 1, resposta + 1));
    }
    printf("%d\n", resposta);
    return 0;
}
