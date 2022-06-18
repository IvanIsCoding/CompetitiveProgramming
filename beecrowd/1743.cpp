// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1743
#include <cstdio>
int vetor1[10], vetor2[10];
int main() {
    for (int i = 0; i < 5; i++) scanf("%d", &vetor1[i]);
    for (int i = 0; i < 5; i++) scanf("%d", &vetor2[i]);
    for (int i = 0; i < 5; i++)
        if (vetor1[i] == vetor2[i]) {
            printf("N\n");
            return 0;
        }
    printf("Y\n");
    return 0;
}
