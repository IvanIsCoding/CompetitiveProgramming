// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1688
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n, q, a, b, k;
ll xor1(ll x) {
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}
ll xorrange(ll x, ll y) {
    if (x > y) swap(x, y);
    if (y <= 0) return 0;
    x = max(x, 1LL);
    return xor1(y) ^ xor1(x - 1);
}
ll func() { return xor1(a - 1) ^ xorrange(a + k, b + k) ^ xorrange(b + 1, n); }
int main() {
    while (scanf("%lld %lld", &n, &q) != EOF) {
        while (q--) {
            scanf("%lld %lld %lld", &a, &b, &k);
            if (func())
                printf("JABBA\n");
            else
                printf("HAN\n");
        }
    }
    return 0;
}
