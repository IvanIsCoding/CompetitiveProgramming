// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2380
#include <cstdio>
#define MAXN 100100
int n, k;
int pai[MAXN], peso[MAXN];
inline int find(int x) {
    while (x != pai[x]) x = pai[x];
    return x;
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (peso[x] > peso[y]) pai[y] = x;
    if (peso[x] < peso[y])
        pai[x] = y;
    else {
        peso[x]++;
        pai[y] = x;
    }
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) pai[i] = i;
    char op;
    int banco1, banco2;
    for (int i = 1; i <= k; i++) {
        scanf(" %c %d %d", &op, &banco1, &banco2);
        if (op == 'F')
            join(banco1, banco2);
        else if (find(banco1) == find(banco2))
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}
