// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2537
#include <cstdio>
#include <cstring>
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
#define LSOne(S) (S & (-S))
const int MAXN = 1010;
int bit[MAXN][MAXN], vetor[MAXN][MAXN], n, m;
void update(int posx, int posy) {
    for (int i = posx; i <= n; i += LSOne(i)) {
        for (int j = posy; j <= n; j += LSOne(j)) {
            bit[i][j]++;
        }
    }
}
int read(int posx, int posy) {
    int ans = 0;
    for (int i = posx; i > 0; i -= LSOne(i)) {
        for (int j = posy; j > 0; j -= LSOne(j)) {
            ans += bit[i][j];
        }
    }
    return ans + vetor[posx][posy];
}
int query(int x1, int y1, int x2, int y2) {
    return read(x2, y2) - read(x2, y1 - 1) - read(x1 - 1, y2) +
           read(x1 - 1, y1 - 1);
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            memset(bit[i], 0, sizeof(int) * (n + 2));
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int davez;
                scanf("%d", &davez);
                vetor[i][j] = vetor[i][j - 1] + vetor[i - 1][j] + davez -
                              vetor[i - 1][j - 1];
            }
        }
        while (m--) {
            int a, b, c, d;
            scanf("%d %d", &a, &b);
            update(a, b);
            scanf("%d %d %d %d", &a, &b, &c, &d);
            printf("%d\n", query(a, b, c, d));
        }
    }
    return 0;
}
