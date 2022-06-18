// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2124
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define MAXN 2001
using namespace std;
unordered_map<string, int> conversao;
vector<int> grafo[MAXN], transposto[MAXN];
stack<int> pilha;
int processado1[MAXN], processado2[MAXN], componente[MAXN], ID, vertices, n,
    instancia, possivel;
inline int neg(int x) {
    if (x & 1) return x + 1;
    return x - 1;
}
inline void add(string s) {
    string a, b;
    b.push_back('!');
    if (s[0] == '!') {
        for (int i = 1; i < s.size(); i++) {
            a.push_back(s[i]);
            b.push_back(s[i]);
        }
    } else {
        for (int i = 0; i < s.size(); i++) {
            a.push_back(s[i]);
            b.push_back(s[i]);
        }
    }
    conversao[a] = ++vertices;
    conversao[b] = ++vertices;
}
void dfs1(int x) {
    processado1[x] = 1;
    for (int i = 0; i < grafo[x].size(); i++) {
        int v = grafo[x][i];
        if (!processado1[v]) {
            dfs1(v);
        }
    }
    pilha.push(x);
}
void dfs2(int x) {
    processado2[x] = 1;
    componente[x] = ID;
    for (int i = 0; i < transposto[x].size(); i++) {
        int v = transposto[x][i];
        if (!processado2[v]) {
            dfs2(v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= vertices; i++) {
            processado1[i] = 0;
            processado2[i] = 0;
            grafo[i].clear();
            transposto[i].clear();
            componente[i] = 0;
        }
        possivel = 1;
        ID = 0;
        vertices = 0;
        conversao.clear();
        while (!pilha.empty()) pilha.pop();
        while (n--) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!conversao.count(s1)) add(s1);
            if (!conversao.count(s2)) add(s2);
            int u = conversao[s1];
            int v = conversao[s2];
            grafo[neg(u)].push_back(v);
            transposto[v].push_back(neg(u));
            grafo[neg(v)].push_back(u);
            transposto[u].push_back(neg(v));
        }
        for (int i = 1; i <= vertices; i++) {
            if (!processado1[i]) dfs1(i);
        }
        while (!pilha.empty()) {
            int i = pilha.top();
            pilha.pop();
            if (!processado2[i]) {
                ID++;
                dfs2(i);
            }
        }
        for (int i = 1; i <= vertices; i++) {
            if (componente[i] == componente[neg(i)]) {
                possivel = 0;
                break;
            }
        }
        printf("Instancia %d\n", ++instancia);
        if (possivel)
            printf("sim\n\n");
        else
            printf("nao\n\n");
    }
    return 0;
}
