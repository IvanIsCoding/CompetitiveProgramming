// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2393
#include <algorithm>
#include <cstdio>
using namespace std;
int matriz[110][110], resposta;
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++) matriz[i][j] = 1;
    }
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 110; j++) resposta += matriz[i][j];
    printf("%d\n", resposta);
    return 0;
}
