// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2460
#include <cstdio>
#include <set>
#define MAX 50010
using namespace std;
int vetor[MAX], n, m, i, davez;
set<int> removidos;
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &vetor[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &davez);
        removidos.insert(davez);
    }
    int exibicao = 0;
    for (i = 0; i < n; i++) {
        if (removidos.count(vetor[i]) == 1) continue;
        if (exibicao)
            printf(" ");
        else
            exibicao = 1;
        printf("%d", vetor[i]);
    }
    printf("\n");
    return 0;
}
