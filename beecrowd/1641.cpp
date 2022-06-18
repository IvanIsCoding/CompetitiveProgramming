// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1641
#include <cstdio>
int pizza;
int main() {
    int r, l, w;
    while (scanf("%d", &r) && r) {
        scanf("%d %d", &w, &l);
        pizza++;
        int delta = 4 * r * r - w * w - l * l;
        if (delta >= 0)
            printf("Pizza %d fits on the table.\n", pizza);
        else
            printf("Pizza %d does not fit on the table.\n", pizza);
    }
    return 0;
}
