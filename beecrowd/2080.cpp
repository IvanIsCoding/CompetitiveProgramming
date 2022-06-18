// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2080
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++) {
        if (tc) cout << endl;
        string entrada;
        int k;
        cin >> entrada >> k;
        cout << entrada << endl;
        while (k--) {
            string substituta;
            int idx = 1;
            int contador = 1;
            char ultimo = entrada[0];
            while (idx < entrada.size()) {
                if (entrada[idx] == ultimo) {
                    contador++;
                    idx++;
                } else {
                    string aisim = to_string(contador);
                    for (int i = 0; i < aisim.size(); i++) {
                        substituta.push_back(aisim[i]);
                    }
                    substituta.push_back(ultimo);
                    ultimo = entrada[idx];
                    contador = 0;
                }
            }
            string aisim = to_string(contador);
            for (int i = 0; i < aisim.size(); i++) {
                substituta.push_back(aisim[i]);
            }
            substituta.push_back(ultimo);
            entrada = substituta;
            cout << entrada << endl;
        }
    }
    return 0;
}
