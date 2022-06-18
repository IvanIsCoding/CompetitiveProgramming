// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1606
#include <cstdio>
#define MAXN 100010
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
int vetor[MAXN];
int main() {
    int TC = 0, n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int davez;
        getint(davez);
        vetor[davez] = ++TC;
        printf("%d", davez);
        n--;
        while (n--) {
            getint(davez);
            if (vetor[davez] != TC) {
                vetor[davez] = TC;
                printf(" %d", davez);
            }
        }
        printf("\n");
    }
    return 0;
}
