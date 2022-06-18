// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2520
#include <cstdio>
#include <cstdlib>
int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                int davez;
                scanf("%d", &davez);
                if (davez == 1) x1 = i, y1 = j;
                if (davez == 2) x2 = i, y2 = j;
            }
        }
        printf("%d\n", abs(y1 - y2) + abs(x1 - x2));
    }
    return 0;
}
