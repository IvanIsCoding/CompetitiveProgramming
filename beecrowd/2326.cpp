// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2326
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAXN 31
#define MAXT 101
using namespace std;
vector<int> grafo[MAXN];
int processado[MAXN][MAXT][MAXT], n, t, resp, presente[MAXN], tipo[MAXN];
void dfs(int x, int a, int b) {
    processado[x][a][b] = 1;
    if (a || b) {
        resp = min(resp, abs(a - b));
    }
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i];
        if (!processado[v][a][b]) dfs(v, a, b);
        if (tipo[x] == 0) {
            if (presente[x] + a + b <= t) {
                if (!processado[v][a + presente[x]][b])
                    dfs(v, a + presente[x], b);
            }
        } else {
            if (presente[x] + a + b <= t) {
                if (!processado[v][a][presente[x] + b])
                    dfs(v, a, presente[x] + b);
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    scanf("%d", &t);
    resp = MAXT;
    for (int vez = 0; vez < n; vez++) {
        int cidade, valor;
        char letra;
        int qtd;
        scanf("%d %d %c %d", &cidade, &valor, &letra, &qtd);
        presente[cidade] = valor;
        tipo[cidade] = (letra == 'A');
        while (qtd--) {
            int vaipara;
            scanf("%d", &vaipara);
            grafo[cidade].push_back(vaipara);
        }
        grafo[cidade].push_back(cidade);
    }
    dfs(0, 0, 0);
    printf("%d\n", resp);
    return 0;
}
