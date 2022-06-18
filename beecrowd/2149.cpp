// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2149
#include <cstdio>
int main() {
    long long int vetor[30] = {0,
                               1,
                               1,
                               1,
                               2,
                               2,
                               4,
                               8,
                               12,
                               96,
                               108,
                               10368,
                               10476,
                               108615168,
                               108625644,
                               11798392572168192,
                               11798392680793836};
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", vetor[n - 1]);
    }
    return 0;
}
