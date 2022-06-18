// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2081
#include <cstdio>
#include <queue>
#define MAXN 51
using namespace std;
int processado[MAXN][MAXN][MAXN][MAXN], n, m;
struct ponto {
    int percorrido, x1, x2, y1, y2;
};
char mapa1[MAXN][MAXN], mapa2[MAXN][MAXN];
int main() {
    int TC;
    scanf("%d", &TC);
    for (int instancia = 1; instancia <= TC; instancia++) {
        int possivel = 0;
        scanf("%d %d", &n, &m);
        int xr1, xr2, xf1, xf2, yr1, yr2, yf2, yf1;
        for (int i = 0; i < n; i++) {
            scanf("%s", mapa1[i]);
            for (int j = 0; j < m; j++) {
                if (mapa1[i][j] == 'R') {
                    xr1 = i;
                    yr1 = j;
                }
                if (mapa1[i][j] == 'F') {
                    xf1 = i;
                    yf1 = j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", mapa2[i]);
            for (int j = 0; j < m; j++) {
                if (mapa2[i][j] == 'R') {
                    xr2 = i;
                    yr2 = j;
                }
                if (mapa2[i][j] == 'F') {
                    xf2 = i;
                    yf2 = j;
                }
            }
        }
        queue<ponto> bfs;
        ponto inicial;
        inicial.percorrido = 0;
        inicial.x1 = xr1;
        inicial.x2 = xr2;
        inicial.y1 = yr1;
        inicial.y2 = yr2;
        bfs.push(inicial);
        while (!bfs.empty()) {
            ponto d = bfs.front();
            bfs.pop();
            if (processado[d.x1][d.y1][d.x2][d.y2] == instancia ||
                d.percorrido >= MAXN)
                continue;
            processado[d.x1][d.y1][d.x2][d.y2] = instancia;
            if (d.x1 == xf1 && d.y1 == yf1 && d.x2 == xf2 && d.y2 == yf2) {
                printf("%d\n", d.percorrido);
                possivel = 1;
                break;
            }
            if (d.x1 - 1 >= 0 && d.x2 - 1 >= 0 &&
                mapa1[d.x1 - 1][d.y1] != 'B' && mapa2[d.x2 - 1][d.y2] != 'B') {
                ponto proximo;
                proximo.percorrido = d.percorrido + 1;
                proximo.x1 = d.x1 - (mapa1[d.x1 - 1][d.y1] != '#') * 1;
                proximo.x2 = d.x2 - (mapa2[d.x2 - 1][d.y2] != '#') * 1;
                proximo.y1 = d.y1;
                proximo.y2 = d.y2;
                if (processado[proximo.x1][proximo.y1][proximo.x2]
                              [proximo.y2] != instancia)
                    bfs.push(proximo);
            }
            if (d.x1 + 1 < n && d.x2 + 1 < n && mapa1[d.x1 + 1][d.y1] != 'B' &&
                mapa2[d.x2 + 1][d.y2] != 'B') {
                ponto proximo;
                proximo.percorrido = d.percorrido + 1;
                proximo.x1 = d.x1 + (mapa1[d.x1 + 1][d.y1] != '#') * 1;
                proximo.x2 = d.x2 + (mapa2[d.x2 + 1][d.y2] != '#') * 1;
                proximo.y1 = d.y1;
                proximo.y2 = d.y2;
                if (processado[proximo.x1][proximo.y1][proximo.x2]
                              [proximo.y2] != instancia)
                    bfs.push(proximo);
            }
            if (d.y1 - 1 >= 0 && d.y2 - 1 >= 0 &&
                mapa1[d.x1][d.y1 - 1] != 'B' && mapa2[d.x2][d.y2 - 1] != 'B') {
                ponto proximo;
                proximo.percorrido = d.percorrido + 1;
                proximo.y1 = d.y1 - (mapa1[d.x1][d.y1 - 1] != '#') * 1;
                proximo.y2 = d.y2 - (mapa2[d.x2][d.y2 - 1] != '#') * 1;
                proximo.x1 = d.x1;
                proximo.x2 = d.x2;
                if (processado[proximo.x1][proximo.y1][proximo.x2]
                              [proximo.y2] != instancia)
                    bfs.push(proximo);
            }
            if (d.y1 + 1 < m && d.y2 + 1 < m && mapa1[d.x1][d.y1 + 1] != 'B' &&
                mapa2[d.x2][d.y2 + 1] != 'B') {
                ponto proximo;
                proximo.percorrido = d.percorrido + 1;
                proximo.y1 = d.y1 + (mapa1[d.x1][d.y1 + 1] != '#') * 1;
                proximo.y2 = d.y2 + (mapa2[d.x2][d.y2 + 1] != '#') * 1;
                proximo.x1 = d.x1;
                proximo.x2 = d.x2;
                if (processado[proximo.x1][proximo.y1][proximo.x2]
                              [proximo.y2] != instancia)
                    bfs.push(proximo);
            }
        }
        if (!possivel) printf("impossivel\n");
    }
    return 0;
}
