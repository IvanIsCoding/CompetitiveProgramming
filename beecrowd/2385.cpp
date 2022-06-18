// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2385
#include <cstdio>
typedef long long ll;
ll resposta;
int main() {
    int ordem, p, q, r, s, x, y, a, b;
    scanf("%d %d %d %d %d %d %d %d %d", &ordem, &p, &q, &r, &s, &x, &y, &a, &b);
    for (int i = 1; i <= ordem; i++) {
        ll elemento1 = (p * a + q * i) % x;
        ll elemento2 = (i * r + s * b) % y;
        resposta += elemento1 * elemento2;
    }
    printf("%lld\n", resposta);
    return 0;
}
