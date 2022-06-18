// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2663
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> entrada;
    int n, k;
    cin >> n >> k;
    while (n--) {
        int x;
        cin >> x;
        entrada.push_back(-x);
    }
    sort(entrada.begin(), entrada.end());
    while (k < entrada.size() && entrada[k - 1] == entrada[k]) {
        k++;
    }
    cout << k << endl;
    return 0;
}
