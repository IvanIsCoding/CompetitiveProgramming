// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2445
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int resp = 0, soma = 0, n;
    scanf("%d", &n);
    vector<int> vetor;
    for (int i = 0; i < n; i++) {
        int davez;
        scanf("%d", &davez);
        vetor.push_back(davez);
    }
    sort(vetor.begin(), vetor.end());
    for (int i = 0; i < n; i++) {
        if (vetor[i] < soma) resp = i + 1;
        soma += vetor[i];
    }
    printf("%d\n", resp);
    return 0;
}
