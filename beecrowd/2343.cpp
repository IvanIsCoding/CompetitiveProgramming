// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2343
#include <cstdio>
#define MAXN 501
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
int matriz[MAXN][MAXN];
int main() {
    int n;
    getint(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        getint(x);
        getint(y);
        if (matriz[x][y]) {
            printf("1\n");
            return 0;
        }
        matriz[x][y] = 1;
    }
    printf("0\n");
    return 0;
}
