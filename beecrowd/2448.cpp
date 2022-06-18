// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2448
#include <cstdio>
#include <map>
using namespace std;
int abs(int x) {
    if (x > 0) return x;
    return -x;
}
int main() {
    int i, n, m, davez, resposta = 0, atual = 1;
    map<int, int> mapa;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &davez);
        mapa[davez] = i;
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &davez);
        resposta += abs(mapa[davez] - atual);
        atual = mapa[davez];
    }
    printf("%d\n", resposta);
    return 0;
}
