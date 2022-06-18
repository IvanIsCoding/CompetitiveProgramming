// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2167
#include <cstdio>
int main() {
    int primeiro[10000];
    int casos;
    scanf("%d", &casos);
    for (int i = 1; i <= casos; i++) scanf("%d", &primeiro[i]);
    for (int i = 2; i <= casos; i++) {
        if (primeiro[i] < primeiro[i - 1]) {
            printf("%i\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
