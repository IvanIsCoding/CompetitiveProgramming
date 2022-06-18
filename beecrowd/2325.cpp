// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2325
#include <cstdio>
#include <map>
#include <set>
using namespace std;
int main() {
    int n, m;
    map<int, int> mapa;
    set<int> instalar;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int programa, codigo;
        scanf("%d %d", &programa, &codigo);
        mapa[programa] = codigo;
    }
    while (m--) {
        int davez, versao;
        scanf("%d %d", &davez, &versao);
        if (mapa[davez] < versao) {
            mapa[davez] = versao;
            instalar.insert(davez);
        }
    }
    for (set<int>::iterator it = instalar.begin(); it != instalar.end(); it++) {
        printf("%d %d\n", *it, mapa[*it]);
    }
    return 0;
}
