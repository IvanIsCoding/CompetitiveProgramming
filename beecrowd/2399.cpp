// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2399
#include <cstdio>
int vetor[1010];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x) {
            vetor[i - 1]++;
            vetor[i]++;
            vetor[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d\n", vetor[i]);
    return 0;
}
