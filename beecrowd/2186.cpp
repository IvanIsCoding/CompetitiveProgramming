// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2186
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int MAXN = 1e6 + 10;
const int ALPHABET_SIZE = 26;
typedef struct node *pnode;
vector<int> modelo[ALPHABET_SIZE];
char entrada[MAXN];
struct node {
    pnode l, r;
    int prior, size, rev;
    int puro;
    vector<int> total;
    node(int puro)
        : puro(puro), size(1), prior(rand()), rev(0), l(NULL), r(NULL) {
        total = modelo[puro];
    }
};
inline int sz(pnode t) { return (t == NULL) ? 0 : t->size; }
inline void upd_sz(pnode t) {
    if (t) t->size = sz(t->l) + 1 + sz(t->r);
}
inline int tot(pnode t, int c) { return (t == NULL) ? 0 : t->total[c]; }
inline void operation(pnode t) {
    if (t)
        for (int c = 0; c < ALPHABET_SIZE; c++)
            t->total[c] = tot(t->l, c) + (t->puro == c) + tot(t->r, c);
}
void push(pnode &t) {
    if (t && t->rev) {
        t->rev = 0;
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= 1;
        if (t->r) t->r->rev ^= 1;
    }
}
void split(pnode t, int key, int add, pnode &l, pnode &r) {
    if (t == NULL) {
        l = r = NULL;
    } else {
        push(t);
        int cur_key = sz(t->l) + add + 1;
        if (key < cur_key) {
            split(t->l, key, add, l, t->l);
            r = t;
        } else {
            split(t->r, key, add + sz(t->l) + 1, t->r, r);
            l = t;
        }
    }
    upd_sz(t);
    operation(t);
}
void merge(pnode &t, pnode l, pnode r) {
    push(l);
    push(r);
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
    operation(t);
}
void insert(pnode &t, int key, int val) {
    pnode L, R;
    pnode aux = new node(val);
    split(t, key - 1, 0, L, R);
    merge(t, L, aux);
    merge(t, t, R);
}
void erase(pnode &t, int key) {
    pnode L, mid, R;
    split(t, key - 1, 0, L, R);
    split(R, key, sz(L), mid, R);
    merge(t, L, R);
}
void reverse(pnode &t, int a, int b) {
    pnode L, mid, R;
    split(t, a - 1, 0, L, R);
    split(R, b, sz(L), mid, R);
    mid->rev = 1;
    merge(t, L, mid);
    merge(t, t, R);
}
int search(pnode t, int add, int key) {
    push(t);
    int cur_key = sz(t->l) + add + 1;
    if (key < cur_key) return search(t->l, add, key);
    if (key == cur_key) return t->puro;
    return search(t->r, add + sz(t->l) + 1, key);
}
int find_first(pnode t, int add, int val) {
    push(t);
    int cur_key = sz(t->l) + add + 1;
    if (tot(t->l, val) > 0) {
        return find_first(t->l, add, val);
    }
    if (t->puro == val) return cur_key;
    return find_first(t->r, add + sz(t->l) + 1, val);
}
int find_last(pnode t, int add, int val) {
    push(t);
    int cur_key = sz(t->l) + add + 1;
    if (tot(t->r, val) > 0) {
        return find_last(t->r, add + sz(t->l) + 1, val);
    }
    if (t->puro == val) return cur_key;
    return find_last(t->l, add, val);
}
int query_qtd(pnode t, int a, int b, int c) {
    pnode L, mid, R;
    split(t, a - 1, 0, L, R);
    split(R, b, sz(L), mid, R);
    int resp = mid->total[c];
    merge(t, L, mid);
    merge(t, t, R);
    return resp;
}
void query_find(pnode t, int a, int b, int c, int &resp1, int &resp2) {
    pnode L, mid, R;
    split(t, a - 1, 0, L, R);
    split(R, b, sz(L), mid, R);
    if (mid->total[c] == 0) {
        resp1 = resp2 = -1;
    } else {
        resp1 = find_first(mid, sz(L), c);
        resp2 = find_last(mid, sz(L), c);
    }
    merge(t, L, mid);
    merge(t, t, R);
}
int main() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        modelo[i].assign(ALPHABET_SIZE, 0);
        modelo[i][i] = 1;
    }
    int N, Q;
    scanf("%d %d", &N, &Q);
    scanf("%s", entrada);
    pnode raiz = NULL;
    for (int i = 0; i < N; i++) {
        int c = entrada[i] - 'a';
        pnode aux = new node(c);
        merge(raiz, raiz, aux);
    }
    while (Q--) {
        int op, a, b, c;
        char davez;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %c", &a, &b, &davez);
            c = davez - 'a';
            printf("%d\n", query_qtd(raiz, a, b, c));
        } else if (op == 2) {
            scanf("%d %d %c", &a, &b, &davez);
            c = davez - 'a';
            int exibir1, exibir2;
            query_find(raiz, a, b, c, exibir1, exibir2);
            if (exibir1 == -1)
                printf("-1\n");
            else
                printf("%d %d\n", exibir1, exibir2);
        } else if (op == 3) {
            scanf("%d %d", &a, &b);
            reverse(raiz, a, b);
        } else {
            scanf("%d %c", &a, &davez);
            c = davez - 'a';
            insert(raiz, a, c);
        }
    }
    int tam = sz(raiz);
    for (int i = 1; i <= tam; i++) {
        char davez = 'a' + search(raiz, 0, i);
        printf("%c", davez);
    }
    printf("\n");
    return 0;
}
