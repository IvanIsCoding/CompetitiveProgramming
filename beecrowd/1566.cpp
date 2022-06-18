// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1566
#include <cstdio>
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
int main() {
    int vetor[240], casos, davez, i, j, subdavez;
    getint(casos);
    for (i = 0; i < casos; i++) {
        for (j = 0; j <= 230; j++) {
            vetor[j] = 0;
        }
        getint(davez);
        for (j = 0; j < davez; j++) {
            getint(subdavez);
            vetor[subdavez] += 1;
        }
        int maximo = 19, minimo = 230;
        for (j = 19; j <= 230; j++) {
            if (vetor[j]) maximo = j;
        }
        for (j = 230; j >= 19; j--) {
            if (vetor[j]) minimo = j;
        }
        printf("%d", minimo);
        vetor[minimo]--;
        for (j = minimo; j <= maximo; j++) {
            int total = vetor[j];
            while (total--) printf(" %d", j);
        }
        printf("\n");
    }
    return 0;
}
