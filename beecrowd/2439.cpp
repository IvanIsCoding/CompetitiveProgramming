// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2439
#include <algorithm>
#include <cstdio>
#define REP(A, B) for (long long A = 0; A < B; A++)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAXK = 2;
typedef struct matrix {
    ll mat[MAXK][MAXK];
} matrix;
matrix base, identidade;
matrix multiplication(matrix A, matrix B) {
    matrix C;
    REP(i, MAXK) REP(j, MAXK) C.mat[i][j] = 0;
    REP(i, MAXK)
    REP(j, MAXK)
    REP(k, MAXK) C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
    return C;
}
matrix exponentiation(ll expo) {
    if (expo == 0) return identidade;
    if (expo == 1) return base;
    if (expo % 2 == 0) {
        matrix temp = exponentiation(expo / 2);
        return multiplication(temp, temp);
    }
    return multiplication(base, exponentiation(expo - 1));
}
int main() {
    ll n;
    scanf("%lld", &n);
    if (n == 1) {
        printf("12\n");
        return 0;
    }
    if (n == 2) {
        printf("54\n");
        return 0;
    }
    REP(i, MAXK) REP(j, MAXK) identidade.mat[i][j] = (i == j);
    base.mat[0][0] = 0;
    base.mat[0][1] = 1;
    base.mat[1][0] = -2;
    base.mat[1][1] = 5;
    matrix t = exponentiation(n - 1);
    ll resp = (t.mat[0][0] * 12 + t.mat[0][1] * 54) % MOD;
    resp = (resp + MOD) % MOD;
    printf("%lld\n", resp);
    return 0;
}
