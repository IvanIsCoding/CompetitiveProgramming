// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2227
#include <algorithm>
#include <cstdio>
#include <vector>
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int main() {
    int n, v, teste = 1;
    while (scanf("%d %d", &n, &v) && (n || v)) {
        printf("Teste %d\n", teste++);
        vi vetor;
        for (int i = 0; i <= n; i++) vetor.PB(0);
        while (v--) {
            int x, y;
            scanf("%d %d", &x, &y);
            vetor[x]++;
            vetor[y]++;
        }
        int grau = *(max_element(vetor.begin(), vetor.end()));
        for (int i = 1; i <= n; i++) {
            if (vetor[i] != grau) continue;
            printf("%d ", i);
        }
        printf("\n\n");
    }
    return 0;
}
