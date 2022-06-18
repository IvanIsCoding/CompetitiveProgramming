// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2479
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, bem = 0, mal = 0;
    cin >> n;
    vector<string> nomes;
    for (int i = 0; i < n; i++) {
        string davez;
        cin >> davez;
        if (davez[0] == '+')
            bem++;
        else
            mal++;
        cin >> davez;
        nomes.push_back(davez);
    }
    sort(nomes.begin(), nomes.end());
    for (int i = 0; i < n; i++) {
        cout << nomes[i] << endl;
    }
    cout << "Se comportaram: " << bem << " | Nao se comportaram: " << mal
         << endl;
    return 0;
}
