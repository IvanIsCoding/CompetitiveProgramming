// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2434
#include <cstdio>
int min(int x, int y) {
    if (x < y) return x;
    return y;
}
int main() {
    int n, atual, menor;
    scanf("%d %d", &n, &atual);
    menor = atual;
    while (n--) {
        int davez;
        scanf("%d", &davez);
        atual += davez;
        menor = min(atual, menor);
    }
    printf("%d\n", menor);
    return 0;
}
