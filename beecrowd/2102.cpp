// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2102
#include <cstdio>
#include <map>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
map<ii, int> mapa;
int TC, m, n;
int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        if (tc != 1) printf("\n");
        scanf("%d %d", &m, &n);
        mapa.clear();
        while (n--) {
            int p, v, l, c;
            scanf("%d %d %d %d", &p, &l, &c, &v);
            mapa[MP(l, c)] += v;
        }
        for (auto it = mapa.begin(); it != mapa.end(); it++) {
            printf("%d %d %d\n", (*it).first.first, (*it).first.second,
                   (*it).second);
        }
    }
    return 0;
}
