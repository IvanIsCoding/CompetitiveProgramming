// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2546
#include <algorithm>
#include <cstdio>
#define MP make_pair
#define MAXN 100010
using namespace std;
typedef pair<int, int> ii;
int vetor[MAXN], lazy[4 * MAXN], n, q;
ii arvore[4 * MAXN];
void build(int pos, int left, int right) {
    if (left == right) {
        lazy[pos] = 0;
        arvore[pos] = MP(vetor[left], -left);
        return;
    }
    lazy[pos] = 0;
    int mid = (left + right) / 2;
    build(2 * pos, left, mid);
    build(2 * pos + 1, mid + 1, right);
    arvore[pos] = max(arvore[2 * pos], arvore[2 * pos + 1]);
}
void update(int pos, int left, int right, int val, int i, int j) {
    if (lazy[pos] != 0) {
        arvore[pos] = MP(arvore[pos].first + lazy[pos], arvore[pos].second);
        if (left != right) {
            lazy[2 * pos] += lazy[pos];
            lazy[2 * pos + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (left > right || left > j || right < i) return;
    if (left >= i && right <= j) {
        arvore[pos] = MP(arvore[pos].first + val, arvore[pos].second);
        if (left != right) {
            lazy[2 * pos] += val;
            lazy[2 * pos + 1] += val;
        }
        return;
    }
    int mid = (left + right) / 2;
    update(2 * pos, left, mid, val, i, j);
    update(2 * pos + 1, mid + 1, right, val, i, j);
    arvore[pos] = max(arvore[2 * pos], arvore[2 * pos + 1]);
}
ii query(int pos, int left, int right, int i, int j) {
    if (lazy[pos] != 0) {
        arvore[pos] = MP(arvore[pos].first + lazy[pos], arvore[pos].second);
        if (left != right) {
            lazy[2 * pos] += lazy[pos];
            lazy[2 * pos + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (left > right || left > j || right < i) return MP(-1, -1);
    if (left >= i && right <= j) {
        return arvore[pos];
    }
    int mid = (left + right) / 2;
    return max(query(2 * pos, left, mid, i, j),
               query(2 * pos + 1, mid + 1, right, i, j));
}
int main() {
    while (scanf("%d %d", &n, &q) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%d", &vetor[i]);
        build(1, 1, n);
        while (q--) {
            char op;
            scanf(" %c", &op);
            if (op == 'A') {
                int i, j, val;
                scanf("%d %d %d", &i, &j, &val);
                update(1, 1, n, val, i, j);
            } else {
                int i, j;
                scanf("%d %d", &i, &j);
                printf("%d\n", -query(1, 1, n, i, j).second);
            }
        }
    }
    return 0;
}
