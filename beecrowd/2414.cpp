// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2414
#include <cstdio>
int main() {
    int resp = 0;
    while (1) {
        int davez;
        scanf("%d", &davez);
        if (davez == 0) {
            break;
        } else if (davez > resp) {
            resp = davez;
        }
    }
    printf("%d\n", resp);
    return 0;
}
