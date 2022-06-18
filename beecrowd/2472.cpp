// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2472
#include <cstdio>
typedef long long ll;
int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll val = (a - b + 1) * (a - b + 1);
    val += b - 1;
    printf("%lld\n", val);
    return 0;
}
