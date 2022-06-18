// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2250
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n, teste = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;
        vector<pair<int, string> > competidores;
        vector<int> posicao;
        for (int i = 1; i <= n; i++) {
            string nome;
            cin >> nome;
            vector<int> temporario;
            int resp = 0;
            for (int j = 1; j <= 12; j++) {
                int davez;
                cin >> davez;
                temporario.push_back(davez);
                resp += davez;
            }
            sort(temporario.begin(), temporario.end());
            competidores.push_back(
                make_pair(temporario[0] + temporario[11] - resp, nome));
        }
        sort(competidores.begin(), competidores.end());
        posicao.push_back(1);
        for (int i = 1; i < n; i++) {
            if (competidores[i].first == competidores[i - 1].first)
                posicao.push_back(posicao[i - 1]);
            else
                posicao.push_back(i + 1);
        }
        cout << "Teste " << teste << endl;
        teste++;
        for (int i = 0; i < n; i++) {
            cout << posicao[i] << " " << -competidores[i].first << " "
                 << competidores[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}
