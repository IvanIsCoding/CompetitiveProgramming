// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2189
#include <cstdio>
int main() {
    int i, n, vez = 1;
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        else {
            printf("Teste %d\n", vez);
            int resp = 0;
            for (i = 0; i < n; i++) {
                int davez;
                scanf("%d", &davez);
                if (resp == 0 && i + 1 == davez) resp = davez;
            }
            printf("%d\n\n", resp);
        }
        vez++;
    }
    return 0;
}
