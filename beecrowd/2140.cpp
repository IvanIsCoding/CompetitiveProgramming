// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2140
#include <cstdio>
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        int troco = m - n;
        if (troco == 7 || troco == 12 || troco == 22 || troco == 52 ||
            troco == 102 || troco == 15 || troco == 25 || troco == 55 ||
            troco == 105 || troco == 30 || troco == 60 || troco == 110 ||
            troco == 70 || troco == 120 || troco == 150)
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}
