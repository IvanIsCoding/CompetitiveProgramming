// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2296
#include <algorithm>
#include <cstdio>
#include <vector>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
vector<ii> trilhas;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        vector<int> alturas;
        int m, r1 = 0, r2 = 0;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int k;
            scanf("%d", &k);
            alturas.push_back(k);
        }
        for (int j = 0; j + 1 < m; j++) {
            r1 += max(0, alturas[j + 1] - alturas[j]);
        }
        for (int j = m - 1; j > 0; j--) {
            r2 += max(0, alturas[j - 1] - alturas[j]);
        }
        trilhas.push_back(MP(min(r1, r2), i));
    }
    sort(trilhas.begin(), trilhas.end());
    printf("%d\n", trilhas[0].second);
    return 0;
}
