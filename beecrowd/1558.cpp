// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1558
#include <cstdio>
#define MAXN 30000
bool vetor[MAXN];
int main() {
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++) {
            vetor[i * i + j * j] = true;
        }
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n < 0) {
            printf("NO\n");
            continue;
        }
        if (vetor[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
