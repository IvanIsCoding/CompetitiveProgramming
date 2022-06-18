// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2242
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int main() {
    stack<char> pilha;
    queue<char> fila;
    char davez;
    while (scanf("%c", &davez) != EOF) {
        if (davez == 'a' || davez == 'e' || davez == 'i' || davez == 'o' ||
            davez == 'u') {
            pilha.push(davez);
            fila.push(davez);
        }
    }
    while (!pilha.empty()) {
        if (pilha.top() != fila.front()) {
            printf("N\n");
            return 0;
        }
        fila.pop();
        pilha.pop();
    }
    printf("S\n");
    return 0;
}
