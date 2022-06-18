// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2387
#include <algorithm>
#include <cstdio>
#include <deque>
using namespace std;
int main() {
    int n, resposta = 0, momento = 0;
    deque<pair<int, int> > fila;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int inicio, termino;
        scanf("%d %d", &inicio, &termino);
        fila.push_back(make_pair(termino, inicio));
    }
    sort(fila.begin(), fila.end());
    while (!fila.empty()) {
        pair<int, int> davez = fila.front();
        fila.pop_front();
        if (davez.second >= momento) {
            momento = davez.first;
            resposta++;
        }
    }
    printf("%d\n", resposta);
    return 0;
}
