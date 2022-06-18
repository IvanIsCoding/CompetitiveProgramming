// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2073
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 1001
#define LSOne(S) (S & (-S))
int bit[MAXN][MAXN];
void update(int x, int y, int val) {
    for (int i = x; i < MAXN; i += LSOne(i))
        for (int j = y; j < MAXN; j += LSOne(j))
            bit[i][j] = max(bit[i][j], val);
}
int get(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= LSOne(i))
        for (int j = y; j > 0; j -= LSOne(j)) sum = max(bit[i][j], sum);
    return sum;
}
int main() {
    int casos, n;
    scanf("%d", &casos);
    while (casos--) {
        int resposta = 0;
        memset(bit, 0, sizeof(bit));
        scanf("%d", &n);
        for (int agora = 0; agora < n; agora++) {
            int p, q;
            scanf("%d %d", &p, &q);
            int valor = get(p, q) + 1;
            update(p, q, valor);
            resposta = max(resposta, valor);
        }
        printf("%d\n", resposta);
    }
    return 0;
}
