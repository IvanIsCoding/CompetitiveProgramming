// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2288
#include <cstdio>
#define MAXN 1001
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = gc())
        ;
    if (c == '-') {
        neg = 1;
        c = gc();
    }
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}
int matriz[MAXN][MAXN], nova[MAXN][MAXN];
int main() {
    int n, m, teste = 1;
    while (true) {
        getint(n);
        getint(m);
        if (n == 0 && m == 0) break;
        printf("Teste %d\n", teste++);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                getint(matriz[i][j]);
            }
        }
        int deltax = 0, deltay = 0, davezx, davezy;
        while (true) {
            getint(davezx);
            getint(davezy);
            if (davezx == 0 && davezy == 0) break;
            deltax += davezx;
            deltay += davezy;
        }
        deltay *= -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != 0) printf(" ");
                printf("%d", matriz[(n + (i - deltay) % n) % n]
                                   [(m + (j - deltax) % m) % m]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
