// Ivan Carvalho
// Solution to
https :  // www.beecrowd.com.br/judge/problems/view/2881
#include <bits/stdc++.h>
         using namespace std;

typedef tuple<int, int, int, int> trinca;

const int INF = 1e8;
const int NEG = -INF;
const int MAXL = 1036;
const int MAXN = 1010;

int N, M, dp[MAXN][MAXL], nxt_place[MAXN], stage[MAXN], points[MAXN];
vector<trinca> sortedOrder;
vector<int> mySearch;

int solve(int pos, int bitmask) {
    if (pos == M) {
        if (__builtin_popcount(bitmask) != N) return NEG;
        return 0;
    }

    if (dp[pos][bitmask] != -1) return dp[pos][bitmask];

    int nxt = nxt_place[pos], nbitmask = bitmask | (1 << stage[pos]);

    return dp[pos][bitmask] =
               max(solve(nxt, nbitmask) + points[pos], solve(pos + 1, bitmask));
}

int main() {
    cin >> N;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++) {
        int qtd;
        cin >> qtd;
        for (int j = 0; j < qtd; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            sortedOrder.push_back(make_tuple(a, b, c, i));
        }
    }

    M = sortedOrder.size();
    sort(sortedOrder.begin(), sortedOrder.end());

    for (int i = 0; i < M; i++) {
        mySearch.push_back(get<0>(sortedOrder[i]));
    }

    for (int i = 0; i < M; i++) {
        stage[i] = get<3>(sortedOrder[i]);
        points[i] = get<2>(sortedOrder[i]);
        vector<int>::iterator it = lower_bound(mySearch.begin(), mySearch.end(),
                                               get<1>(sortedOrder[i]));
        if (it == mySearch.end()) {
            nxt_place[i] = M;
        } else {
            nxt_place[i] = it - mySearch.begin();
        }
    }

    int best = solve(0, 0);
    if (best < 0) best = -1;

    cout << best << endl;

    return 0;
}
