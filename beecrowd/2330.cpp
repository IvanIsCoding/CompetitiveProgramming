// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2330
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    priority_queue<pair<int, pair<int, int> >,
                   vector<pair<int, pair<int, int> > >,
                   greater<pair<int, pair<int, int> > > >
        fila;
    vector<pair<int, int> > resposta;
    for (int i = 1; i <= n; i++) fila.push(make_pair(0, make_pair(i, 0)));
    while (l--) {
        int duracao;
        scanf("%d", &duracao);
        pair<int, pair<int, int> > davez = fila.top();
        fila.pop();
        fila.push(
            make_pair(davez.first + duracao,
                      make_pair(davez.second.first, davez.second.second + 1)));
    }
    for (int i = 1; i <= n; i++) {
        pair<int, pair<int, int> > davez = fila.top();
        fila.pop();
        resposta.push_back(make_pair(davez.second.first, davez.second.second));
    }
    sort(resposta.begin(), resposta.end());
    for (int i = 0; i < n; i++)
        printf("%d %d\n", resposta[i].first, resposta[i].second);
    return 0;
}
