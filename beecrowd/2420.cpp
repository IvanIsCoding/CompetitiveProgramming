// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2420
#include <cstdio>
int main() {
    int i, a, resp = 0;
    scanf("%d", &a);
    int vetor[a];
    for (i = 0; i < a; i++) {
        int davez;
        scanf("%d", &davez);
        resp += davez;
        vetor[i] = resp;
    }
    for (i = 0; i < a; i++) {
        if (2 * vetor[i] == resp) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
}
