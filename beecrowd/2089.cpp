// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2089
#include <cstdio>
#include <unordered_map>
#define MAXN 100001
#define MAXM 1001
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
using namespace std;
unordered_map<int, int> dp[MAXN];
int vetor[MAXM], n, m;
int possivel(int soma, int davez) {
    if (soma == 0) return dp[soma][davez] = 1;
    if (soma < 0 || davez <= 0) return 0;
    if (dp[soma].count(davez)) return dp[soma][davez];
    return dp[soma][davez] = possivel(soma - vetor[davez], davez - 1) ||
                             possivel(soma, davez - 1);
}
int main() {
    while (true) {
        getint(n);
        getint(m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i <= n; i++) dp[i].clear();
        for (int i = 1; i <= m; i++) getint(vetor[i]);
        printf("%s\n", possivel(n, m) ? "sim" : "nao");
    }
    return 0;
}
