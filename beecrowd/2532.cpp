// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2532
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 2010;
const int INF = 1e8;
int custo[MAXN], n, hp;
int main() {
    while (scanf("%d %d", &n, &hp) != EOF) {
        for (int i = 1; i < MAXN; i++) {
            custo[i] = INF;
        }
        custo[0] = 0;
        while (n--) {
            int dano, mana;
            scanf("%d %d", &dano, &mana);
            for (int i = MAXN - 1; i >= dano; i--) {
                custo[i] = min(custo[i], custo[i - dano] + mana);
            }
        }
        int minimo = INF;
        for (int i = hp; i < MAXN; i++) {
            minimo = min(minimo, custo[i]);
        }
        if (minimo == INF)
            printf("-1\n");
        else
            printf("%d\n", minimo);
    }
    return 0;
}
