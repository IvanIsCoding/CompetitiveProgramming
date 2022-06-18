// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2372
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAX 110
#define LIMIT 999999999
using namespace std;
int matriz[MAX][MAX], distancia[MAX][MAX], n, m;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) matriz[i][j] = LIMIT;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        matriz[x][y] = min(matriz[x][y], z);
        matriz[y][x] = min(matriz[y][x], z);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) distancia[i][j] = matriz[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                distancia[i][j] =
                    min(distancia[i][j], distancia[i][k] + distancia[k][j]);
    vector<int> resposta;
    for (int i = 0; i < n; i++) {
        int inicial = distancia[i][0];
        for (int j = 0; j < n; j++) {
            inicial = max(distancia[i][j], inicial);
        }
        resposta.push_back(inicial);
    }
    sort(resposta.begin(), resposta.end());
    printf("%d\n", resposta[0]);
    return 0;
}
