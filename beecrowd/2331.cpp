// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2331
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define MP make_pair
#define PB push_back
#define MAXN 10000
using namespace std;
typedef pair<int, int> ii;
typedef map<string, int>::iterator ssit;
vector<int> grafo[MAXN], lista;
map<string, int> mapa;
bool visitado[MAXN];
int resposta, n, contador, ini, fim;
string inicio, final;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string nome1, nome2;
        cin >> nome1 >> nome2;
        if (mapa.find(nome1) == mapa.end()) {
            mapa[nome1] = ++contador;
        }
        if (mapa.find(nome2) == mapa.end()) {
            mapa[nome2] = ++contador;
        }
        int codigo1 = mapa[nome1], codigo2 = mapa[nome2];
        grafo[codigo1].PB(codigo2);
    }
    for (ssit pcomeco = mapa.begin(); pcomeco != mapa.end(); pcomeco++) {
        lista.PB((*pcomeco).second);
    }
    for (int i = 0; i < (lista.size()) - 1; i++) {
        int h = lista[i], g = lista[i + 1];
        grafo[h].PB(g);
        grafo[g].PB(h);
    }
    cin >> inicio >> final;
    ini = mapa[inicio];
    fim = mapa[final];
    queue<ii> bfs;
    bfs.push(MP(ini, 0));
    while (!bfs.empty()) {
        ii agora = bfs.front();
        bfs.pop();
        int vertice = agora.first, percorrido = agora.second;
        if (vertice == fim) {
            cout << percorrido << endl;
            return 0;
        }
        if (visitado[vertice]) continue;
        visitado[vertice] = true;
        for (int i = 0; i < (int)grafo[vertice].size(); i++)
            bfs.push(MP(grafo[vertice][i], percorrido + 1));
    }
    return 0;
}
