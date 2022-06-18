// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2661
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    ll x = n;
    ll qtd = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (x % i != 0) continue;
        while (x % i == 0) x /= i;
        qtd++;
    }
    if (x != 1) qtd++;
    ll resp = (1LL << qtd) - qtd - 1;
    cout << max(0LL, resp) << endl;
    return 0;
}
