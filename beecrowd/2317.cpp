// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2317
#include <cstdio>
#include <set>
#define MAXN 260
#define MAXC 63500
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
int lobos[MAXC], ovelhas[MAXC], visitado[MAXN][MAXN], componentes, resposta1,
    resposta2, n, m;
char matriz[MAXN][MAXN];
void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || visitado[x][y]) return;
    visitado[x][y] = 1;
    if (matriz[x][y] == '#')
        return;
    else if (matriz[x][y] == 'k')
        ovelhas[componentes]++;
    else if (matriz[x][y] == 'v')
        lobos[componentes]++;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main() {
    set<ii> cordenadas;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", matriz[i]);
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 'k' || matriz[i][j] == 'v')
                cordenadas.insert(MP(i, j));
        }
    }
    for (set<ii>::iterator it = cordenadas.begin(); it != cordenadas.end();
         it++) {
        int coordx = (*it).first, coordy = (*it).second;
        if (!visitado[coordx][coordy]) {
            componentes++;
            dfs(coordx, coordy);
        }
    }
    for (int i = 1; i <= componentes; i++) {
        if (lobos[i] >= ovelhas[i]) {
            resposta2 += lobos[i];
        } else
            resposta1 += ovelhas[i];
    }
    printf("%d %d\n", resposta1, resposta2);
    return 0;
}
