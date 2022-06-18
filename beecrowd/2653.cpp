// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2653
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    set<string> cjt;
    while (cin >> s) {
        cjt.insert(s);
    }
    cout << cjt.size() << endl;
    return 0;
}
