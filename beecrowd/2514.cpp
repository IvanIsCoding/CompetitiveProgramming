// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2514
#include <algorithm>
#include <cstdio>
using namespace std;
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}
int mmc(int a, int b) { return a * (b / gcd(a, b)); }
int mmc(int a, int b, int c) { return mmc(mmc(a, b), c); }
int main() {
    int m, l1, l2, l3;
    while (scanf("%d", &m) != EOF) {
        scanf("%d %d %d", &l1, &l2, &l3);
        printf("%d\n", -m + mmc(l1, l2, l3));
    }
    return 0;
}
