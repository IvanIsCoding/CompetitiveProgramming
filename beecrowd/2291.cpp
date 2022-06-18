// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2291
#include <cstdio>
#define MAXN 1000001
typedef long long ll;
ll soma[MAXN], acumulada[MAXN];
int main() {
    for (ll i = 1; i < MAXN; i++) {
        for (ll j = i; j < MAXN; j += i) {
            soma[j] += i;
        }
    }
    for (ll i = 1; i < MAXN; i++) {
        acumulada[i] = acumulada[i - 1] + soma[i];
    }
    int n;
    while (scanf("%d", &n) && n) {
        printf("%lld\n", acumulada[n]);
    }
    return 0;
}
