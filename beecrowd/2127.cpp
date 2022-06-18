// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2127
#include <cstdio>
#include <queue>
#define MAXN 1100
#define MP make_pair
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
using namespace std;
typedef pair<int, int> ii;
int pai[MAXN], peso[MAXN], conjuntos;
int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    conjuntos--;
    if (peso[x] < peso[y])
        pai[x] = y;
    else if (peso[x] > peso[y])
        pai[y] = x;
    else {
        pai[x] = y;
        peso[y]++;
    }
}
int main() {
    int n, m, instancia = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        int resposta = 0;
        conjuntos = n - 1;
        printf("Instancia %d\n", instancia++);
        queue<ii> fila1, fila2, fila3;
        for (int i = 1; i <= n; i++) {
            peso[i] = 0;
            pai[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int u, v, peso;
            getint(u);
            getint(v);
            getint(peso);
            if (peso == 1235)
                fila1.push(MP(u, v));
            else if (peso == 8977)
                fila2.push(MP(u, v));
            else
                fila3.push(MP(u, v));
        }
        while (conjuntos && !fila1.empty()) {
            ii davez = fila1.front();
            fila1.pop();
            if (find(davez.first) != find(davez.second)) {
                join(davez.first, davez.second);
                resposta += 1235;
            }
        }
        while (conjuntos && !fila2.empty()) {
            ii davez = fila2.front();
            fila2.pop();
            if (find(davez.first) != find(davez.second)) {
                join(davez.first, davez.second);
                resposta += 8977;
            }
        }
        while (conjuntos && !fila3.empty()) {
            ii davez = fila3.front();
            fila3.pop();
            if (find(davez.first) != find(davez.second)) {
                join(davez.first, davez.second);
                resposta += 10923;
            }
        }
        printf("%d\n\n", resposta);
    }
    return 0;
}
