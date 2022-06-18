// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1752
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#define MP make_pair
#define LSOne(S) (S & (-S))
using namespace std;
typedef pair<int, int> i2;
typedef pair<int, i2> i3;
typedef pair<int, i3> i4;
const int MAXN = 501;
const int INF = 1e9;
int V[MAXN][MAXN], R[MAXN][MAXN], C[MAXN][MAXN], r, c, n, X[MAXN], Y[MAXN], xi,
    yi, xf, yf, bit[MAXN][MAXN];
set<i4> Dijkstra;
inline int H(int x, int y) { return abs(x - xf) + abs(y - yf); }
void add(int posx, int posy) {
    for (int i = posx; i < MAXN; i += LSOne(i)) {
        for (int j = posy; j < MAXN; j += LSOne(j)) {
            bit[i][j]++;
        }
    }
}
void remove(int posx, int posy) {
    for (int i = posx; i < MAXN; i += LSOne(i)) {
        for (int j = posy; j < MAXN; j += LSOne(j)) {
            bit[i][j]--;
        }
    }
}
int sum(int posx, int posy) {
    int ans = 0;
    for (int i = posx; i > 0; i -= LSOne(i)) {
        for (int j = posy; j > 0; j -= LSOne(j)) {
            ans += bit[i][j];
        }
    }
    return ans;
}
int query(int x1, int x2, int y1, int y2) {
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
           sum(x1 - 1, y1 - 1);
}
void insere(int lx, int rx, int ly, int ry, int cost, int tot) {
    if (tot == -1) tot = query(lx, rx, ly, ry);
    if (tot == 0) return;
    if (lx == rx) {
        if (ly == ry) {
            Dijkstra.insert(MP(cost + V[lx][ly], MP(H(lx, ly), MP(lx, ly))));
            remove(lx, ly);
            return;
        } else {
            int my = (ly + ry) / 2;
            int count = query(lx, rx, ly, my);
            if (count) insere(lx, rx, ly, my, cost, count);
            if (count < tot) insere(lx, rx, my + 1, ry, cost, tot - count);
        }
    } else {
        int mx = (lx + rx) / 2;
        int count = query(lx, mx, ly, ry);
        if (count) insere(lx, mx, ly, ry, cost, count);
        if (count < tot) insere(mx + 1, rx, ly, ry, cost, tot - count);
    }
}
int main() {
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &V[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &R[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &C[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    for (int vez = 1; vez + 1 <= n; vez++) {
        if (vez != 1) printf(" ");
        xi = X[vez];
        yi = Y[vez];
        xf = X[vez + 1];
        yf = Y[vez + 1];
        if (xi == xf && yi == yf) {
            printf("0");
            continue;
        }
        memset(bit, 0, sizeof(bit));
        Dijkstra.clear();
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                add(i, j);
            }
        }
        Dijkstra.insert(MP(V[xi][yi], MP(0, MP(xi, yi))));
        int possivel = 0;
        while (!Dijkstra.empty()) {
            i4 davez = *(Dijkstra.begin());
            Dijkstra.erase(Dijkstra.begin());
            int percorrido = davez.first, x = davez.second.second.first,
                y = davez.second.second.second;
            if (abs(x - xf) <= R[x][y] && abs(y - yf) <= C[x][y]) {
                possivel = 1;
                printf("%d", percorrido);
                break;
            }
            int lr = max(1, x - R[x][y]);
            int lc = max(1, y - C[x][y]);
            int rr = min(r, x + R[x][y]);
            int rc = min(c, y + C[x][y]);
            insere(lr, rr, lc, rc, percorrido, -1);
        }
        if (!possivel) printf("-1");
    }
    printf("\n");
    return 0;
}
