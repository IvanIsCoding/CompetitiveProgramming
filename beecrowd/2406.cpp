// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2406
#include <cstdio>
#include <cstring>
#define MAX 100010
int tam, n, i, j, tamanho;
char pilha[MAX], entrada[MAX];
void clear() { tam = 0; }
void push(char x) { pilha[++tam] = x; }
void pop() {
    if (tam > 0) tam--;
}
char top() { return pilha[tam]; }
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        clear();
        scanf("%s", entrada);
        tamanho = strlen(entrada);
        bool verdade = true;
        for (j = 0; j < tamanho; j++) {
            if (entrada[j] == '(')
                push('(');
            else if (entrada[j] == '[')
                push('[');
            else if (entrada[j] == '{')
                push('{');
            else if (entrada[j] == ')') {
                if (top() == '(')
                    pop();
                else {
                    verdade = false;
                    break;
                }
            } else if (entrada[j] == ']') {
                if (top() == '[')
                    pop();
                else {
                    verdade = false;
                    break;
                }
            } else if (entrada[j] == '}') {
                if (top() == '{')
                    pop();
                else {
                    verdade = false;
                    break;
                }
            }
        }
        if (verdade && tam == 0)
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}
