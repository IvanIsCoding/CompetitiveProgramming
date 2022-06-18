// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2308
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define MAXN 1001
#define LIMIT 1000001
#define MP make_pair
vii grafo[MAXN];
int matriz[MAXN][MAXN], tempo[MAXN], resposta = LIMIT, visitado[MAXN][MAXN];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tempo[i]);
        for (int j = 1; j <= n; j++) matriz[i][j] = LIMIT;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, duracao;
        scanf("%d %d %d", &u, &v, &duracao);
        grafo[u].push_back(MP(tempo[v] + duracao, v));
    }
    for (int i = 1; i <= n; i++) {
        priority_queue<ii, vii, greater<ii> > heap;
        for (int j = 0; j < (int)grafo[i].size(); j++) heap.push(grafo[i][j]);
        while (!heap.empty()) {
            ii davez = heap.top();
            heap.pop();
            if (visitado[i][davez.second]) continue;
            visitado[i][davez.second] = 1;
            matriz[i][davez.second] = davez.first;
            for (int j = 0; j < (int)grafo[davez.second].size(); j++)
                heap.push(MP(davez.first + grafo[davez.second][j].first,
                             grafo[davez.second][j].second));
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            resposta = min(resposta, matriz[i][j] + matriz[j][i]);
    printf("%d\n", resposta);
    return 0;
}
