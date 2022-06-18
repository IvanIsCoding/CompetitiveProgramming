// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2222
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        set<int> conjuntos[10001];
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int elementos;
            scanf("%d", &elementos);
            while (elementos--) {
                int davez;
                scanf("%d", &davez);
                conjuntos[i].insert(davez);
            }
        }
        int operacoes;
        scanf("%d", &operacoes);
        while (operacoes--) {
            int op, x, y;
            scanf("%d %d %d", &op, &x, &y);
            if (op == 1) {
                int contador = 0;
                set<int>::iterator it;
                for (it = conjuntos[x].begin(); it != conjuntos[x].end(); it++)
                    if (conjuntos[y].count(*it)) contador++;
                printf("%d\n", contador);
            } else {
                set<int> agora;
                set<int>::iterator it;
                for (it = conjuntos[x].begin(); it != conjuntos[x].end(); it++)
                    agora.insert(*it);
                for (it = conjuntos[y].begin(); it != conjuntos[y].end(); it++)
                    agora.insert(*it);
                printf("%lu\n", agora.size());
            }
        }
    }
    return 0;
}
