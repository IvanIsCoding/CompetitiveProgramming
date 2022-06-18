// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2390
#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int n, resposta = 0, desligar = 0, ligado = 0;
    queue<int> fila;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int davez;
        scanf("%d", &davez);
        fila.push(davez);
    }
    for (int momento = 0; momento <= 100000000; momento++) {
        int alguem = 0;
        if (fila.empty() && momento > desligar) break;
        while (fila.front() == momento) {
            fila.pop();
            alguem++;
        }
        if (alguem != 0) desligar = momento + 10;
        if (desligar > momento)
            ligado = 1;
        else
            ligado = 0;
        resposta += ligado;
    }
    printf("%d\n", resposta);
    return 0;
}
