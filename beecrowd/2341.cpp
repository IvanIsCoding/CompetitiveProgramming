// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2341
#include <cstdio>
int vetor[1010];
int min(int x, int y) {
    if (x < y) return x;
    return y;
}
int main() {
    int n, k, resposta = 2147483647;
    scanf("%d %d", &n, &k);
    while (n--) {
        int davez;
        scanf("%d", &davez);
        vetor[davez]++;
    }
    for (int i = 1; i <= k; i++) resposta = min(resposta, vetor[i]);
    printf("%d\n", resposta);
    return 0;
}
