// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2100
#include <cstdio>
typedef long long ll;
const ll MOD = 1300031LL;
int main() {
    ll TC;
    scanf("%lld", &TC);
    while (TC--) {
        ll resp = 1;
        ll n, m;
        scanf("%lld %lld", &n, &m);
        for (ll i = 1; i <= m; i++) {
            resp *= 2;
            resp %= MOD;
        }
        for (ll i = n - m; i > n - 2 * m; i--) {
            resp *= i;
            resp %= MOD;
        }
        printf("%lld\n", resp);
    }
    return 0;
}
