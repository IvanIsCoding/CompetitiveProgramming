// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2433
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 100010
#define LIM 2147483647
int vetor[MAX], n, k, i, resposta = LIM;
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);
    sort(vetor, vetor + n);
    for (int i = 0; i <= k; i++)
        if (vetor[i + (n - k) - 1] - vetor[i] < resposta)
            resposta = vetor[i + (n - k) - 1] - vetor[i];
    printf("%d\n", resposta);
    return 0;
}
