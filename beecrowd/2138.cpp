// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2138
#include <cstdio>
#include <cstring>
int frequencia[1000];
char entrada[100010];
int main() {
    while (scanf("%s", entrada) != EOF) {
        int tamanho = strlen(entrada), maximo = 0;
        char resposta = '0';
        memset(frequencia, 0, sizeof(frequencia));
        for (int i = 0; i < tamanho; i++) {
            frequencia[entrada[i]]++;
        }
        for (char digito = '0'; digito <= '9'; digito++) {
            if (frequencia[digito] >= maximo) {
                maximo = frequencia[digito];
                resposta = digito;
            }
        }
        printf("%c\n", resposta);
    }
    return 0;
}
