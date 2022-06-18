// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2658
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
struct node {
    int freq[9];
};
int lazy[4 * MAXN], n, q;
node seg[4 * MAXN], NULO;
node join(node A, node B) {
    node C;
    for (int i = 0; i < 9; i++) C.freq[i] = A.freq[i] + B.freq[i];
    return C;
}
void propagate(int pos, int left, int right) {
    if (lazy[pos] == 0) return;
    int copia[9];
    for (int i = 0; i < 9; i++) {
        copia[(i + lazy[pos]) % 9] = seg[pos].freq[i];
    }
    for (int i = 0; i < 9; i++) seg[pos].freq[i] = copia[i];
    if (left != right) {
        lazy[2 * pos] += lazy[pos];
        lazy[2 * pos + 1] += lazy[pos];
    }
    lazy[pos] = 0;
    return;
}
void build(int pos, int left, int right) {
    for (int i = 0; i < 9; i++) seg[pos].freq[i] = 0;
    seg[pos].freq[1] = right - left + 1;
    if (left != right) {
        int mid = (left + right) / 2;
        build(2 * pos, left, mid);
        build(2 * pos + 1, mid + 1, right);
    }
}
void update(int pos, int left, int right, int i, int j, int delta) {
    propagate(pos, left, right);
    if (left > right || left > j || right < i) return;
    if (left >= i && right <= j) {
        lazy[pos] += delta;
        propagate(pos, left, right);
        return;
    }
    int mid = (left + right) / 2;
    update(2 * pos, left, mid, i, j, delta);
    update(2 * pos + 1, mid + 1, right, i, j, delta);
    seg[pos] = join(seg[2 * pos], seg[2 * pos + 1]);
}
node query(int pos, int left, int right, int i, int j) {
    propagate(pos, left, right);
    if (left > right || left > j || right < i) return NULO;
    if (left >= i && right <= j) {
        return seg[pos];
    }
    int mid = (left + right) / 2;
    return join(query(2 * pos, left, mid, i, j),
                query(2 * pos + 1, mid + 1, right, i, j));
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < 9; i++) NULO.freq[i] = 0;
    build(1, 0, n - 1);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        node resp = query(1, 0, n - 1, a, b);
        int u = 0, maxu = -1;
        for (int i = 0; i < 9; i++) {
            if (resp.freq[i] >= maxu) {
                u = i;
                maxu = resp.freq[i];
            }
        }
        // printf("U %d MAXU %d\n",u,maxu);
        update(1, 0, n - 1, a, b, u);
    }
    for (int i = 0; i < n; i++) {
        node temp = query(1, 0, n - 1, i, i);
        for (int j = 0; j < 9; j++) {
            if (temp.freq[j]) printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
