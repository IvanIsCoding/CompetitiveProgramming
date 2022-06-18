// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2656
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))
const int MAXN = 2 * 1e5 + 20;
const int ADD = 1e5 + 2;
typedef pair<int, int> ii;
typedef struct node *pnode;
map<ii, int> mapa;
struct node {
    int val;
    pnode l, r;
    node() : val(0), l(NULL), r(NULL) {}
    void update(int left, int right, int x, int delta) {
        if (left == right) {
            val += delta;
            return;
        }
        val += delta;
        int mid = (left + right) / 2;
        if (x <= mid) {
            if (l == NULL) l = new node;
            l->update(left, mid, x, delta);
        } else {
            if (r == NULL) r = new node;
            r->update(mid + 1, right, x, delta);
        }
    }
    int query(int left, int right, int i, int j) {
        if (left >= i && right <= j) {
            return val;
        }
        int mid = (left + right) / 2;
        if (j <= mid) {
            return (l == NULL) ? 0 : l->query(left, mid, i, j);
        }
        if (i >= mid + 1) {
            return (r == NULL) ? 0 : r->query(mid + 1, right, i, j);
        }
        return ((l == NULL) ? 0 : l->query(left, mid, i, j)) +
               ((r == NULL) ? 0 : r->query(mid + 1, right, i, j));
    }
};
pnode bit[MAXN];
void update(int x, int y, int delta) {
    while (x < MAXN) {
        bit[x]->update(1, MAXN, y, delta);
        x += LSOne(x);
    }
}
int read(int x, int y1, int y2) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x]->query(1, MAXN, y1, y2);
        x -= LSOne(x);
    }
    return ans;
}
int query(int x1, int y1, int x2, int y2) {
    return read(x2, y1, y2) - read(x1 - 1, y1, y2);
}
int main() {
    int Q;
    scanf("%d", &Q);
    for (int i = 1; i < MAXN; i++) {
        bit[i] = new node;
    }
    while (Q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        x++;
        y++;
        if (op == 1) {
            int tx = y - x + ADD;
            int ty = x + y;
            ii par = ii(tx, ty);
            if (mapa[par] == 1) {
                continue;
            }
            mapa[par] = 1;
            update(tx, ty, 1);
        }
        if (op == 2) {
            int tx = y - x + ADD;
            int ty = x + y;
            ii par = ii(tx, ty);
            if (mapa[par] == 0) {
                continue;
            }
            mapa[par] = 0;
            update(tx, ty, -1);
        }
        if (op == 3) {
            int d;
            scanf("%d", &d);
            int lo_x = y - x - d + ADD;
            int lo_y = x + y - d;
            int hi_x = y - x + d + ADD;
            int hi_y = x + y + d;
            lo_x = max(lo_x, 1);
            lo_y = max(lo_y, 1);
            hi_x = min(hi_x, MAXN - 1);
            hi_y = min(hi_y, MAXN - 1);
            printf("%d\n", query(lo_x, lo_y, hi_x, hi_y));
        }
    }
    return 0;
}
