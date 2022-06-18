// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2373
#include <cstdio>
int main() {
    int resp = 0, casos, i;
    scanf("%d", &casos);
    for (i = 0; i < casos; i++) {
        int l, c;
        scanf("%d %d", &l, &c);
        if (l > c) resp += c;
    }
    printf("%d\n", resp);
    return 0;
}
