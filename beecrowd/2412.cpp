// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2412
#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 1010
int componente[MAXN], distancias1[MAXN], distancias2[MAXN], n, d;
vector<int> lista[MAXN];
void dfs(int x) {
    for (int i = 0; i < lista[x].size(); i++) {
        int v = lista[x][i];
        if (componente[v] == -1) {
            componente[v] = 1;
            dfs(v);
        }
    }
}
int main() {
    scanf("%d %d", &n, &d);
    d = d * d;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        distancias1[i] = a;
        distancias2[i] = b;
        componente[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int temp1 = distancias1[i] - distancias1[j],
                temp2 = distancias2[i] - distancias2[j];
            if (temp1 * temp1 + temp2 * temp2 <= d) {
                lista[i].push_back(j);
                lista[j].push_back(i);
            }
        }
    }
    componente[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (componente[i] == -1) {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}
