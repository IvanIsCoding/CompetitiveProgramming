// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2319
#include <algorithm>
#include <cstdio>
#define MAXN 1001
using namespace std;
const int INF = 1e7;
int m[MAXN][MAXN], processado2[MAXN][MAXN], processado5[MAXN][MAXN],
    dp2[MAXN][MAXN], dp5[MAXN][MAXN], c2[MAXN][MAXN], c5[MAXN][MAXN], n;
int solve2(int x, int y) {
    if (x > n || y > n) {
        return INF;
    }
    if (processado2[x][y]) return dp2[x][y];
    processado2[x][y] = 1;
    if (m[x][y] == 0) return dp2[x][y] = INF;
    if (x == n && y == n) {
        return dp2[x][y] = c2[x][y];
    }
    return dp2[x][y] = c2[x][y] + min(solve2(x + 1, y), solve2(x, y + 1));
}
int solve5(int x, int y) {
    if (x > n || y > n) {
        return INF;
    }
    if (processado5[x][y]) return dp5[x][y];
    processado5[x][y] = 1;
    if (m[x][y] == 0) return dp5[x][y] = INF;
    if (x == n && y == n) {
        return dp5[x][y] = c5[x][y];
    }
    return dp5[x][y] = c5[x][y] + min(solve5(x + 1, y), solve5(x, y + 1));
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 0) continue;
            int pot2 = 0, pot5 = 0;
            while (m[i][j] % 2 == 0) m[i][j] /= 2, pot2++;
            while (m[i][j] % 5 == 0) m[i][j] /= 5, pot5++;
            c2[i][j] = pot2;
            c5[i][j] = pot5;
        }
    }
    printf("%d\n", min(solve2(1, 1), solve5(1, 1)));
    return 0;
}
