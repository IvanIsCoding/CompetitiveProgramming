// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2293
#include <cstdio>
#define max(A, B) (A > B) ? (A) : (B)
int linha[110], coluna[110], resposta;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            linha[i] += x;
            coluna[j] += x;
        }
    }
    for (int i = 0; i < n; i++) resposta = max(resposta, linha[i]);
    for (int i = 0; i < m; i++) resposta = max(resposta, coluna[i]);
    printf("%d\n", resposta);
    return 0;
}
