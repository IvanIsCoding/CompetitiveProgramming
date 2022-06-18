// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2303
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1e3 + 1;
int matriz[MAXN][MAXN], soma[MAXN][MAXN], resp, n, m, p, q;
int main() {
    scanf("%d %d %d %d", &n, &m, &p, &q);
    for (int linha = 1; linha <= n; linha++) {
        for (int coluna = 1; coluna <= m; coluna++) {
            scanf("%d", &matriz[linha][coluna]);
            soma[linha][coluna] =
                soma[linha][coluna - 1] + matriz[linha][coluna];
        }
    }
    for (int linha = 1; linha + p - 1 <= n; linha += p) {
        for (int coluna = 1; coluna + q - 1 <= m; coluna += q) {
            int colunafim = coluna + q - 1;
            int colunaini = coluna - 1;
            int linhalimite = linha + p - 1;
            int temp = 0;
            for (int linhadavez = linha; linhadavez <= linhalimite;
                 linhadavez++) {
                temp +=
                    soma[linhadavez][colunafim] - soma[linhadavez][colunaini];
            }
            // printf("Linha %d Coluna %d Colunafim %d Colunaini %d Linhalimite
            // %d Temp %d Resp
            // %d\n",linha,coluna,colunafim,colunaini,linhalimite,temp,resp);
            resp = max(temp, resp);
        }
    }
    printf("%d\n", resp);
    return 0;
}
