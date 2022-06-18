// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2680
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    scanf("%lld", &n);
    while (n--) {
        ll x;
        scanf("%lld", &x);
        ll copia = x;
        ll soma = 1;
        for (ll i = 2; i * i <= x; i++) {
            if (copia % i == 0) {
                ll tot = 1;
                ll pot = i;
                while (copia % i == 0) {
                    copia /= i;
                    tot += pot;
                    pot *= i;
                }
                soma *= tot;
            }
        }
        if (copia != 1) soma = soma * (copia + 1);
        printf("%lld\n", soma);
    }
    return 0;
}
