// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2294
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define MAXN 15
#define MP make_pair
#define LIMIT 9999
int matriz[MAXN][MAXN], n, m, gugox, gugoy, resposta = LIMIT, i, j,
                                            distancias[MAXN][MAXN];
set<pair<int, int> > pares, visitado;
set<pair<int, int> >::iterator it;
int main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] == 0) {
                pares.insert(MP(i, j));
            }
            if (matriz[i][j] == 3) {
                gugox = i;
                gugoy = j;
            }
        }
    memset(distancias, LIMIT, sizeof(distancias));
    queue<pair<pair<int, int>, int> > fila;
    fila.push(MP(MP(gugox, gugoy), 0));
    while (!fila.empty()) {
        pair<pair<int, int>, int> davez = fila.front();
        fila.pop();
        if (visitado.count(davez.first) ||
            matriz[davez.first.first][davez.first.second] == 2 ||
            !davez.first.first || !davez.first.second ||
            davez.first.first > n || davez.first.second > m)
            continue;
        distancias[davez.first.first][davez.first.second] = davez.second;
        visitado.insert(davez.first);
        fila.push(MP(MP(davez.first.first + 1, davez.first.second),
                     davez.second + 1));
        fila.push(MP(MP(davez.first.first - 1, davez.first.second),
                     davez.second + 1));
        fila.push(MP(MP(davez.first.first, davez.first.second + 1),
                     davez.second + 1));
        fila.push(MP(MP(davez.first.first, davez.first.second - 1),
                     davez.second + 1));
    }
    for (it = pares.begin(); it != pares.end(); it++) {
        resposta = min(distancias[(*it).first][(*it).second], resposta);
    }
    printf("%d\n", resposta);
    return 0;
}
