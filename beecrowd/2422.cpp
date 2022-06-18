// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2422
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> casa;
    int n, i, valor;
    cin >> n;
    for (i = 0; i < n; i++) {
        int davez;
        cin >> davez;
        casa.insert(davez);
    }
    cin >> valor;
    set<int>::iterator it;
    for (it = casa.begin(); it != casa.end(); it++) {
        if (casa.count(valor - *it)) {
            cout << *it << " " << valor - *it << endl;
            return 0;
        }
    }
    return 0;
}
