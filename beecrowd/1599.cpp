// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1599
#include <iostream>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, i, j;
    bool valido, possivel;
    while (cin >> n >> m) {
        int map[n][m];
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
        possivel = false;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                valido = true;
                if (i - 1 >= 0 && map[i][j] <= map[i - 1][j]) valido = false;
                if (j - 1 >= 0 && map[i][j] <= map[i][j - 1]) valido = false;
                if (i - 1 >= 0 && j - 1 >= 0 && map[i][j] <= map[i - 1][j - 1])
                    valido = false;
                if (i + 1 < n && map[i][j] <= map[i + 1][j]) valido = false;
                if (j + 1 < m && map[i][j] <= map[i][j + 1]) valido = false;
                if (i + 1 < n && j + 1 < m && map[i][j] <= map[i + 1][j + 1])
                    valido = false;
                if (i + 1 < n && j - 1 >= 0 && map[i][j] <= map[i + 1][j - 1])
                    valido = false;
                if (i - 1 >= 0 && j + 1 < m && map[i][j] <= map[i - 1][j + 1])
                    valido = false;
                if (valido) {
                    possivel = true;
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
        if (!possivel) cout << -1 << endl;
        cout << endl;
    }
    return 0;
}
