// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2443
#include <algorithm>
#include <cstdio>
using namespace std;
int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if ((x % y) == 0) return y;
    return gcd(y, x % y);
}
int main() {
    int n1, d1, n2, d2;
    scanf("%d %d %d %d", &n1, &d1, &n2, &d2);
    int cima = n1 * d2 + n2 * d1;
    int debaixo = d1 * d2;
    int mdc = gcd(cima, debaixo);
    printf("%d %d\n", cima / mdc, debaixo / mdc);
    return 0;
}
