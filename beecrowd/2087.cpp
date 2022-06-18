// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2087
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    while (true) {
        cin >> n;
        if (n == 0) break;
        bool flag = false;
        unordered_set<string> noobei, palavras;
        for (int i = 0; i < n; i++) {
            string davez;
            cin >> davez;
            if (flag) continue;
            if (noobei.count(davez)) {
                flag = true;
                break;
            }
            noobei.insert(davez);
            palavras.insert(davez);
            while (!davez.empty() && !flag) {
                davez.pop_back();
                flag |= palavras.count(davez);
                noobei.insert(davez);
            }
        }
        if (flag)
            cout << "Conjunto Ruim" << endl;
        else
            cout << "Conjunto Bom" << endl;
    }
    return 0;
}
