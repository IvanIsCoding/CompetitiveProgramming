// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2531
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 1e5 + 10;
const ii NULO = MP(MAXN, -MAXN);
int vetor[MAXN], n, q;
ii arvore[4 * MAXN];
ii join(ii A, ii B) {
    return MP(min(A.first, B.first), max(A.second, B.second));
}
void build(int pos, int left, int right) {
    if (left == right) {
        arvore[pos] = MP(vetor[left], vetor[left]);
        return;
    }
    int mid = (left + right) / 2;
    build(2 * pos, left, mid);
    build(2 * pos + 1, mid + 1, right);
    arvore[pos] = join(arvore[2 * pos], arvore[2 * pos + 1]);
}
void update(int pos, int left, int right, int x, int val) {
    if (left > right || left > x || right < x) {
        return;
    }
    if (left == right) {
        vetor[left] = val;
        arvore[pos] = MP(vetor[left], vetor[left]);
        return;
    }
    int mid = (left + right) / 2;
    update(2 * pos, left, mid, x, val);
    update(2 * pos + 1, mid + 1, right, x, val);
    arvore[pos] = join(arvore[2 * pos], arvore[2 * pos + 1]);
}
ii query(int pos, int left, int right, int i, int j) {
    if (left > right || left > j || right < i) {
        return NULO;
    }
    if (left >= i && right <= j) {
        return arvore[pos];
    }
    int mid = (left + right) / 2;
    return join(query(2 * pos, left, mid, i, j),
                query(2 * pos + 1, mid + 1, right, i, j));
}
int calcula(ii A) { return A.second - A.first; }
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vetor[i]);
        }
        build(1, 1, n);
        scanf("%d", &q);
        while (q--) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int i, p;
                scanf("%d %d", &i, &p);
                update(1, 1, n, i, p);
            } else {
                int i, j;
                scanf("%d %d", &i, &j);
                printf("%d\n", calcula(query(1, 1, n, i, j)));
            }
        }
    }
    return 0;
}
