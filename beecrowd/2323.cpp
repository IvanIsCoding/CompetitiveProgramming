// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2323
#include <cstdio>
#include <set>
#include <vector>
#define PB push_back
#define MAXN 10010
using namespace std;
bool condicional, visitado[MAXN];
vector<int> grafo[MAXN];
int dfs(int u) {
    visitado[u] = true;
    set<int> pesos;
    int resposta = 1;
    for (int i = 0; i < grafo[u].size(); i++) {
        int v = grafo[u][i];
        if (!visitado[v]) {
            int variavel = dfs(v);
            pesos.insert(variavel);
            resposta += variavel;
        }
    }
    if (pesos.size() > 1) condicional = true;
    return resposta;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        grafo[v].PB(u);
    }
    dfs(0);
    if (condicional)
        printf("mal\n");
    else
        printf("bem\n");
    return 0;
}
