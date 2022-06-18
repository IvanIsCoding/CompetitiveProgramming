// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2384
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 100;
typedef long long ll;
const ll MODULO = 1e9 + 7;
string ALFABETO, cadeia;
ll dp[MAXN], N, M;
bool valido(ll ini, ll fim) {
    if (cadeia[ini] == '0') return false;
    if (fim - ini + 1 < N) return true;
    for (ll i = ini; i <= fim; i++) {
        if (ALFABETO[i - ini] > cadeia[i]) return true;
        if (ALFABETO[i - ini] < cadeia[i]) return false;
    }
    return true;
}
ll solve(ll pos) {
    if (dp[pos] != -1) return dp[pos];
    ll val = 0;
    for (ll quebra = pos; quebra + 1 <= M; quebra++) {
        if (quebra - pos + 1 > N) break;
        if (valido(pos, quebra)) {
            val += solve(quebra + 1);
            val %= MODULO;
        }
    }
    return dp[pos] = val;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> ALFABETO >> cadeia;
    N = ALFABETO.size();
    M = cadeia.size();
    memset(dp, -1, sizeof(dp));
    dp[M] = 1LL;
    cout << solve(0) << endl;
    return 0;
}
