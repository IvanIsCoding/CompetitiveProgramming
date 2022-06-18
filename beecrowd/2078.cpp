// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2078
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 200110
#define LSOne(S) (S & (-S))
using namespace std;
int bit[MAXN], resposta[MAXN], n, d;
void update(int pos, int val) {
    while (pos < MAXN) {
        bit[pos] += val;
        pos += LSOne(pos);
    }
}
int sum(int pos) {
    pos = min(pos, MAXN - 1);
    if (pos <= 0) return 0;
    int answer = 0;
    while (pos > 0) {
        answer += bit[pos];
        pos -= LSOne(pos);
    }
    return answer;
}
int query(int a, int b) { return sum(b) - sum(a - 1); }
struct point {
    int x, y, id;
};
bool comp(point A, point B) {
    if (A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &n, &d);
        memset(bit, 0, sizeof(bit));
        vector<point> vetorzao;
        for (int i = 0; i < n; i++) {
            point davez;
            int xi, yi;
            scanf("%d %d", &xi, &yi);
            // giramos 45 graus e fazemos a translacao no x para nao ficar
            // negativo e no y para nao ficar nulo
            davez.x = xi - yi + 100010;
            davez.y = xi + yi + 1;
            davez.id = i;
            vetorzao.push_back(davez);
        }
        sort(vetorzao.begin(), vetorzao.end(), comp);
        int ini = 0, fim = 0;
        for (int i = 0; i < n; i++) {
            while (ini < i && vetorzao[i].x - vetorzao[ini].x > d) {
                update(vetorzao[ini++].y, -1);
            }
            while (fim < n && vetorzao[fim].x - vetorzao[i].x <= d) {
                update(vetorzao[fim++].y, 1);
            }
            resposta[vetorzao[i].id] =
                query(vetorzao[i].y - d, vetorzao[i].y + d);
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", resposta[i] - 1);
        }
        printf("\n");
    }
    return 0;
}
