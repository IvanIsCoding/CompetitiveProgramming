// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2665
#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
int area(point P1, point P2, point P3) {
    return abs(P1.x * (P2.y - P3.y) - P1.y * (P2.x - P3.x) + P2.x * P3.y -
               P2.y * P3.x);
}
int inside(point P, point V1, point V2, point V3) {
    return area(V1, V2, V3) ==
           area(P, V1, V2) + area(P, V1, V3) + area(P, V2, V3);
}
point P[110], A, B;
int dp[110], n, resp;
int solve(int q) {
    if (dp[q] != -1) return dp[q];
    int ret = 1;
    for (int r = 1; r <= n; r++) {
        if (r == q) continue;
        if (inside(P[r], A, B, P[q])) ret = max(ret, solve(r) + 1);
    }
    return dp[q] = ret;
}
int main() {
    scanf("%d %d %d", &n, &A.x, &B.x);
    A.y = B.y = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        scanf("%d %d", &P[i].x, &P[i].y);
    }
    for (int i = 1; i <= n; i++) resp = max(resp, solve(i));
    printf("%d\n", resp);
    return 0;
}
