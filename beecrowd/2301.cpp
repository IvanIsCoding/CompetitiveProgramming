// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2301
#include <algorithm>
#include <cstdio>
#include <vector>
#define PB push_back
using namespace std;
int main() {
    int p, r, teste = 1;
    while (scanf("%d %d", &p, &r) && (p || r)) {
        vector<int> numeros;
        for (int i = 0; i < p; i++) {
            int davez;
            scanf("%d", &davez);
            numeros.PB(davez);
        }
        for (int i = 0; i < r; i++) {
            int j, k;
            vector<int> temp;
            scanf("%d %d", &j, &k);
            for (int q = 0; q < j; q++) {
                int davez;
                scanf("%d", &davez);
                if (davez == k) temp.PB(numeros[q]);
            }
            swap(temp, numeros);
        }
        printf("Teste %d\n%d\n\n", teste++, numeros[0]);
    }
    return 0;
}
