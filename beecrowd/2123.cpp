// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2123
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 101
using namespace std;
vector<int> grafo[MAXN], vis, capacidade;
vector<vector<int> > match;
int n, m, k, instancia;
int augmenting_path(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int i = 0; i < grafo[l].size(); i++) {
        int r = grafo[l][i];
        if (match[r].size() < capacidade[r]) {
            match[r].push_back(l);
            return 1;
        }
        for (int j = 0; j < match[r].size(); j++) {
            int p = match[r][j];
            if (augmenting_path(p)) {
                match[r][j] = l;
                return 1;
            }
        }
    }
    return 0;
}
bool comp(int A, int B) { return capacidade[A] > capacidade[B]; }
int main() {
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        printf("Instancia %d\n", ++instancia);
        capacidade.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &capacidade[i]);
        }
        for (int i = 1; i <= m; i++) {
            grafo[i].clear();
        }
        while (k--) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[v].push_back(u);
        }
        for (int i = 1; i <= m; i++) {
            sort(grafo[i].begin(), grafo[i].end(), comp);
        }
        int resp = 0;
        vector<int> vazio;
        match.assign(n + 1, vazio);
        for (int i = 1; i <= m; i++) {
            vis.assign(m + 1, 0);
            resp += augmenting_path(i);
        }
        printf("%d\n\n", resp);
    }
    return 0;
}
