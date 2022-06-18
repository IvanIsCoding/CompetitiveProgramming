// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2091
#include <cstdio>
typedef long long ll;
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        ll resp = 0;
        while (n--) {
            ll davez;
            scanf("%lld", &davez);
            resp ^= davez;
        }
        printf("%lld\n", resp);
    }
    return 0;
}
