// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1584
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
const ll MODULO = 1e9 + 7;
ll n, MAX_N, k, contador, conversao[26][26], X[26], Y[26];
struct Matrix {
    ll mat[26][26];
};
Matrix base, identidade;
void addLine(ll A, ll B) {
    ll cof1 = Y[A] - Y[B];
    ll cof2 = X[A] - X[B];
    cof2 *= -1;
    ll cof3 = X[A] * Y[B] - X[B] * Y[A];
    vector<ii> vetorzao;
    for (ll i = 0; i < contador; i++) {
        if (cof1 * X[i] + cof2 * Y[i] + cof3 == 0) {
            vetorzao.push_back(make_pair(X[i], Y[i]));
        }
    }
    sort(vetorzao.begin(), vetorzao.end());
    for (ll i = 0; i < vetorzao.size(); i++) {
        if (i - 1 >= 0) {
            ll x1 = vetorzao[i - 1].first, x2 = vetorzao[i].first;
            ll y1 = vetorzao[i - 1].second, y2 = vetorzao[i].second;
            ll id1 = conversao[x1][y1];
            ll id2 = conversao[x2][y2];
            base.mat[id1][id2] = 1;
            base.mat[id2][id1] = 1;
        }
        if (i + 1 < vetorzao.size()) {
            ll x1 = vetorzao[i + 1].first, x2 = vetorzao[i].first;
            ll y1 = vetorzao[i + 1].second, y2 = vetorzao[i].second;
            ll id1 = conversao[x1][y1];
            ll id2 = conversao[x2][y2];
            base.mat[id1][id2] = 1;
            base.mat[id2][id1] = 1;
        }
    }
}
inline Matrix multiplication(Matrix A, Matrix B) {
    Matrix C;
    for (ll i = 0; i < MAX_N; i++) {
        for (ll j = 0; j < MAX_N; j++) {
            C.mat[i][j] = 0;
            for (ll k = 0; k < MAX_N; k++) {
                C.mat[i][j] += (A.mat[i][k] * B.mat[k][j] % MODULO);
                C.mat[i][j] %= MODULO;
            }
        }
    }
    return C;
}
Matrix exponentiation(ll expo) {
    if (expo == 0) return identidade;
    if (expo == 1) return base;
    if (expo % 2 == 0) {
        Matrix temp = exponentiation(expo / 2);
        return multiplication(temp, temp);
    }
    return multiplication(base, exponentiation(expo - 1));
}
int main() {
    while (scanf("%lld %lld", &n, &k) != EOF) {
        contador = 0;
        MAX_N = n * n;
        for (ll i = 0; i < MAX_N; i++) {
            for (ll j = 0; j < MAX_N; j++) {
                base.mat[i][j] = 0;
                identidade.mat[i][j] = (i == j);
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                X[contador] = i;
                Y[contador] = j;
                conversao[X[contador]][Y[contador]] = contador;
                contador++;
            }
        }
        for (ll i = 0; i < contador; i++) {
            for (ll j = i + 1; j < contador; j++) {
                addLine(i, j);
            }
        }
        Matrix resposta = exponentiation(k);
        ll soma = 0;
        for (ll i = 0; i < MAX_N; i++) {
            for (ll j = 0; j < MAX_N; j++) {
                soma += resposta.mat[i][j];
                soma %= MODULO;
            }
        }
        printf("%lld\n", soma);
    }
    return 0;
}
