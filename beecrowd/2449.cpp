// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2449
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int n, tamanho, vetor[1010], resposta = 0;
    scanf("%d %d", &n, &tamanho);
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);
    for (int i = 0; i < n; i++) {
        int diferenca = tamanho - vetor[i];
        resposta += abs(diferenca);
        vetor[i + 1] += diferenca;
    }
    printf("%d\n", resposta);
    return 0;
}
