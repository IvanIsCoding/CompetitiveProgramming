// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1583
#include <cstdio>
#include <stack>
#define MAXN 60
using namespace std;
typedef pair<int, int> ii;
int n, m;
char matriz[MAXN][MAXN];
void dfs(int a, int b) {
    if (a < 0 || b < 0 || a >= n || b >= m || matriz[a][b] != 'A') return;
    matriz[a][b] = 'T';
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
}
int main() {
    while (scanf("%d %d", &n, &m) && (n || m)) {
        stack<ii> pilha;
        for (int i = 0; i < n; i++) scanf("%s", matriz[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (matriz[i][j] == 'T') pilha.push(make_pair(i, j));
            }
        while (!pilha.empty()) {
            ii davez = pilha.top();
            pilha.pop();
            matriz[davez.first][davez.second] = 'A';
            dfs(davez.first, davez.second);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
