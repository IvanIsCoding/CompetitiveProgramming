// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2561
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF) {
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
        int x5 = max(x1, x3);
        int y5 = max(y1, y3);
        int x6 = min(x2, x4);
        int y6 = min(y2, y4);
        if (x5 > x6 || y5 > y6) {
            printf("inexistente\n");
            continue;
        }
        if (x5 == x6 && y5 == y6) {
            printf("ponto\n");
            continue;
        }
        if (x5 == x6 || y5 == y6) {
            printf("linha\n");
            continue;
        }
        int area = abs(x5 - x6) * abs(y5 - y6);
        if (area <= 10)
            printf("adequada\n");
        else
            printf("grande\n");
    }
    return 0;
}
