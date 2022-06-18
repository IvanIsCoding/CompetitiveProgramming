// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2349
#include <cstdio>
int vetor[101];
int main() {
    int n, c, s;
    scanf("%d %d %d", &n, &c, &s);
    int ini = 1;
    vetor[ini]++;
    while (c--) {
        int comando;
        scanf("%d", &comando);
        if (comando == 1) {
            ini++;
            if (ini == n + 1) ini = 1;
        } else {
            ini--;
            if (ini == 0) ini = n;
        }
        vetor[ini]++;
    }
    printf("%d\n", vetor[s]);
    return 0;
}
