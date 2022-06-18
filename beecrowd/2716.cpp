// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2716
#include <bits/stdc++.h>
using namespace std;
bitset<300010> bt;
int n, total, possivel;
int main() {
    while (scanf("%d", &n) != EOF) {
        bt.reset();
        total = 0;
        possivel = 1e9;
        bt.set(0, 1);
        while (n--) {
            int x;
            scanf("%d", &x);
            bt |= (bt << x);
            total += x;
        }
        for (int i = 0; i <= total / 2 + 1; i++) {
            if (!bt.test(i)) continue;
            int j = total - i;
            possivel = min(possivel, abs(j - i));
        }
        printf("%d\n", possivel);
    }
    return 0;
}
