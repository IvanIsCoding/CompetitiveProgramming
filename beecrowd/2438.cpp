// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2438
#include <cstdio>
long long resposta;
int n, vetor[1000001], sequencias[9], soma;
int main() {
    scanf("%d", &n);
    sequencias[0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        soma += x;
        resposta += sequencias[soma % 8];
        sequencias[soma % 8]++;
    }
    printf("%lld\n", resposta);
    return 0;
}
