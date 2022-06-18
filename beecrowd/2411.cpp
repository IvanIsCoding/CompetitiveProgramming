// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2411
#include <cstdio>
int main() {
    int x = 4, y = 3, resposta = 0;
    bool possivel = true;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        if (!possivel) continue;
        if (m == 1) {
            x += 1;
            y += 2;
        } else if (m == 2) {
            x += 2;
            y += 1;
        } else if (m == 3) {
            x += 2;
            y -= 1;
        } else if (m == 4) {
            x += 1;
            y -= 2;
        } else if (m == 5) {
            x -= 1;
            y -= 2;
        } else if (m == 6) {
            x -= 2;
            y -= 1;
        } else if (m == 7) {
            x -= 2;
            y += 1;
        } else {
            x -= 1;
            y += 2;
        }
        if (x == 1 && y == 3) possivel = false;
        if (x == 2 && y == 3) possivel = false;
        if (x == 2 && y == 5) possivel = false;
        if (x == 5 && y == 4) possivel = false;
        resposta++;
    }
    printf("%d\n", resposta);
    return 0;
}
