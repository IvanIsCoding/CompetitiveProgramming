// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2878
#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
using namespace std;

const int MAXN = 1e5 + 10;

typedef long long ll;
typedef pair<int, int> ii;

vector<ii> myPoints;
vector<int> comp;
int bit[MAXN], N, H, V, X, Y;

void update(int x) {
    while (x < MAXN) {
        bit[x]++;
        x += LSOne(x);
    }
}

int read(int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= LSOne(x);
    }
    return ans;
}

long long invcount() {
    memset(bit, 0, sizeof(bit));
    comp.clear();
    N = myPoints.size();

    sort(myPoints.begin(), myPoints.end());

    for (int i = 0; i < N; i++) {
        comp.push_back(myPoints[i].second);
    }

    sort(comp.begin(), comp.end());

    long long inversions = 0;

    for (int i = 0; i < N; i++) {
        int val = lower_bound(comp.begin(), comp.end(), myPoints[i].second) -
                  comp.begin() + 1;
        inversions += read(N + 1) - read(val);
        update(val);
    }

    return inversions;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long ans = 0;

    cin >> X >> Y;
    cin >> H >> V;

    ans += 1LL * (1 + H) * (1 + V);

    for (int i = 1; i <= H; i++) {
        int a, b;
        cin >> a >> b;
        myPoints.push_back(ii(a, b));
    }

    ans += invcount();

    myPoints.clear();

    for (int i = 1; i <= V; i++) {
        int a, b;
        cin >> a >> b;
        myPoints.push_back(ii(a, b));
    }

    ans += invcount();

    cout << ans << endl;

    return 0;
}
