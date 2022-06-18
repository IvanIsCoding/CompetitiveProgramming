// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2451
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 200
char matriz[MAXN][MAXN];
int soma, resposta, n, i, j;
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%s", matriz[i]);
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < n; j++) {
                if (matriz[i][j] == 'o') soma++;
                if (matriz[i][j] == 'A') soma = 0;
                resposta = max(resposta, soma);
            }
        } else {
            for (j = n - 1; j >= 0; j--) {
                if (matriz[i][j] == 'o') soma++;
                if (matriz[i][j] == 'A') soma = 0;
                resposta = max(resposta, soma);
            }
        }
    }
    printf("%d\n", resposta);
    return 0;
}
