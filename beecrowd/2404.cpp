// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2404
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXM 124751
#define MAXN 501
int pai[MAXN], peso[MAXN], n, m, resposta;
pair<int, pair<int, int> > vetor[MAXM];
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] < peso[y])
        pai[x] = y;
    else if (peso[x] > peso[y])
        pai[y] = x;
    else {
        pai[x] = y;
        peso[y]++;
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) pai[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, peso;
        scanf("%d %d %d", &u, &v, &peso);
        vetor[i] = make_pair(peso, make_pair(u, v));
    }
    sort(vetor, vetor + m);
    for (int i = 0; i < m; i++) {
        if (find(vetor[i].second.first) != find(vetor[i].second.second)) {
            resposta += vetor[i].first;
            join(vetor[i].second.first, vetor[i].second.second);
        }
    }
    printf("%d\n", resposta);
    return 0;
}
