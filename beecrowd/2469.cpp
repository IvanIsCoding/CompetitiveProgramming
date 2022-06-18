// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2469
#include <cstdio>
#include <map>
using namespace std;
int main() {
    int n, i, resposta, vezes = 0, davez;
    map<int, int> mapa;
    map<int, int>::iterator it;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &davez);
        if (mapa.find(davez) != mapa.end())
            mapa[davez] += 1;
        else
            mapa[davez] = 1;
    }
    for (it = mapa.begin(); it != mapa.end(); it++) {
        if ((*it).second > vezes) {
            resposta = (*it).first;
            vezes = (*it).second;
        } else if ((*it).second == vezes && (*it).first > resposta)
            resposta = (*it).first;
    }
    printf("%d\n", resposta);
    return 0;
}
