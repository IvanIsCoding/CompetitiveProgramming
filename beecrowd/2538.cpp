// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2538
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define LSOne(S) (S & (-S))
using namespace std;
int bit[MAXN], resp;
void update(int idx) {
    while (idx < MAXN) {
        bit[idx]++;
        idx += LSOne(idx);
    }
}
int read(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= LSOne(idx);
    }
    return ans;
}
int query(int a, int b) { return read(b) - read(a - 1); }
int main() {
    int ip, m;
    while (scanf("%d %d", &ip, &m) != EOF) {
        memset(bit, 0, sizeof(bit));
        int resp = 0;
        while (m--) {
            int pc, na;
            scanf("%d %d", &pc, &na);
            int ini = max(pc - ip, 1);
            int fim = min(pc + ip, MAXN - 1);
            int intervalo = query(ini, fim);
            if (intervalo <= na) {
                update(pc);
                resp++;
            }
        }
        printf("%d\n", resp);
    }
    return 0;
}
