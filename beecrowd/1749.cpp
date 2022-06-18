// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1749
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define MP make_pair
#define PB push_back
#define X second
#define Y first
using namespace std;
const int MAXN = 5 * (1e4 + 1);
typedef pair<int, int> point;
map<point, int> conversao;
set<point> conjunto;
vector<point> pontos;
vector<int> grafo[MAXN];
int cor[MAXN], qtd[2], resp, n;
bool comp(point A, point B) {
    if (A.X == B.X) return A.Y < B.Y;
    return A.X < B.X;
}
int main() {
    memset(cor, -1, sizeof(cor));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        point davez;
        scanf("%d %d", &davez.X, &davez.Y);
        conversao[davez] = i;
        pontos.PB(davez);
    }
    sort(pontos.begin(), pontos.end(), comp);
    int ini = 0;
    for (int i = 0; i < n; i++) {
        point davez = pontos[i];
        int id = conversao[davez];
        while (ini < i && davez.X - pontos[ini].X > 5) {
            conjunto.erase(pontos[ini++]);
        }
        for (set<point>::iterator it =
                 conjunto.lower_bound(MP(davez.Y - 5, davez.X - 5));
             it != conjunto.upper_bound(MP(davez.Y + 5, davez.X + 5)); it++) {
            point candidato = (*it);
            int cid = conversao[candidato];
            long long delta1 = (long long)candidato.X - davez.X;
            long long delta2 = (long long)candidato.Y - davez.Y;
            long long dist = delta1 * delta1 + delta2 * delta2;
            if (dist <= 25) {
                grafo[cid].PB(id);
                grafo[id].PB(cid);
            }
        }
        conjunto.insert(davez);
    }
    for (int i = 1; i <= n; i++) {
        if (cor[i] == -1) {
            cor[i] = 1;
            qtd[0] = 0;
            qtd[1] = 1;
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty()) {
                int v = bfs.front();
                bfs.pop();
                for (int j = 0; j < grafo[v].size(); j++) {
                    int u = grafo[v][j];
                    if (cor[u] == -1) {
                        cor[u] = 1 - cor[v];
                        qtd[cor[u]]++;
                        bfs.push(u);
                    }
                }
            }
            resp += min(qtd[0], qtd[1]);
        }
    }
    printf("%d\n", resp);
    return 0;
}
