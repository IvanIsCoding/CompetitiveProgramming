// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2529
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct node *pnode;
struct node {
    pnode l, r;
    int rev, size, prior;
    int val, total;
    node(int val)
        : val(val),
          total(val),
          prior(rand()),
          l(NULL),
          r(NULL),
          size(1),
          rev(0) {}
};
int sz(pnode t) { return (t == NULL) ? 0 : t->size; }
void upd_sz(pnode t) {
    if (t) t->size = sz(t->l) + 1 + sz(t->r);
}
int tot(pnode t) { return (t == NULL) ? 0 : t->total; }
void operation(pnode t) {
    if (t) t->total = tot(t->l) + t->val + tot(t->r);
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
    pnode aux = new node(val % 2);
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
    if (t) push(t);
    split(t, a - 1, 0, L, R);
    split(R, b, sz(L), mid, R);
    mid->rev = 1;
    merge(t, L, mid);
    merge(t, t, R);
}
int query_even(pnode &t, int a, int b) {
    pnode L, mid, R;
    if (t) push(t);
    split(t, a - 1, 0, L, R);
    split(R, b, sz(L), mid, R);
    int ans = mid->size - mid->total;
    merge(t, L, mid);
    merge(t, t, R);
    return ans;
}
int query_odd(pnode &t, int a, int b) {
    pnode L, mid, R;
    if (t) push(t);
    split(t, a - 1, 0, L, R);
    split(R, b, sz(L), mid, R);
    int ans = mid->total;
    merge(t, L, mid);
    merge(t, t, R);
    return ans;
}
int main() {
    int n, q;
    while (scanf("%d %d", &n, &q) != EOF) {
        pnode raiz = NULL;
        for (int i = 1; i <= n; i++) {
            int davez;
            scanf("%d", &davez);
            insert(raiz, i, davez);
        }
        while (q--) {
            char op;
            int a, b;
            scanf(" %c %d %d", &op, &a, &b);
            if (op == 'S') {
                erase(raiz, a);
                insert(raiz, a, b);
            }
            if (op == 'E') {
                printf("%d\n", query_even(raiz, a, b));
            }
            if (op == 'O') {
                printf("%d\n", query_odd(raiz, a, b));
            }
            if (op == 'I') {
                reverse(raiz, a, b);
            }
        }
    }
    return 0;
}
