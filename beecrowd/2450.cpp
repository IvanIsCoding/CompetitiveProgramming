// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2450
#include <cstdio>
int main() {
    int ordema, ordemb, i, j;
    int numero[500];
    scanf("%d %d", &ordema, &ordemb);
    for (i = 0; i < ordema; i++) {
        int anterior = 0, total = 0, jaquebrou = 0;
        for (j = 0; j < ordemb; j++) {
            int davez;
            scanf("%d", &davez);
            if (davez == 0 && anterior == 0 && jaquebrou == 0)
                total++;
            else
                jaquebrou = 1;
            anterior = davez;
        }
        numero[i] = total;
    }
    int referencia = numero[0];
    for (i = 1; i < ordema; i++) {
        if (referencia == ordemb) {
            if (numero[i] != ordemb) {
                printf("N\n");
                return 0;
            }
        } else {
            if (numero[i] > referencia)
                referencia = numero[i];
            else {
                printf("N\n");
                return 0;
            }
        }
    }
    printf("S\n");
    return 0;
}
