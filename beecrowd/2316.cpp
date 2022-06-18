// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2316
#include <algorithm>
#include <cstdio>
#define MAXN 110
using namespace std;
int k, n, m;
int ultimo[MAXN], voltas[MAXN], competidores[MAXN], momentoconclusao[MAXN];
bool compara(int x, int y) {
    if (voltas[x] == voltas[y]) {
        if (ultimo[x] == ultimo[y]) {
            if (momentoconclusao[x] == momentoconclusao[y]) return x < y;
            return momentoconclusao[x] < momentoconclusao[y];
        }
        return ultimo[x] > ultimo[y];
    }
    return voltas[x] > voltas[y];
}
int main() {
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 1; i <= n; i++) competidores[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b - ultimo[a] == 1) {
            momentoconclusao[a] = i;
            if (b == k) {
                voltas[a] += 1;
                ultimo[a] = 0;
            } else {
                ultimo[a]++;
            }
        }
    }
    sort(competidores + 1, competidores + n + 1, compara);
    printf("%d", competidores[1]);
    for (int i = 2; i <= n; i++) printf(" %d", competidores[i]);
    printf("\n");
    return 0;
}
