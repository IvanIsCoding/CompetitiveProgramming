// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2332
#include <cstdio>
#include <queue>
#define MP make_pair
#define MAXN 100
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int matriz[MAXN][MAXN], processado[MAXN][MAXN];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    priority_queue<iii, vector<iii>, greater<iii> > bfs;
    bfs.push(MP(0, MP(1, 1)));
    while (!bfs.empty()) {
        iii davez = bfs.top();
        bfs.pop();
        int x = davez.second.first, y = davez.second.second,
            tempo = davez.first;
        if (processado[x][y]) continue;
        processado[x][y] = 1;
        if (x == n && y == m) {
            printf("%d\n", tempo);
            return 0;
        }
        if (x + 1 <= n) {
            for (int k = 0; k <= 20; k++) {
                int a1 = (matriz[x][y] + tempo + k) % 10;
                int a2 = (matriz[x + 1][y] + tempo + k) % 10;
                if (a1 + 1 >= a2) {
                    bfs.push(MP(tempo + k + 1, MP(x + 1, y)));
                    break;
                }
            }
        }
        if (y + 1 <= m) {
            for (int k = 0; k <= 20; k++) {
                int a1 = (matriz[x][y] + tempo + k) % 10;
                int a2 = (matriz[x][y + 1] + tempo + k) % 10;
                if (a1 + 1 >= a2) {
                    bfs.push(MP(tempo + k + 1, MP(x, y + 1)));
                    break;
                }
            }
        }
        if (x - 1 >= 1) {
            for (int k = 0; k <= 20; k++) {
                int a1 = (matriz[x][y] + tempo + k) % 10;
                int a2 = (matriz[x - 1][y] + tempo + k) % 10;
                if (a1 + 1 >= a2) {
                    bfs.push(MP(tempo + k + 1, MP(x - 1, y)));
                    break;
                }
            }
        }
        if (y - 1 >= 1) {
            for (int k = 0; k <= 20; k++) {
                int a1 = (matriz[x][y] + tempo + k) % 10;
                int a2 = (matriz[x][y - 1] + tempo + k) % 10;
                if (a1 + 1 >= a2) {
                    bfs.push(MP(tempo + k + 1, MP(x, y - 1)));
                    break;
                }
            }
        }
    }
    return 0;
}
