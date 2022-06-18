// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1554
#include <cstdio>
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n, xbola, ybola, menordist = (1 << 29), menorid = -1;
        scanf("%d %d %d", &n, &xbola, &ybola);
        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            int davez = (x - xbola) * (x - xbola) + (y - ybola) * (y - ybola);
            if (davez < menordist) {
                menordist = davez;
                menorid = i;
            }
        }
        printf("%d\n", menorid);
    }
    return 0;
}
