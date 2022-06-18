// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2285
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 2010
using namespace std;
int dp[MAXN], palindrome[MAXN][MAXN], tam, teste;
char entrada[MAXN];
int solve_palindrome(int ini, int fim) {
    if (ini > fim) return 0;
    if (palindrome[ini][fim] != -1) return palindrome[ini][fim];
    if (ini == fim) {
        return palindrome[ini][fim] = 1;
    }
    if (ini + 1 == fim) {
        if (entrada[ini] == entrada[ini + 1]) return palindrome[ini][fim] = 1;
        return palindrome[ini][fim] = 0;
    }
    if (entrada[ini] == entrada[fim] && solve_palindrome(ini + 1, fim - 1))
        return palindrome[ini][fim] = 1;
    return palindrome[ini][fim] = 0;
}
int main() {
    while (scanf("%d", &tam) && tam) {
        scanf("%s", entrada);
        memset(palindrome, -1, sizeof(palindrome));
        memset(dp, 0, sizeof(dp));
        for (int i = tam; i >= 1; i--) {
            entrada[i] = entrada[i - 1];
        }
        for (int i = 1; i <= tam; i++) {
            dp[i] = MAXN;
            for (int j = 0; j < tam; j++) {
                if (solve_palindrome(j + 1, i)) {
                    dp[i] = min(dp[j] + solve_palindrome(j + 1, i), dp[i]);
                }
            }
        }
        printf("Teste %d\n%d\n\n", ++teste, dp[tam]);
    }
    return 0;
}
