// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2462
#include <cstdio>
#define MODULO 1440
int main() {
    int a, b, c, d, e, f, g, h;
    int p1, c1, p2, c2;
    scanf("%d %*c %d %d %*c %d %d %*c %d %d %*c %d", &a, &b, &c, &d, &e, &f, &g,
          &h);
    p1 = 60 * a + b;
    c1 = 60 * c + d;
    p2 = 60 * e + f;
    c2 = 60 * g + h;
    // printf("%d %d %d %d\n",p1,c1,p2,c2);
    for (int duracao = 0; duracao <= 720; duracao++) {
        for (int delta = 12; delta >= -12; delta--) {
            int p1t = (p1 + 60 * delta + duracao + MODULO) % MODULO;
            int p2t = (p2 - 60 * delta + duracao + MODULO) % MODULO;
            // printf("Duracao %d Delta %d\n",duracao,delta);
            // printf("%d %d %d %d\n",p1t,c1,p2t,c2);
            if (p1t != c1) continue;
            if (p2t != c2) continue;
            printf("%d %d\n", duracao, delta);
            return 0;
        }
    }
    return 0;
}
