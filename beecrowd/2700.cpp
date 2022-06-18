// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2700
#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> trinca;
const int MAXN = 1e5 + 10;
vector<trinca> sweep, atu;
vector<ll> comp;
ll bit[MAXN], resp, N;
ll e1[MAXN], e2[MAXN], e3[MAXN];
void update(int idx, ll delta) {
    while (idx < MAXN) {
        bit[idx] = max(bit[idx], delta);
        idx += LSOne(idx);
    }
}
ll query(int idx) {
    ll ans = 0;
    while (idx > 0) {
        ans = max(bit[idx], ans);
        idx -= LSOne(idx);
    }
    return ans;
}
int main() {
    cin.tie(0);
    cout.tie();
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> e1[i] >> e2[i] >> e3[i];
        comp.push_back(e2[i]);
    }
    sort(comp.begin(), comp.end());
    for (ll i = 0; i < N; i++) {
        e2[i] = lower_bound(comp.begin(), comp.end(), e2[i]) - comp.begin() + 1;
        sweep.push_back(make_tuple(e1[i], e2[i], e3[i]));
    }
    sort(sweep.begin(), sweep.end());
    vector<trinca> agoravai;
    for (int i = 0; i < N; i++) {
        if (!agoravai.empty() && get<0>(agoravai.back()) == get<0>(sweep[i]) &&
            get<1>(agoravai.back()) == get<1>(sweep[i])) {
            get<2>(agoravai.back()) += get<2>(sweep[i]);
        } else {
            agoravai.push_back(sweep[i]);
        }
    }
    sweep = agoravai;
    for (int i = 0; i < N; i++) {
        ll x = get<0>(sweep[i]), y = get<1>(sweep[i]), val = get<2>(sweep[i]);
        while (!atu.empty() && get<0>(atu.back()) < x) {
            update(get<1>(atu.back()), get<2>(atu.back()));
            atu.pop_back();
        }
        ll davez = query(y - 1) + val;
        atu.push_back(make_tuple(x, y, davez));
        resp = max(resp, davez);
    }
    cout << resp << endl;
    return 0;
}
