// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2366
#include <cstdio>
int vetor[10010];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vetor[n] = 42195;
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);
    for (int i = 1; i <= n; i++) {
        if (vetor[i] - vetor[i - 1] > m) {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
