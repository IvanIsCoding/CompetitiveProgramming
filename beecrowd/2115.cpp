// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2115
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<ii> vetorzao;
        for (int i = 0; i < n; i++) {
            int ini, tempo;
            scanf("%d %d", &ini, &tempo);
            vetorzao.push_back(MP(ini, tempo));
        }
        sort(vetorzao.begin(), vetorzao.end());
        int atual = 0;
        for (int i = 0; i < n; i++) {
            atual = max(atual, vetorzao[i].first);
            atual += vetorzao[i].second;
        }
        printf("%d\n", atual);
    }
    return 0;
}
