// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2400
#include <cstdio>
#define MAXN 100010
#define MAXS 1000010
#define max(A, B) (A) > (B) ? (A) : (B)
#define LSOne(S) (S & (-S))
int MAX = 1000001, bits[MAXS], n, skill[MAXN], answer, maximum;
void update(int x) {
    while (x < 100005) {
        bits[x]++;
        x += LSOne(x);
    }
}
int sum(int x) {
    int s = 0;
    while (x > 0) {
        s += bits[x];
        x -= LSOne(x);
    }
    return s;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &skill[i]);
        maximum = max(maximum, skill[i]);
    }
    for (int i = 1; i <= n; i++) {
        update(skill[i]);
        answer += sum(maximum) - sum(skill[i]);
    }
    printf("%d\n", answer);
    return 0;
}
