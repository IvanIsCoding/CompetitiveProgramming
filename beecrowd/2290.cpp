// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2290
#include <iostream>
#include <set>
#define endl '\n'
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    while (cin >> n && n) {
        set<ll> conjunto;
        while (n--) {
            ll davez;
            cin >> davez;
            if (conjunto.count(davez)) {
                conjunto.erase(davez);
            } else {
                conjunto.insert(davez);
            }
        }
        cout << *(conjunto.begin()) << " " << *(conjunto.rbegin()) << endl;
    }
    return 0;
}
