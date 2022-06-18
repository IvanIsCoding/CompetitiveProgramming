// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2781
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

int vetor[MAXN], somatorio1, somatorio2, N, M;

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        vetor[a] += b;
        vetor[c] -= b;
        somatorio1 += b;
    }

    for (int i = 1; i <= N; i++) somatorio2 += abs(vetor[i]);
    somatorio2 /= 2;

    if (somatorio1 == somatorio2) {
        printf("N\n");
        printf("%d\n", somatorio2);
    } else {
        printf("S\n");
        printf("%d\n", somatorio2);
    }

    return 0;
}