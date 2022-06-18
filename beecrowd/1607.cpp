// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1607
#include <cstdio>
#include <cstring>
int main() {
    int a, i, j;
    scanf("%d", &a);
    for (i = 0; i < a; i++) {
        char palavra1[10100], palavra2[10100];
        scanf("%s %s", palavra1, palavra2);
        int tamanho = strlen(palavra1), resp = 0;
        for (j = 0; j < tamanho; j++) {
            int davez1 = palavra1[j], davez2 = palavra2[j];
            if (davez1 != davez2) {
                if (davez1 > davez2) {
                    resp += (26 + davez2 - davez1);
                } else {
                    resp += davez2 - davez1;
                }
            }
        }
        printf("%d\n", resp);
    }
    return 0;
}
