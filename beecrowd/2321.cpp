// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2321
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int a, b, c, d, e, f, g, h;
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
    int xmin = max(a, e);
    int xmax = min(c, g);
    if (xmin > xmax) {
        printf("0\n");
        return 0;
    }
    int ymin = max(b, f);
    int ymax = min(d, h);
    if (ymin > ymax) {
        printf("0\n");
        return 0;
    }
    printf("1\n");
    return 0;
}
