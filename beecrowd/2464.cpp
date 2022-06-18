// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2464
#include <cstdio>
#include <cstring>
char conv[1000], entrada[10100];
int main() {
    for (char c = 'a'; c <= 'z'; c++) {
        scanf("%c", &conv[c]);
    }
    scanf("%s", entrada);
    for (int i = 0; i < strlen(entrada); i++) {
        printf("%c", conv[entrada[i]]);
    }
    printf("\n");
    return 0;
}
