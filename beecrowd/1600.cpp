// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1600
#include <cstdio>
#include <queue>
#define MAXN 25
#define MAXL 32
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair<int, int> i2;
typedef pair<int, i2> i3;
typedef pair<int, i3> i4;
typedef pair<int, i4> i5;
typedef pair<int, i5> i6;
typedef pair<int, i6> i7;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int processado[MAXN][MAXN][MAXN][MAXN][MAXL], conversao[MAXN][MAXN], portas, n,
    m, iteracao, xgato, ygato, xbau, ybau, possivel;
char mapa[MAXN][MAXN];
inline int contabits(int bitmask) {
    int ans = 0;
    for (int i = 0; i < portas; i++) {
        if (bitmask & (1 << i)) ans++;
    }
    return ans;
}
inline int valido(int x, int y) {
    if (x < 0) return 0;
    if (y < 0) return 0;
    if (x >= n) return 0;
    if (y >= m) return 0;
    if (mapa[x][y] == '*') return 0;
    return 1;
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        portas = 0;
        possivel = 0;
        iteracao++;
        for (int i = 0; i < n; i++) {
            scanf("%s", mapa[i]);
            for (int j = 0; j < m; j++) {
                if (mapa[i][j] == 'j') {
                    xgato = i;
                    ygato = j;
                }
                if (mapa[i][j] == 'b') {
                    xbau = i;
                    ybau = j;
                }
                if (mapa[i][j] == '#') {
                    conversao[i][j] = portas++;
                }
            }
        }
        priority_queue<i7, vector<i7>, greater<i7> > Dijkstra;
        Dijkstra.push(
            MP(0, MP(0, MP(0, MP(xgato, MP(ygato, MP(xbau, ybau)))))));
        while (!Dijkstra.empty()) {
            i7 d = Dijkstra.top();
            Dijkstra.pop();
            int ligados = d.F, percorrido = d.S.F, oldbitmask = d.S.S.F,
                xg = d.S.S.S.F, yg = d.S.S.S.S.F, xb = d.S.S.S.S.S.F,
                yb = d.S.S.S.S.S.S;
            if (mapa[xb][yb] == 'x') {
                possivel = 1;
                printf("%d %d\n", ligados, percorrido);
                break;
            }
            if (processado[xg][yg][xb][yb][oldbitmask] == iteracao) continue;
            // printf("%d %d %d %d\n",xg,yg,xb,yb);
            processado[xg][yg][xb][yb][oldbitmask] = iteracao;
            int bitmask = oldbitmask;
            if (mapa[xg][yg] == '#') {
                bitmask |= (1 << conversao[xg][yg]);
            }
            for (int i = 0; i < 4; i++) {
                int nxg = xg + dx[i];
                int nyg = yg + dy[i];
                if (nxg == xb && nyg == yb) {
                    int nxb = xb + dx[i];
                    int nyb = yb + dy[i];
                    if (!valido(nxb, nyb)) continue;
                    if (mapa[nxb][nyb] == '#' &&
                        !(bitmask & (1 << conversao[nxb][nyb])))
                        continue;
                    Dijkstra.push(
                        MP(contabits(bitmask),
                           MP(percorrido + 1,
                              MP(bitmask, MP(nxg, MP(nyg, MP(nxb, nyb)))))));
                } else {
                    if (valido(nxg, nyg))
                        Dijkstra.push(
                            MP(contabits(bitmask),
                               MP(percorrido + 1,
                                  MP(bitmask, MP(nxg, MP(nyg, MP(xb, yb)))))));
                }
            }
        }
        if (!possivel) printf("-1\n");
    }
    return 0;
}
