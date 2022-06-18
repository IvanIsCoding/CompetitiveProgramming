// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2249
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#define MAXN 110
#define MP make_pair
#define endl '\n'
using namespace std;
typedef pair<string, string> pss;
typedef set<int> si;
typedef pair<int, int> ii;
int nivel[MAXN];
si grafo[MAXN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int artigos, teste = 1;
    while (cin >> artigos && artigos) {
        map<pss, int> mapa;
        int contador = 0;
        string inicialerdos = "P.", nomeerdos = "Erdos";
        mapa[MP(nomeerdos, inicialerdos)] = 0;
        grafo[0].clear();
        while (artigos--) {
            string inicial, nome;
            si autores;
            bool condicional = false;
            while (!condicional) {
                cin >> inicial >> nome;
                string::iterator it = --nome.end();
                condicional = *(it) == '.';
                nome.erase(it);
                pss nomecompleto = MP(nome, inicial);
                if (mapa.find(nomecompleto) == mapa.end()) {
                    mapa[nomecompleto] = ++contador;
                    nivel[contador] = -1;
                    grafo[contador].clear();
                }
                autores.insert(mapa[nomecompleto]);
            }
            for (si::iterator i = autores.begin(); i != autores.end(); i++)
                for (si::iterator j = autores.begin(); j != autores.end();
                     j++) {
                    grafo[*i].insert(*j);
                    grafo[*j].insert(*i);
                }
        }
        for (int i = 0; i <= contador; i++) grafo[i].erase(i);
        priority_queue<ii, vector<ii>, greater<ii> > fila;
        nivel[0] = -1;
        fila.push(MP(0, 0));
        while (!fila.empty()) {
            ii davez = fila.top();
            fila.pop();
            int distancia = davez.first, vertice = davez.second;
            if (nivel[vertice] != -1) continue;
            nivel[vertice] = distancia;
            for (si::iterator i = grafo[vertice].begin();
                 i != grafo[vertice].end(); i++)
                if (nivel[*i] == -1) fila.push(MP(distancia + 1, *i));
        }
        mapa.erase(MP(nomeerdos, inicialerdos));
        cout << "Teste " << teste++ << endl;
        for (map<pss, int>::iterator percorrer = mapa.begin();
             percorrer != mapa.end(); percorrer++) {
            cout << (*(percorrer)).first.second << " "
                 << (*(percorrer)).first.first << ": ";
            if (nivel[(*(percorrer)).second] == -1)
                cout << "infinito" << endl;
            else
                cout << nivel[(*(percorrer)).second] << endl;
        }
        cout << endl;
    }
    return 0;
}
