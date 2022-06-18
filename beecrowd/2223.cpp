// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2223
#include <iostream>
#include <vector>
#define MAXN 100110
using namespace std;
vector<int> val, esq, dir;
int segIt;
int raiz[MAXN], n, q, atualizacao;
inline void cria() {
    esq.push_back(0);
    dir.push_back(0);
    val.push_back(0);
}
void update(int novo, int velho, int left, int right, int x, int delta) {
    if (left == right) {
        val[novo] = delta;
        return;
    }
    int mid = (left + right) / 2;
    if (x <= mid) {
        cria();
        esq[novo] = ++segIt;
        dir[novo] = dir[velho];
        update(esq[novo], esq[velho], left, mid, x, delta);
    } else {
        cria();
        esq[novo] = esq[velho];
        dir[novo] = ++segIt;
        update(dir[novo], dir[velho], mid + 1, right, x, delta);
    }
    val[novo] = val[esq[novo]] + val[dir[novo]];
}
int query(int pos, int left, int right, int i, int j) {
    if (left > right || left > j || right < i) return 0;
    if (left >= i && right <= j) {
        return val[pos];
    }
    int mid = (left + right) / 2;
    return query(esq[pos], left, mid, i, j) +
           query(dir[pos], mid + 1, right, i, j);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        cria();
        segIt = 0;
        atualizacao = 0;
        raiz[0] = 0;
        cria();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int davez;
            cin >> davez;
            cria();
            int novo = ++segIt;
            update(novo, raiz[0], 1, n, i, davez);
            raiz[0] = novo;
        }
        cin >> q;
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x, y, k;
                cin >> x >> y >> k;
                cout << query(raiz[k], 1, n, x, y) << '\n';
            } else {
                int x, w;
                cin >> x >> w;
                cria();
                raiz[++atualizacao] = ++segIt;
                update(raiz[atualizacao], raiz[atualizacao - 1], 1, n, x, w);
            }
        }
    }
    return 0;
}
