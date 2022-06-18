// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1706
#include <cstdio>
#define MAXN 1001
int grafo[MAXN][MAXN], grau[MAXN], cor[MAXN], qtd1[MAXN], qtd2[MAXN],
    componente, processado[MAXN], n, m;
void dfs(int x) {
    processado[x] = 1;
    qtd1[componente]++;
    qtd2[componente] += cor[x];
    for (int i = 0; i < grau[x]; i++) {
        int u = grafo[x][i];
        if (!processado[u]) {
            dfs(u);
        }
    }
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        componente = 0;
        for (int i = 1; i <= n; i++) {
            processado[i] = 0;
            qtd1[i] = 0;
            qtd2[i] = 0;
            grau[i] = 0;
            char davez;
            scanf(" %c", &davez);
            cor[i] = davez != 'A';
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u][grau[u]++] = v;
            grafo[v][grau[v]++] = u;
        }
        for (int i = 1; i <= n; i++) {
            if (!processado[i]) {
                componente++;
                dfs(i);
            }
        }
        bool flag1 = false;
        for (int i = 1; i <= componente; i++) {
            if (qtd2[i] % 2 == 1) {
                flag1 = true;
                break;
            }
        }
        if (flag1)
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
