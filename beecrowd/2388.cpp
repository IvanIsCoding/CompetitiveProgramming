// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2388
#include <cstdio>
int main() {
    int n, resposta = 0;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        resposta += x * y;
    }
    printf("%d\n", resposta);
    return 0;
}
