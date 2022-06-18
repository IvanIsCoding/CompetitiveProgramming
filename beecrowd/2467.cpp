// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2467
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
typedef struct node *pnode;
const int MAXN = 1e5 + 10;
const int MAXR = 51;
int ultima_linha[MAXN], ultima_coluna[MAXN], atual_linha[MAXN],
    atual_coluna[MAXN], iteracao;
struct node {
    pnode l, r;
    int size, prior;
    ii key;
    node(ii key) : key(key), size(1), prior(rand()), l(NULL), r(NULL) {}
};
inline int sz(pnode t) {
    if (t == NULL) return 0;
    return t->size;
}
inline void upd_sz(pnode t) {
    if (t) t->size = sz(t->l) + 1 + sz(t->r);
}
void split(pnode t, ii key, pnode &l, pnode &r) {
    if (t == NULL) {
        l = r = NULL;
    } else if (key < t->key) {
        split(t->l, key, l, t->l);
        r = t;
    } else {
        split(t->r, key, t->r, r);
        l = t;
    }
    upd_sz(t);
}
void merge(pnode &t, pnode l, pnode r) {
    if (l == NULL) {
        t = r;
    } else if (r == NULL) {
        t = l;
    } else if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    upd_sz(t);
}
void insert(pnode &t, ii key) {
    pnode L, R;
    pnode aux = new node(key);
    split(t, MP(key.first, key.second - 1), L, R);
    merge(t, L, aux);
    merge(t, t, R);
}
void erase(pnode &t, ii key) {
    pnode L, mid, R;
    split(t, MP(key.first, key.second - 1), L, R);
    split(R, key, mid, R);
    merge(t, L, R);
}
int query(pnode t, ii key) {
    pnode L, R;
    split(t, key, L, R);
    int resp = sz(R);
    merge(t, L, R);
    return resp;
}
pnode raiz_linha[MAXR], raiz_coluna[MAXR];
int main() {
    int n, q, r = 50;
    scanf("%d %d", &n, &q);
    for (int i = 0; i <= r; i++) {
        raiz_linha[i] = NULL;
        raiz_coluna[i] = NULL;
    }
    for (int i = 1; i <= n; i++) {
        insert(raiz_linha[0], MP(0, i));
        insert(raiz_coluna[0], MP(0, i));
    }
    while (q--) {
        iteracao++;
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, davez;
            scanf("%d %d", &x, &davez);
            erase(raiz_linha[atual_linha[x]], MP(ultima_linha[x], x));
            atual_linha[x] = davez;
            ultima_linha[x] = iteracao;
            insert(raiz_linha[davez], MP(iteracao, x));
        } else if (op == 2) {
            int x, davez;
            scanf("%d %d", &x, &davez);
            erase(raiz_coluna[atual_coluna[x]], MP(ultima_coluna[x], x));
            atual_coluna[x] = davez;
            ultima_coluna[x] = iteracao;
            insert(raiz_coluna[davez], MP(iteracao, x));
        } else if (op == 3) {
            int x;
            scanf("%d", &x);
            int davez = atual_linha[x];
            int ultima = ultima_linha[x];
            ii resp = MP(-1, -1);
            ii pergunta = MP(ultima - 1, n + 1);
            int tot = 0;
            for (int cor = 0; cor <= r; cor++) {
                if (cor == davez) continue;
                int conta = query(raiz_coluna[cor], pergunta);
                resp = max(resp, MP(conta, cor));
                tot += conta;
            }
            resp = max(resp, MP(n - tot, davez));
            printf("%d\n", resp.second);
        } else {
            int x;
            scanf("%d", &x);
            int davez = atual_coluna[x];
            int ultima = ultima_coluna[x];
            ii resp = MP(-1, -1);
            ii pergunta = MP(ultima - 1, n + 1);
            int tot = 0;
            for (int cor = 0; cor <= r; cor++) {
                if (cor == davez) continue;
                int conta = query(raiz_linha[cor], pergunta);
                resp = max(resp, MP(conta, cor));
                tot += conta;
            }
            resp = max(resp, MP(n - tot, davez));
            printf("%d\n", resp.second);
        }
    }
    return 0;
}
