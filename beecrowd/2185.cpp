// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2185
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
int arvore[4 * MAXN], lazy[4 * MAXN], vetor[MAXN];
void build(int pos, int left, int right) {
    if (left == right) {
        arvore[pos] = vetor[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * pos, left, mid);
    build(2 * pos + 1, mid + 1, right);
    arvore[pos] = arvore[2 * pos] ^ arvore[2 * pos + 1];
}
void update(int pos, int left, int right, int i, int j, int val) {
    if (lazy[pos] != -1) {
        if ((right - left + 1) % 2 == 0) {
            arvore[pos] = 0;
        } else {
            arvore[pos] = lazy[pos];
        }
        if (left != right) {
            lazy[2 * pos] = lazy[pos];
            lazy[2 * pos + 1] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if (left > right || left > j || right < i) return;
    if (left >= i && right <= j) {
        if ((right - left + 1) % 2 == 0) {
            arvore[pos] = 0;
        } else {
            arvore[pos] = val;
        }
        if (left != right) {
            lazy[2 * pos] = val;
            lazy[2 * pos + 1] = val;
        }
        return;
    }
    int mid = (left + right) / 2;
    update(2 * pos, left, mid, i, j, val);
    update(2 * pos + 1, mid + 1, right, i, j, val);
    arvore[pos] = arvore[2 * pos] ^ arvore[2 * pos + 1];
}
int main() {
    memset(lazy, -1, sizeof(lazy));
    int n, m;
    getint(n);
    getint(m);
    for (int i = 1; i <= n; i++) getint(vetor[i]);
    build(1, 1, n);
    while (m--) {
        int a, b, c;
        getint(a);
        getint(b);
        getint(c);
        update(1, 1, n, a, b, c);
        if (arvore[1] == 0)
            printf("Impossivel\n");
        else
            printf("Possivel\n");
    }
    return 0;
}
