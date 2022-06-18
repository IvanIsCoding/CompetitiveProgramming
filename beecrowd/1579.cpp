// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1579
#include <cstdio>
int paineis[101], caminhoes, frete, totalpaineis;
int checa(int peso) {
    int atual = peso, restam = caminhoes - 1;
    for (int i = 1; i <= totalpaineis; i++) {
        if (atual >= paineis[i]) {
            atual -= paineis[i];
            continue;
        }
        if (restam == 0) return 0;
        restam--;
        if (paineis[i] > peso) return 0;
        atual = peso - paineis[i];
    }
    return 1;
}
int busca() {
    int ini = 1, fim = 100000, meio, resp;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (checa(meio)) {
            fim = meio - 1;
            resp = meio;
        } else
            ini = meio + 1;
    }
    return resp;
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d %d", &totalpaineis, &caminhoes, &frete);
        for (int i = 1; i <= totalpaineis; i++) {
            scanf("%d", &paineis[i]);
        }
        int val = busca();
        printf("%d $%d\n", val, frete * val * caminhoes);
    }
    return 0;
}
