// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2180
#include <cstdio>
#define MAXN 61000
#define DISTANCIA 60000000
bool crivo[MAXN];
int main() {
    int n, resposta = 0, contador = 0;
    for (int i = 2; i < MAXN; i++) {
        if (crivo[i]) continue;
        for (int j = 2 * i; j < MAXN; j += i) crivo[j] = true;
    }
    scanf("%d", &n);
    if (n % 2 == 0) n++;
    for (int i = n; contador < 10; i += 2) {
        if (!crivo[i]) {
            resposta += i;
            contador++;
        }
    }
    printf("%d km/h\n", resposta);
    printf("%d h / %d d\n", DISTANCIA / resposta, DISTANCIA / (resposta * 24));
    return 0;
}
