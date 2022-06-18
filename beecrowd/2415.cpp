// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2415
#include <cstdio>
int main() {
    int entrada, resp = 0, temporario = 1, anterior, count = 0;
    scanf("%d", &entrada);
    while (count < entrada) {
        int davez;
        scanf("%d", &davez);
        if (anterior == davez) {
            temporario++;
        } else {
            if (temporario > resp) {
                resp = temporario;
            }
            temporario = 1;
        }
        anterior = davez;
        count++;
    }
    if (temporario > resp) {
        resp = temporario;
    }
    printf("%d\n", resp);
    return 0;
}
