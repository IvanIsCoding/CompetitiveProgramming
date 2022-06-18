// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2430
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 3 * 1e5 + 10;
int ponteiro, N, n, tam[MAXN], filhos[MAXN], nivel[MAXN], total, resp;
set<int> grafo[MAXN];
map<string, int> conversao;
void dfs1(int x) {
    filhos[x] = 0;
    for (set<int>::iterator it = grafo[x].begin(); it != grafo[x].end(); it++) {
        int v = *it;
        nivel[v] = nivel[x] + 1;
        dfs1(v);
        filhos[x] += filhos[v];
    }
    if (filhos[x] == 0) filhos[x] = 1;
}
void dfs2(int x, int salva, int acumulada) {
    if (grafo[x].size() == 0) return;
    int proximo_acumulada = (N - filhos[x]) * 3 + acumulada;
    int proximo_salva = salva + (tam[x] + (x != 0)) * (filhos[x]);
    if (x != 0) {
        int temporario = total - proximo_salva + proximo_acumulada;
        resp = min(resp, temporario);
    }
    for (set<int>::iterator it = grafo[x].begin(); it != grafo[x].end(); it++) {
        int v = *it;
        dfs2(v, proximo_salva, proximo_acumulada);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    N = n;
    while (n--) {
        string entrada, temp;
        vector<string> vetorzao;
        vector<int> arestas;
        arestas.push_back(0);
        cin >> entrada;
        resp += entrada.size();
        total += entrada.size();
        for (int i = 0; i < entrada.size(); i++) {
            if (entrada[i] == '/') {
                vetorzao.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(entrada[i]);
            }
        }
        vetorzao.push_back(temp);
        for (int i = 0; i < vetorzao.size(); i++) {
            if (!conversao.count(vetorzao[i])) {
                conversao[vetorzao[i]] = ++ponteiro;
                tam[ponteiro] = vetorzao[i].size();
            }
            arestas.push_back(conversao[vetorzao[i]]);
        }
        for (int i = 0; i + 1 < arestas.size(); i++) {
            grafo[arestas[i]].insert(arestas[i + 1]);
        }
    }
    n = ponteiro;
    dfs1(0);
    // for(int i=0;i<=n;i++){
    //	printf("Vertice %d Filhos %d Nivel %d :",i,filhos[i],nivel[i]);
    //	for(set<int>::iterator it = grafo[i].begin();it !=
    // grafo[i].end();it++){ 		printf(" %d",*it);
    //	}
    //	printf("\n");
    // }
    dfs2(0, 0, 0);
    cout << resp << endl;
    return 0;
}
