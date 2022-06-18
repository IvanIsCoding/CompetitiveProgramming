// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2481
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll NEG = -1e16;
struct line {
    ll a, b;
    line(ll a, ll b) : a(a), b(b) {}
};
struct cht {
    vector<line> hull;
    ll pointer;
    bool useless(line left, line mid, line right) {
        return (right.b - left.b) * (left.a - mid.a) <
               (left.b - mid.b) * (right.a - left.a);
    }
    void add(line t) {
        while (!hull.empty() && hull.back().a == t.a && hull.back().b > t.b) {
            hull.pop_back();
        }
        while (hull.size() >= 2 &&
               useless(hull[hull.size() - 2], hull[hull.size() - 1], t)) {
            hull.pop_back();
        }
        hull.push_back(t);
    }
    ll query(ll x) {
        if (pointer >= hull.size()) pointer = hull.size() - 1;
        while (pointer + 1 < hull.size() &&
               hull[pointer + 1].a * x + hull[pointer + 1].b <
                   hull[pointer].a * x + hull[pointer].b) {
            pointer++;
        }
        return hull[pointer].a * x + hull[pointer].b;
    }
};
int main() {
    int TC;
    scanf("%d", &TC);
    cht dp;
    while (TC--) {
        dp.hull.clear();
        dp.pointer = 0;
        int n;
        scanf("%d", &n);
        dp.add(line(0, 0));
        ll xi, ci;
        for (int i = 1; i < n; i++) {
            scanf("%lld %lld", &xi, &ci);
            ll best = -dp.query(xi) - xi * xi - ci;
            dp.add(line(-xi, -best));
        }
        scanf("%lld %lld", &xi, &ci);
        ll resp = -dp.query(xi) - ci;
        if (resp <= 0)
            printf("Perde %lld\n", -1LL * resp);
        else
            printf("Ganha %lld\n", resp);
    }
    return 0;
}
