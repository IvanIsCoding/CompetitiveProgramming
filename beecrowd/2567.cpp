// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2567
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> entrada;
        for (int i = 0; i < n; i++) {
            int davez;
            scanf("%d", &davez);
            entrada.push_back(davez);
        }
        sort(entrada.begin(), entrada.end());
        int resp = 0;
        int ini = 0, fim = n - 1;
        while (ini <= fim) {
            resp += entrada[fim] - entrada[ini];
            ini++;
            fim--;
        }
        printf("%d\n", resp);
    }
    return 0;
}
