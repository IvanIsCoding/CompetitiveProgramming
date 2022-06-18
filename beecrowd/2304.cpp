// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2304
#include <iostream>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int dalila, eloi, felix, eventos;
    cin >> dalila >> eventos;
    eloi = felix = dalila;
    while (eventos--) {
        char op;
        int valor;
        cin >> op;
        if (op == 'C') {
            char jogador;
            cin >> jogador >> valor;
            if (jogador == 'D') dalila -= valor;
            if (jogador == 'E') eloi -= valor;
            if (jogador == 'F') felix -= valor;
        }
        if (op == 'V') {
            char jogador;
            cin >> jogador >> valor;
            if (jogador == 'D') dalila += valor;
            if (jogador == 'E') eloi += valor;
            if (jogador == 'F') felix += valor;
        }
        if (op == 'A') {
            char jogador1, jogador2;
            cin >> jogador1 >> jogador2 >> valor;
            if (jogador1 == 'D') dalila += valor;
            if (jogador1 == 'E') eloi += valor;
            if (jogador1 == 'F') felix += valor;
            if (jogador2 == 'D') dalila -= valor;
            if (jogador2 == 'E') eloi -= valor;
            if (jogador2 == 'F') felix -= valor;
        }
    }
    cout << dalila << " " << eloi << " " << felix << endl;
    return 0;
}
