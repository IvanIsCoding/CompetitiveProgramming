// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2248
#include <algorithm>
#include <iostream>
#include <queue>
#define endl '\n'
#define MAXN 10100
using namespace std;
typedef pair<int, int> ii;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, turma = 1;
    while (cin >> n && n) {
        queue<ii> fila;
        fila.push(make_pair(-1, -1));
        while (n--) {
            int i, j;
            cin >> i >> j;
            if (j > fila.front().second) {
                queue<ii> vazia;
                vazia.push(make_pair(i, j));
                swap(vazia, fila);
            } else if (j == fila.front().second)
                fila.push(make_pair(i, j));
        }
        cout << "Turma " << turma++ << endl;
        while (!fila.empty()) {
            cout << fila.front().first << ' ';
            fila.pop();
        }
        cout << endl << endl;
    }
    return 0;
}
