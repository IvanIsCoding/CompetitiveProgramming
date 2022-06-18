// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1621
#include <cstdio>
#include <queue>
#define MAXN 500
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
char matriz[MAXN][MAXN];
int processado1[MAXN][MAXN], processado2[MAXN][MAXN], n, m, iteracao;
int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        iteracao++;
        int xini = -1, yini = -1, xultimo, yultimo, resp;
        for (int i = 0; i < n; i++) {
            scanf("%s", matriz[i]);
            if (xini == -1)
                for (int j = 0; j < m; j++) {
                    if (matriz[i][j] == '.') {
                        xini = i;
                        yini = j;
                        break;
                    }
                }
        }
        queue<ii> bfs;
        bfs.push(MP(xini, yini));
        while (!bfs.empty()) {
            ii d = bfs.front();
            bfs.pop();
            if (processado1[d.F][d.S] == iteracao) continue;
            processado1[d.F][d.S] = iteracao;
            xultimo = d.F;
            yultimo = d.S;
            if (d.F - 1 >= 0 && matriz[d.F - 1][d.S] != '#')
                bfs.push(MP(d.F - 1, d.S));
            if (d.S - 1 >= 0 && matriz[d.F][d.S - 1] != '#')
                bfs.push(MP(d.F, d.S - 1));
            if (d.F + 1 < n && matriz[d.F + 1][d.S] != '#')
                bfs.push(MP(d.F + 1, d.S));
            if (d.S + 1 < m && matriz[d.F][d.S + 1] != '#')
                bfs.push(MP(d.F, d.S + 1));
        }
        queue<iii> diametro;
        diametro.push(MP(0, MP(xultimo, yultimo)));
        while (!diametro.empty()) {
            iii davez = diametro.front();
            diametro.pop();
            int x = davez.S.F, y = davez.S.S, percorrido = davez.F;
            if (processado2[x][y] == iteracao) continue;
            processado2[x][y] = iteracao;
            resp = percorrido;
            if (x - 1 >= 0 && matriz[x - 1][y] != '#')
                diametro.push(MP(percorrido + 1, MP(x - 1, y)));
            if (y - 1 >= 0 && matriz[x][y - 1] != '#')
                diametro.push(MP(percorrido + 1, MP(x, y - 1)));
            if (x + 1 < n && matriz[x + 1][y] != '#')
                diametro.push(MP(percorrido + 1, MP(x + 1, y)));
            if (y + 1 < m && matriz[x][y + 1] != '#')
                diametro.push(MP(percorrido + 1, MP(x, y + 1)));
        }
        printf("%d\n", resp);
    }
    return 0;
}
