// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2398
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define MAXN 110
using namespace std;
int main() {
    int n, k, resposta = 0, resp1, resp2;
    vector<pair<int, pair<int, int> > > pares;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        pares.push_back(make_pair(z, make_pair(x, y)));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int pode_ser = 1;
            for (int k = 0; k < pares.size(); k++) {
                pair<int, pair<int, int> > par = pares[k];
                if (abs(i - par.second.first) + abs(j - par.second.second) !=
                    par.first) {
                    pode_ser = 0;
                    break;
                }
            }
            if (pode_ser) {
                resp1 = i;
                resp2 = j;
                resposta++;
            }
            if (resposta > 1) {
                printf("-1 -1\n");
                return 0;
            }
        }
    }
    if (resposta == 1)
        printf("%d %d\n", resp1, resp2);
    else
        printf("-1 -1\n");
    return 0;
}
