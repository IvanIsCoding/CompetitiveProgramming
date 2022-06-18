// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2371
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#define MAXN 10010
#define MAXL 110
using namespace std;
vector<int> lista[MAXN];
map<pair<int, int>, int> mapa;
map<pair<int, int>, int>::iterator it;
map<int, int> navios;
map<int, int>::iterator jt;
int componente[MAXN], k, n, m, resposta, contador;
char entrada[MAXN];
void dfs(int z) {
    for (int i = 0; i < lista[z].size(); i++) {
        int v = lista[z][i];
        if (componente[v] == -1) {
            componente[v] = componente[z];
            dfs(v);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", entrada);
        for (int j = 0; j < m; j++) {
            if (entrada[j] == '#') {
                contador++;
                componente[contador] = -1;
                mapa[make_pair(i, j + 1)] = contador;
            }
        }
    }
    for (it = mapa.begin(); it != mapa.end(); it++) {
        int x = (*it).first.first, y = (*it).first.second, id = (*it).second;
        pair<int, int> a1 = make_pair(x + 1, y), a2 = make_pair(x - 1, y),
                       b1 = make_pair(x, y + 1), b2 = make_pair(x, y - 1);
        if (mapa.find(a1) != mapa.end()) lista[id].push_back(mapa[a1]);
        if (mapa.find(a2) != mapa.end()) lista[id].push_back(mapa[a2]);
        if (mapa.find(b1) != mapa.end()) lista[id].push_back(mapa[b1]);
        if (mapa.find(b2) != mapa.end()) lista[id].push_back(mapa[b2]);
    }
    for (int i = 1; i <= contador; i++) {
        if (componente[i] == -1) {
            resposta++;
            componente[i] = resposta;
            dfs(i);
        }
    }
    for (int i = 1; i <= contador; i++) {
        if (navios.find(componente[i]) != navios.end())
            navios[componente[i]]++;
        else
            navios[componente[i]] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> par = make_pair(a, b);
        if (mapa.find(par) != mapa.end()) navios[componente[mapa[par]]]--;
    }
    for (jt = navios.begin(); jt != navios.end(); jt++) {
        if ((*jt).second != 0) resposta--;
    }
    printf("%d\n", resposta);
    return 0;
}
