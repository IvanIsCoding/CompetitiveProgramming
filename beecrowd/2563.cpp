// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2563
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXP = 1e4 + 1;
int melhor[MAXP], D[MAXP], P[MAXP], n, cap;
int main() {
    while (scanf("%d %d", &n, &cap) != EOF) {
        memset(melhor, 0, sizeof(melhor));
        for (int i = 1; i <= n; i++) scanf("%d", &D[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &P[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = MAXP - 1; j >= P[i]; j--) {
                melhor[j] = max(melhor[j], melhor[j - P[i]] + D[i]);
            }
        }
        int resp = 0;
        for (int i = 0; i <= cap; i++) resp = max(resp, melhor[i]);
        printf("%d\n", resp);
    }
    return 0;
}
