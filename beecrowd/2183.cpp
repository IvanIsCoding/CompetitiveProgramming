// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2183
#include <algorithm>
#include <iostream>
#include <queue>
#define MAXN 111
#define endl '\n'
#define MAXL 40
#define MAXK 20
#define MP make_pair
#define LIMIT 1000000000
using namespace std;
typedef pair<int, int> i2;
typedef pair<int, i2> i3;
typedef pair<int, i3> i4;
typedef pair<int, i4> i5;
int n, visitado[MAXN][MAXN][MAXL][MAXK], conversao[MAXN][MAXN], poderes,
    resposta, possivel;
char matriz[MAXN][MAXN];
int utilidade(char variavel) {
    if (variavel == '0' || variavel == 'I' || variavel == 'F' ||
        variavel == 'P' || variavel == 'O' || variavel == 'W' ||
        variavel == 'E' || variavel == 'R' || variavel == '#') {
        return 0;
    }
    if (variavel == '1') return 1;
    if (variavel == '2') return 2;
    if (variavel == '3') return 3;
    if (variavel == '4') return 4;
    if (variavel == '5') return 5;
    if (variavel == '6') return 6;
    if (variavel == '7') return 7;
    if (variavel == '8') return 8;
    if (variavel == '9') return 9;
    return 0;
}
int main() {
    resposta = LIMIT;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> poderes;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char davez;
            cin >> matriz[i][j];
            conversao[i][j] = utilidade(matriz[i][j]);
        }
    }
    priority_queue<i5, vector<i5>, greater<i5> > bfs;
    bfs.push(MP(0, MP(0, MP(0, MP(1, 1)))));
    while (!bfs.empty()) {
        i5 davez = bfs.top();
        bfs.pop();
        int percorrido = davez.first, mochila = davez.second.first,
            disponivies = davez.second.second.first,
            cordx = davez.second.second.second.first,
            cordy = davez.second.second.second.second;
        if (visitado[cordx][cordy][mochila][disponivies]) continue;
        visitado[cordx][cordy][mochila][disponivies] = 1;
        if (matriz[cordx][cordy] == '#') continue;
        int novamochila = mochila;
        if (cordx == n && cordy == n) {
            cout << percorrido + 1 << endl;
            return 0;
        }
        if (matriz[cordx][cordy] == 'P') {
            novamochila |= (1 << 0);
        }
        if (matriz[cordx][cordy] == 'O') {
            novamochila |= (1 << 1);
        }
        if (matriz[cordx][cordy] == 'W') {
            novamochila |= (1 << 2);
        }
        if (matriz[cordx][cordy] == 'E') {
            novamochila |= (1 << 3);
        }
        if (matriz[cordx][cordy] == 'R') {
            novamochila |= (1 << 4);
        }
        if (novamochila == 31) {
            if (cordx + 1 <= n)
                bfs.push(
                    MP(percorrido, MP(0, MP(poderes, MP(cordx + 1, cordy)))));
            if (cordy + 1 <= n)
                bfs.push(
                    MP(percorrido, MP(0, MP(poderes, MP(cordx, cordy + 1)))));
            continue;
        }
        if (disponivies > 0) {
            if (cordx + 1 <= n)
                bfs.push(MP(percorrido,
                            MP(novamochila,
                               MP(disponivies - 1, MP(cordx + 1, cordy)))));
            if (cordy + 1 <= n)
                bfs.push(MP(percorrido,
                            MP(novamochila,
                               MP(disponivies - 1, MP(cordx, cordy + 1)))));
            continue;
        }
        if (conversao[cordx][cordy] == 0) {
            if (cordx + 1 <= n)
                bfs.push(MP(percorrido,
                            MP(novamochila, MP(0, MP(cordx + 1, cordy)))));
            if (cordy + 1 <= n)
                bfs.push(MP(percorrido,
                            MP(novamochila, MP(0, MP(cordx, cordy + 1)))));
            continue;
        } else {
            if (cordx + 1 <= n)
                bfs.push(MP(conversao[cordx][cordy] + percorrido,
                            MP(novamochila, MP(0, MP(cordx + 1, cordy)))));
            if (cordy + 1 <= n)
                bfs.push(MP(conversao[cordx][cordy] + percorrido,
                            MP(novamochila, MP(0, MP(cordx, cordy + 1)))));
            continue;
        }
    }
    cout << -1 << endl;
    return 0;
}
