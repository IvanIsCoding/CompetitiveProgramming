// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2410
#include <iostream>
#include <set>
using namespace std;
int main() {
    std::cout.sync_with_stdio(false);
    std::cin.sync_with_stdio(false);
    int casos, i, davez;
    set<int> notas;
    cin >> casos;
    for (i = 0; i < casos; i++) {
        cin >> davez;
        notas.insert(davez);
    }
    cout << (int)notas.size() << endl;
    return 0;
}
