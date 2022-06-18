// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2188
#include <cstdio>
#define INF 10010
#define NEGINF -INF
int main() {
    int teste = 1, n;
    while (scanf("%d", &n) && n) {
        printf("Teste %d\n", teste++);
        int x1 = NEGINF, y1 = INF, x2 = INF, y2 = NEGINF;
        for (int k = 0; k < n; k++) {
            int x3, y3, x4, y4;
            scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
            if (x3 > x1) x1 = x3;
            if (y3 < y1) y1 = y3;
            if (x4 < x2) x2 = x4;
            if (y4 > y2) y2 = y4;
        }
        if (x1 > x2 || y2 > y1)
            printf("nenhum\n\n");
        else
            printf("%d %d %d %d\n\n", x1, y1, x2, y2);
    }
    return 0;
}
