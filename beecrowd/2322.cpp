// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2322
#include <cstdio>
#define MAXN 1001
int vetor[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        vetor[x] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!vetor[i]) {
            printf("%d\n", i);
            break;
        }
    return 0;
}
