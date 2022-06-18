// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1595
#include <algorithm>
#include <cstdio>
#define MAXN 100010
using namespace std;
int vetor[MAXN];
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n, c, r;
        scanf("%d %d %d", &n, &c, &r);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vetor[i]);
        }
        sort(vetor + 1, vetor + n + 1);
        double resp = 0;
        for (int i = 1; i <= c; i++) {
            resp += 1.0 / double(vetor[i] + r);
        }
        for (int i = c + 1; i <= n; i++) {
            resp += 1.0 / double(vetor[i]);
        }
        printf("%.2lf\n", resp);
    }
    return 0;
}
