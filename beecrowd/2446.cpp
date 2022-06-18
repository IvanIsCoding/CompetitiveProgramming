// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2446
#include <cstdio>
int n, alvo, tab[1010][100010], moedas[1010];
char resposta;
bool verdade;
void busca(int obj, int valor) {
    if (verdade) return;
    if (tab[obj][valor] != 0) return;
    tab[obj][valor] = 1;
    if (valor == alvo) {
        verdade = true;
        resposta = 'S';
        return;
    }
    if (obj > n || valor > alvo) return;
    busca(obj + 1, valor + moedas[obj]);
    busca(obj + 1, valor);
}
int main() {
    resposta = 'N';
    scanf("%d %d", &alvo, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &moedas[i]);
    busca(1, 0);
    printf("%c\n", resposta);
    return 0;
}
