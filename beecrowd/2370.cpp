// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2370
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n, t, davez = 0, i;
    cin >> n >> t;
    vector<vector<string> > times;
    vector<pair<int, string> > jogadores;
    for (i = 0; i < n; i++) {
        int habilidade;
        string nome;
        cin >> nome >> habilidade;
        jogadores.push_back(make_pair(habilidade, nome));
    }
    for (i = 0; i < t; i++) {
        vector<string> aux;
        times.push_back(aux);
    }
    sort(jogadores.begin(), jogadores.end());
    for (i = n - 1; i >= 0; i--) {
        times[davez].push_back(jogadores[i].second);
        davez++;
        davez = davez % t;
    }
    for (i = 0; i < t; i++) {
        sort(times[i].begin(), times[i].end());
    }
    for (int i = 0; i < t; i++) {
        cout << "Time " << i + 1 << endl;
        vector<string>::iterator it;
        for (it = times[i].begin(); it != times[i].end(); it++) {
            cout << *it << endl;
        }
        cout << endl;
    }
    return 0;
}
