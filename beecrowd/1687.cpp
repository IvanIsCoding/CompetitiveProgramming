// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1687
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 236
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MOD = 1300031;
int n, ordem, k, contador, conversao[MAXN][MAXN], X[MAXN], Y[MAXN];
struct Matrix {
    ll mat[MAXN][MAXN];
};
Matrix base, identidade;
inline void addLine(int A, int B) {
    ll cof1 = Y[A] - Y[B];
    ll cof2 = X[A] - X[B];
    cof2 *= -1;
    ll cof3 = X[A] * Y[B] - X[B] * Y[A];
    vector<ii> vetorzao;
    for (int i = 0; i < contador; i++) {
        if (cof1 * X[i] + cof2 * Y[i] + cof3 == 0) {
            vetorzao.push_back(make_pair(X[i], Y[i]));
        }
    }
    sort(vetorzao.begin(), vetorzao.end());
    for (int i = 0; i < vetorzao.size(); i++) {
        if (i - 1 >= 0) {
            int x1 = vetorzao[i - 1].first, x2 = vetorzao[i].first;
            int y1 = vetorzao[i - 1].second, y2 = vetorzao[i].second;
            int id1 = conversao[x1][y1];
            int id2 = conversao[x2][y2];
            base.mat[id1][id2] = 1;
            base.mat[id2][id1] = 1;
        }
        if (i + 1 < vetorzao.size()) {
            int x1 = vetorzao[i + 1].first, x2 = vetorzao[i].first;
            int y1 = vetorzao[i + 1].second, y2 = vetorzao[i].second;
            int id1 = conversao[x1][y1];
            int id2 = conversao[x2][y2];
            base.mat[id1][id2] = 1;
            base.mat[id2][id1] = 1;
        }
    }
}
inline Matrix matMul(Matrix a, Matrix b) {  // O(n^3), but O(1) as n = 2
    Matrix ans;
    int i, j, k;
    for (i = 0; i < ordem; i++)
        for (j = 0; j < ordem; j++)
            for (ans.mat[i][j] = k = 0; k < ordem; k++) {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
            }
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            ans.mat[i][j] %= MOD;
        }
    }
    return ans;
}

inline Matrix matPow(int p) {  // O(n^3 log p), but O(log p) as n = 2
    Matrix ans;
    int i, j;
    for (i = 0; i < ordem; i++)
        for (j = 0; j < ordem; j++)
            ans.mat[i][j] = (i == j);  // prepare identity matrix
    while (p) {     // iterative version of Divide & Conquer exponentiation
        if (p & 1)  // check if p is odd (the last bit is on)
            ans = matMul(ans, base);  // update ans
        base = matMul(base, base);    // square the base
        p >>= 1;                      // divide p by 2
    }
    return ans;
}
int main() {
    while (scanf("%d %d", &n, &k) && (n || k)) {
        contador = 0;
        ordem = n * n;
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                base.mat[i][j] = 0;
                identidade.mat[i][j] = (i == j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                X[contador] = i;
                Y[contador] = j;
                conversao[X[contador]][Y[contador]] = contador;
                contador++;
            }
        }
        for (int i = 0; i < contador; i++) {
            for (int j = i + 1; j < contador; j++) {
                addLine(i, j);
            }
        }
        Matrix resposta = matPow(k - 1);
        ll soma = 0;
        for (int i = 0; i < ordem; i++) {
            for (ll j = 0; j < ordem; j++) {
                soma += resposta.mat[i][j];
                soma %= MOD;
            }
        }
        printf("%lld\n", soma);
    }
    return 0;
}
