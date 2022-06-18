// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2174
#include <iostream>
#include <set>
#include <string>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<string> pokemons;
    int n;
    cin >> n;
    while (n--) {
        string davez;
        cin >> davez;
        pokemons.insert(davez);
    }
    cout << "Falta(m) " << 151 - pokemons.size() << " pomekon(s)." << endl;
    return 0;
}
