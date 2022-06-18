// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2427
#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int resposta = 0, n;
    scanf("%d", &n);
    queue<int> simulacao;
    simulacao.push(n);
    while (!simulacao.empty()) {
        int davez = simulacao.front();
        simulacao.pop();
        // printf("%d\n",davez);
        if (davez >= 2) {
            for (int i = 1; i <= 4; i++) simulacao.push(davez / 2);
        } else {
            resposta++;
        }
    }
    printf("%d\n", resposta);
    return 0;
}
