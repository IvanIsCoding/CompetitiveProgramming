// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1611
#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 10100
priority_queue<int> elevador;
int main() {
    int casos;
    scanf("%d", &casos);
    while (casos--) {
        int andares, capacidade, pessoas, resposta = 0;
        scanf("%d %d %d", &andares, &capacidade, &pessoas);
        while (pessoas--) {
            int davez;
            scanf("%d", &davez);
            elevador.push(davez);
        }
        while (!elevador.empty()) {
            resposta += 2 * elevador.top();
            for (int i = 0; i < capacidade && !elevador.empty(); i++)
                elevador.pop();
        }
        printf("%d\n", resposta);
    }
    return 0;
}
