// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2190
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXN 110
int pai[MAXN], peso[MAXN], n, m, teste = 1;
struct Aresta {
    int first;
    pair<int, int> second;
};
Aresta vetor[MAXN * MAXN / 2];
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
int Compara(const void *a, const void *b) {
    Aresta *A = (Aresta *)a, *B = (Aresta *)b;

    if (A->first > B->first)
        return +1;
    else if (A->first < B->first)
        return -1;
    else
        return 0;
}
int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        printf("Teste %d\n", teste++);
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v, peso;
            scanf("%d %d %d", &u, &v, &peso);
            if (u > v) swap(u, v);
            vetor[i].first = peso;
            vetor[i].second.first = u;
            vetor[i].second.second = v;
        }
        qsort(vetor, m, sizeof(Aresta), Compara);
        for (int i = 0; i < m; i++)
            if (find(vetor[i].second.first) != find(vetor[i].second.second)) {
                printf("%d %d\n", vetor[i].second.first,
                       vetor[i].second.second);
                join(vetor[i].second.first, vetor[i].second.second);
            }
        printf("\n");
    }
    return 0;
}
