// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2558
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MP make_pair
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int MAXN = 101;
const int MAXL = 11;
const int INF = 1e9 + 10;
char matriz[MAXN][MAXN];
int posx[MAXL], posy[MAXL];
int dist[MAXL][MAXL];
int S[MAXN][MAXN];
int resp;
int N, M, W, H;
inline int valido(int x, int y) {
    return x >= 0 && y >= 0 && x < H && y < W && matriz[x][y] != '#';
}
int check(vector<int> vetorzao) {
    if (vetorzao.size() == 0) return dist[0][N + 1];
    int percorrido = 0;
    if (dist[0][vetorzao[0]] == INF) return INF;
    if (dist[vetorzao[vetorzao.size() - 1]][N + 1] == INF) return INF;
    for (int i = 0; i + 1 < vetorzao.size(); i++) {
        if (dist[vetorzao[i]][vetorzao[i + 1]] == INF) return INF;
        percorrido += dist[vetorzao[i]][vetorzao[i + 1]];
    }
    return dist[0][vetorzao[0]] + percorrido +
           dist[vetorzao[vetorzao.size() - 1]][N + 1];
}
void func(int bitmask) {
    vector<int> davez;
    for (int i = 0; i < N; i++)
        if (bitmask & (1 << i)) davez.push_back(i + 1);
    if (davez.size() == 0 && check(davez) <= M) resp = max(resp, 0);
    if (davez.size() <= resp) return;
    do {
        if (check(davez) <= M) {
            resp = max((int)davez.size(), resp);
            return;
        }
    } while (next_permutation(davez.begin(), davez.end()));
}
int main() {
    while (scanf("%d %d", &N, &M) != EOF) {
        int davez = 0;
        resp = -1;
        scanf("%d %d", &W, &H);
        for (int i = 0; i < H; i++) {
            scanf("%s", matriz[i]);
            for (int j = 0; j < W; j++) {
                if (matriz[i][j] == 'S') {
                    posx[0] = i;
                    posy[0] = j;
                } else if (matriz[i][j] == 'R') {
                    posx[N + 1] = i;
                    posy[N + 1] = j;
                } else if (matriz[i][j] == '*') {
                    posx[++davez] = i;
                    posy[davez] = j;
                }
            }
        }
        for (int vez = 0; vez <= N + 1; vez++) {
            for (int i = 0; i <= N + 1; i++) dist[vez][i] = INF;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    S[i][j] = INF;
                }
            }
            queue<iii> bfs;
            bfs.push(MP(0, MP(posx[vez], posy[vez])));
            while (!bfs.empty()) {
                iii temp = bfs.front();
                bfs.pop();
                int x = temp.second.first, y = temp.second.second,
                    percorrido = temp.first;
                if (S[x][y] <= percorrido) continue;
                S[x][y] = percorrido;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (valido(nx, ny))
                        bfs.push(MP(percorrido + 1, MP(nx, ny)));
                }
            }
            for (int novovez = 0; novovez <= N + 1; novovez++)
                dist[vez][novovez] = S[posx[novovez]][posy[novovez]];
        }
        for (int i = 0; i < (1 << N); i++) {
            func(i);
        }
        printf("%d\n", resp);
    }
    return 0;
}
