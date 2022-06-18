// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2376
#include <cstdio>
int main() {
    int a, b, davez = 0;
    char oitavas[16], quartas[8], semis[4], final[2], aux = 'A';
    for (int i = 0; i < 16; i++) {
        oitavas[i] = aux;
        aux++;
    }
    for (int i = 0; i < 8; i++) {
        scanf("%d %d", &a, &b);
        if (a > b)
            quartas[i] = oitavas[davez];
        else
            quartas[i] = oitavas[davez + 1];
        davez += 2;
    }
    davez = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &a, &b);
        if (a > b)
            semis[i] = quartas[davez];
        else
            semis[i] = quartas[davez + 1];
        davez += 2;
    }
    davez = 0;
    for (int i = 0; i < 2; i++) {
        scanf("%d %d", &a, &b);
        if (a > b)
            final[i] = semis[davez];
        else
            final[i] = semis[davez + 1];
        davez += 2;
    }
    scanf("%d %d", &a, &b);
    if (a > b)
        printf("%c\n", final[0]);
    else
        printf("%c\n", final[1]);
    return 0;
}
