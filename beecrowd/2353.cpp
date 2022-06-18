// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2353
#include <cstdio>
typedef long long ll;
bool isprime(ll x) {
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    ll n;
    scanf("%lld", &n);
    while (n > 0) {
        if (isprime(n)) {
            printf("%lld\n", n);
            return 0;
        }
        n--;
    }
    return 0;
}
