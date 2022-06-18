// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2230
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 10010
#define MP make_pair
#define LIMIT 99999
using namespace std;
typedef pair<int, int> ii;
vector<int> grafo[MAXN];
int visitado[MAXN], distancias[MAXN];
int main() {
    int vertices, arestas, cidade, preco, teste = 1;
    while (scanf("%d %d %d %d", &vertices, &arestas, &cidade, &preco) &&
           (vertices || cidade || arestas || preco)) {
        printf("Teste %d\n", teste++);
        for (int i = 1; i <= vertices; i++) {
            grafo[i].clear();
            visitado[i] = 0;
            distancias[i] = LIMIT;
        }
        for (int i = 0; i < arestas; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }
        queue<ii> bfs;
        bfs.push(MP(cidade, 0));
        while (!bfs.empty()) {
            ii davez = bfs.front();
            bfs.pop();
            int u = davez.first, d = davez.second;
            if (visitado[u]) continue;
            distancias[u] = d;
            visitado[u] = 1;
            for (int i = 0; i < int(grafo[u].size()); i++)
                bfs.push(MP(grafo[u][i], d + 1));
        }
        distancias[cidade] = LIMIT;
        for (int i = 1; i <= vertices; i++)
            if (distancias[i] <= preco) printf("%d ", i);
        printf("\n\n");
    }
    return 0;
}
