// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2436
#include <cstdio>
#include <queue>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
#define MAXN 1010
int visitado[MAXN][MAXN], matriz[MAXN][MAXN], x, y, n, m;
int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    queue<ii> bfs;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &matriz[i][j]);
    bfs.push(MP(x, y));
    while (!bfs.empty()) {
        ii davez = bfs.front();
        bfs.pop();
        if (visitado[davez.first][davez.second]) continue;
        x = davez.first;
        y = davez.second;
        visitado[x][y] = 1;
        if (matriz[x + 1][y]) bfs.push(MP(x + 1, y));
        if (matriz[x - 1][y]) bfs.push(MP(x - 1, y));
        if (matriz[x][y + 1]) bfs.push(MP(x, y + 1));
        if (matriz[x][y - 1]) bfs.push(MP(x, y - 1));
    }
    printf("%d %d\n", x, y);
    return 0;
}
