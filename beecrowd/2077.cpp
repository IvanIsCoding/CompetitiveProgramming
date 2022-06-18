// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2077
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define MAXN 202
#define endl '\n'
using namespace std;
vector<int> grafo[MAXN], vis;
vector<vector<int> > match;
map<string, int> mapa;
int n, m, capacidade[MAXN], contador;
int augmenting_path(int l, int maximo) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int i = 0; i < grafo[l].size(); i++) {
        int r = grafo[l][i];
        if (match[r].size() < capacidade[r] * maximo) {
            match[r].push_back(l);
            return 1;
        }
        for (int j = 0; j < match[r].size(); j++) {
            if (augmenting_path(match[r][j], maximo)) {
                match[r][j] = l;
                return 1;
            }
        }
    }
    return 0;
}
int func(int maximo) {
    vector<int> temp;
    match.assign(n + m + 2, temp);
    int resp = 0;
    for (int i = 1; i <= n; i++) {
        vis.assign(n + m + 2, 0);
        if (!augmenting_path(i, maximo)) {
            return 0;
        }
    }
    return 1;
}
int busca() {
    int ini = 1, fim = n, meio, resp = -1;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (func(meio)) {
            resp = meio;
            fim = meio - 1;
        } else
            ini = meio + 1;
    }
    return resp;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> m;
        mapa.clear();
        contador = 0;
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            string davez;
            cin >> davez;
            if (!mapa.count(davez)) {
                contador++;
                mapa[davez] = contador + n;
                capacidade[contador + n] = 1;
            } else {
                capacidade[mapa[davez]]++;
            }
        }
        m = contador;
        for (int i = 1; i <= n; i++) {
            int vertices;
            cin >> vertices;
            for (int j = 1; j <= vertices; j++) {
                string horario;
                cin >> horario;
                if (mapa.count(horario)) {
                    grafo[i].push_back(mapa[horario]);
                }
            }
        }
        cout << busca() << endl;
    }
    return 0;
}
