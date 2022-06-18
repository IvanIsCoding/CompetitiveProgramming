// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1750
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
using namespace std;
deque<int> cupidos;
inline int calcula(int a, int b) {
    int delta = abs(a - b);
    return min(delta, 24 - delta);
}
int func() {
    int soma = 0;
    for (int i = 0; i + 1 < cupidos.size(); i += 2) {
        soma += calcula(cupidos[i], cupidos[i + 1]);
    }
    return soma;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int davez;
        scanf("%d", &davez);
        cupidos.push_back(davez);
    }
    sort(cupidos.begin(), cupidos.end());
    int referencia = func();
    for (int vez = 1; vez <= n; vez++) {
        cupidos.push_back(cupidos.front());
        cupidos.pop_front();
        referencia = min(referencia, func());
    }
    printf("%d\n", referencia);
    return 0;
}
