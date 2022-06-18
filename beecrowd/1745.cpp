// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1745
#include <cstdio>
typedef long long ll;
ll total[4], resp, soma;
inline void reseta() {
    soma = 0;
    total[0] = 1;
    total[1] = 0;
    total[2] = 0;
}
int main() {
    char c;
    reseta();
    while (scanf("%c", &c) != EOF) {
        if (!(c >= '0' && c <= '9')) {
            reseta();
            continue;
        }
        soma += c - '0';
        soma %= 3;
        resp += total[soma];
        total[soma]++;
    }
    printf("%lld\n", resp);
    return 0;
}
