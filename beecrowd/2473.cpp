// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2473
#include <cstdio>
int sorteado[8], seus[8], resp;
int main() {
    for (int i = 0; i < 6; i++) {
        scanf("%d", &sorteado[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &seus[i]);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            resp += int(sorteado[i] == seus[j]);
        }
    }
    if (resp < 3)
        printf("azar\n");
    else if (resp == 3)
        printf("terno\n");
    else if (resp == 4)
        printf("quadra\n");
    else if (resp == 5)
        printf("quina\n");
    else
        printf("sena\n");
    return 0;
}
