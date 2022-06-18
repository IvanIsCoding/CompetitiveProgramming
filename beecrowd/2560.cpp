// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2560
#include <algorithm>
#include <cstdio>
#include <deque>
#define MP make_pair
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 2 * (1e5) + 1;
int vetor[MAXN], n, b;
int main() {
    while (scanf("%d %d", &n, &b) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%d", &vetor[i]);
        long long score = 0;
        int soma = 0;
        deque<ii> maximo, minimo;
        for (int i = 1; i <= b; i++) {
            soma += vetor[i];
            while (!maximo.empty() && maximo.back().second <= vetor[i])
                maximo.pop_back();
            while (!minimo.empty() && minimo.back().second >= vetor[i])
                minimo.pop_back();
            minimo.push_back(MP(i, vetor[i]));
            maximo.push_back(MP(i, vetor[i]));
        }
        // printf("%d %d
        // %d\n",soma,maximo.front().second,minimo.front().second);
        int davez = soma - maximo.front().second - minimo.front().second;
        score += (long long)davez;
        for (int i = b + 1; i <= n; i++) {
            soma -= vetor[i - b];
            soma += vetor[i];
            if (maximo.front().first == i - b) maximo.pop_front();
            if (minimo.front().first == i - b) minimo.pop_front();
            while (!maximo.empty() && maximo.back().second <= vetor[i])
                maximo.pop_back();
            while (!minimo.empty() && minimo.back().second >= vetor[i])
                minimo.pop_back();
            minimo.push_back(MP(i, vetor[i]));
            maximo.push_back(MP(i, vetor[i]));
            davez = soma - maximo.front().second - minimo.front().second;
            score += (long long)davez;
        }
        printf("%lld\n", score);
    }
    return 0;
}
