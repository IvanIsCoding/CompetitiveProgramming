// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2522
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int MAXN = 510;
int X[MAXN], Y[MAXN], pai[MAXN], n;
vector<iii> Kruskal;
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x > y) swap(x, y);
    pai[y] = x;
}
inline int dot(int x, int y) { return x * x + y * y; }
int main() {
    while (scanf("%d", &n) != EOF) {
        Kruskal.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &X[i], &Y[i]);
            pai[i] = i;
        }
        double resp = 0.0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                Kruskal.push_back(MP(dot(X[i] - X[j], Y[i] - Y[j]), MP(i, j)));
            }
        }
        sort(Kruskal.begin(), Kruskal.end());
        for (int i = 0; i < Kruskal.size(); i++) {
            if (find(Kruskal[i].second.first) !=
                find(Kruskal[i].second.second)) {
                join(Kruskal[i].second.first, Kruskal[i].second.second);
                resp += sqrt(Kruskal[i].first);
            }
        }
        printf("%.2lf\n", resp);
    }
    return 0;
}
