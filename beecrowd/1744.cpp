// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1744
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
#define MAXN 5011
char entrada[MAXN];
long long a, b, resp;
int pretas, tamanho;
deque<int> proxima;
int main() {
    scanf("%lld %lld", &a, &b);
    scanf("%s", entrada);
    tamanho = strlen(entrada);
    for (int i = 0; i < tamanho; i++) {
        if (entrada[i] == 'B') {
            proxima.push_back(i + 1);
            pretas++;
        }
    }
    for (int vez = 1; vez <= pretas; vez++) {
        int esta = proxima.front();
        // printf("Esta %d Vez %d\n",esta,vez);
        if (esta == vez) {
            proxima.pop_front();
            continue;
        }
        int queremos = proxima.back();
        proxima.pop_back();
        // printf("Queremos %d Custo %lld\n",queremos,min(a,
        // (a-b)*(queremos-vez)
        // )
        // );
        resp += min(a, (a - b) * (queremos - vez));
    }
    printf("%lld\n", resp);
    return 0;
}
