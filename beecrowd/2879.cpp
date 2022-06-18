// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2879
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (x == 1) ans--;
    }

    cout << ans << endl;

    return 0;
}
