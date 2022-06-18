// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2453
#include <cstdio>
int main() {
    char davez;
    bool ep = false;
    while (scanf("%c", &davez) != EOF) {
        if (davez == ' ') {
            printf(" ");
            continue;
        }
        if (!ep)
            ep = true;
        else {
            ep = false;
            printf("%c", davez);
        }
    }
    printf("\n");
    return 0;
}
