// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2429
#include <cstdio>
#include <stack>
#include <vector>
#define MAXN 10010
using namespace std;
typedef vector<int> vi;
vi grafo[MAXN], transposto[MAXN];
bool visitado[MAXN];
stack<int> pilha;
void dfs1(int x) {
    visitado[x] = true;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i];
        if (!visitado[v]) dfs1(v);
    }
    pilha.push(x);
}
void dfs2(int x) {
    visitado[x] = false;
    for (int i = 0; i < transposto[x].size(); i++) {
        int v = transposto[x][i];
        if (visitado[v]) dfs2(v);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        grafo[u].push_back(v);
        transposto[v].push_back(u);
    }
    dfs1(1);
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            printf("N\n");
            return 0;
        }
    }
    dfs2(pilha.top());
    for (int i = 1; i <= n; i++) {
        if (visitado[i]) {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
