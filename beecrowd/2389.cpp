// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2389
#include <cstdio>
int resposta, k;
int main() {
    scanf("%d", &k);
    for (int i = 2; 2 * i * i - 2 * i + 1 <= k; i++) {
        if ((k + i - 1) % (2 * i - 1) == 0) resposta++;
    }
    printf("%d\n", resposta);
    return 0;
}
