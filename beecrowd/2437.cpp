// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2437
#include <cstdio>
#include <cstdlib>
int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
    return 0;
}
