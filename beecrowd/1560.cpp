// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1560
#include <cstdio>
#define MAXN 201
typedef int ll;
ll X[MAXN], Y[MAXN];
int n, m, resp;
inline ll ccw(int A, int B, int C) {
    ll val =
        X[A] * (Y[B] - Y[C]) - Y[A] * (X[B] - X[C]) + X[B] * Y[C] - X[C] * Y[B];
    if (val < 0) val *= -1;
    return val;
}
void addTriangle(int A, int B, int C) {
    int pontos = 0;
    for (int i = n + 1; i <= n + m; i++) {
        ll area = ccw(A, B, C);
        ll temp1 = ccw(i, B, C);
        ll temp2 = ccw(i, A, B);
        ll temp3 = ccw(i, A, C);
        if (area == temp1 + temp2 + temp3) {
            pontos++;
        }
    }
    resp += pontos * pontos;
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        resp = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &X[i], &Y[i]);
        }
        for (int i = n + 1; i <= n + m; i++) {
            scanf("%d %d", &X[i], &Y[i]);
        }
        for (int i = 1; i + 2 <= n; i++) {
            for (int j = i + 1; j + 1 <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    addTriangle(i, j, k);
                }
            }
        }
        printf("%d\n", resp);
    }
    return 0;
}
