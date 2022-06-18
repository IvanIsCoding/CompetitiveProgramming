// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2286
#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i, j, teste = 1;
    while (cin >> n && n) {
        string nome1, nome2;
        cout << "Teste " << teste++ << endl;
        cin >> nome1 >> nome2;
        while (n--) {
            cin >> i >> j;
            if ((i + j) % 2)
                cout << nome2 << endl;
            else
                cout << nome1 << endl;
        }
        cout << endl;
    }
    return 0;
}
