// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1716
#include <cmath>
#include <cstdio>
typedef long long ll;
ll fast_expo(ll x, ll y, ll z) {
    if (y == 0) return 1LL;
    if (y == 1) return x % z;
    if (y % 2 == 0) {
        ll temp = fast_expo(x, y / 2, z);
        return (temp * temp) % z;
    }
    return (x * fast_expo(x, y - 1, z)) % z;
}
ll phi(ll val) {
    double result = val;
    for (ll p = 2; p * p <= val; p++) {
        if (val % p == 0) {
            while (val % p == 0) val /= p;
            result *= (1.0 - (1.0 / (double)p));
        }
    }
    if (val > 1) result *= (1.0 - (1.0 / (double)val));
    return (ll)result;
}
ll inv(ll val, ll mod) { return fast_expo(val, phi(mod) - 1, mod); }
int main() {
    ll n, e, c;
    scanf("%lld %lld %lld", &n, &e, &c);
    ll exibir = fast_expo(c, inv(e, phi(n)), n);
    printf("%lld\n", exibir);
    return 0;
}
