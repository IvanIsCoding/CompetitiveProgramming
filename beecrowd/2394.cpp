// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2394
#include <cstdio>
#include <queue>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
int main() {
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int resposta = 0;
        for (int j = 0; j < m; j++) {
            int k;
            scanf("%d", &k);
            resposta += k;
        }
        heap.push(MP(resposta, i));
    }
    printf("%d\n", heap.top().second);
    return 0;
}
