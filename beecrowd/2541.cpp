// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2541
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
struct point {
    int x, y;
};
bool compara(point A, point B) {
    if (A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}
int ccw(point A, point B, point C) {
    int val = A.x * (B.y - C.y) - A.y * (B.x - C.x) + B.x * C.y - B.y * C.x;
    if (val > 0) return 1;
    if (val == 0) return 0;
    return -1;
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<point> pontos, CH(2 * n);
        double resp = 0;
        for (int i = 0; i < n; i++) {
            point davez;
            scanf("%d %d", &davez.x, &davez.y);
            pontos.push_back(davez);
        }
        sort(pontos.begin(), pontos.end(), compara);
        int k = 0;
        for (int i = 0; i < n; i++) {
            while (k >= 2 && ccw(CH[k - 2], CH[k - 1], pontos[i]) <= 0) k--;
            CH[k++] = pontos[i];
        }
        for (int i = n - 2, t = k + 1; i >= 0; i--) {
            while (k >= t && ccw(CH[k - 2], CH[k - 1], pontos[i]) <= 0) k--;
            CH[k++] = pontos[i];
        }
        CH.resize(k - 1);
        CH.push_back(CH[0]);
        for (int i = 0; i + 1 < CH.size(); i++)
            resp += CH[i].x * CH[i + 1].y - CH[i].y * CH[i + 1].x;
        printf("%.2lf\n", resp * 0.5);
    }
    return 0;
}
