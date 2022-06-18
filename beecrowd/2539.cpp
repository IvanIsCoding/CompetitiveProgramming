// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2539
#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
const int MAXN = 1e5 + 1;
int bit[MAXN], vetor[MAXN], n;
void update(int idx) {
    while (idx < MAXN) {
        bit[idx]++;
        idx += LSOne(idx);
    }
}
int query(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= LSOne(idx);
    }
    return ans;
}
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vetor[n - i + 1]);
        }
        long long resp = 0;
        for (int i = 1; i <= n; i++) {
            int davez = query(n) - query(vetor[i] - 1);
            resp += (long long)davez;
            update(vetor[i]);
        }
        printf("%lld\n", resp);
    }
    return 0;
}
