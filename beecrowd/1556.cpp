// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1556
#include <iostream>
#include <set>
#include <string>
#define endl '\n'
using namespace std;
string chave;
set<string> conjunto;
int tam;
void brute(int idx, string s) {
    if (idx == tam) return;
    s.push_back(chave[idx]);
    conjunto.insert(s);
    set<char> jafoi;
    for (int nxt = idx + 1; nxt < tam; nxt++) {
        if (!jafoi.count(chave[nxt])) {
            jafoi.insert(chave[nxt]);
            brute(nxt, s);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> chave) {
        conjunto.clear();
        tam = chave.size();
        string vazio;
        set<char> jafoi;
        for (int nxt = 0; nxt < tam; nxt++) {
            if (!jafoi.count(chave[nxt])) {
                jafoi.insert(chave[nxt]);
                brute(nxt, vazio);
            }
        }
        for (auto it = conjunto.begin(); it != conjunto.end(); it++) {
            cout << *it << endl;
        }
        cout << endl;
    }
    return 0;
}
