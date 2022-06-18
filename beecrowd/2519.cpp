// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2519
#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
#define MAXN 1010
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
int bit[MAXN][MAXN], n, m, q;
void update(int posx, int posy, int val) {
    for (int i = posx; i < MAXN; i += LSOne(i)) {
        for (int j = posy; j < MAXN; j += LSOne(j)) {
            bit[i][j] += val;
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
    return ans;
}
int query(int x1, int y1, int x2, int y2) {
    return read(x2, y2) - read(x1 - 1, y2) - read(x2, y1 - 1) +
           read(x1 - 1, y1 - 1);
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int davez;
                getint(davez);
                if (davez) update(i, j, davez);
            }
        }
        getint(q);
        while (q--) {
            int op;
            getint(op);
            if (op == 0) {
                int a, b, c, d;
                getint(a);
                getint(b);
                getint(c);
                getint(d);
                update(a, b, -1);
                update(c, d, 1);
            } else {
                int a, b, c, d;
                getint(a);
                getint(b);
                getint(c);
                getint(d);
                printf("%d\n", query(a, b, c, d));
            }
        }
    }
    return 0;
}
