// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2381
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    int a, b, i;
    cin >> a >> b;
    vector<string> nomes(a);
    for (i = 0; i < a; i++) {
        cin >> nomes[i];
    }
    sort(nomes.begin(), nomes.end());
    cout << nomes[b - 1] << endl;
    return 0;
}
