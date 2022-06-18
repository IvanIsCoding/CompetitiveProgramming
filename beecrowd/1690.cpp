// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1690
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n;
        scanf("%d", &n);
        vector<long long> vetor;
        long long resp = 1;
        for (int i = 0; i < n; i++) {
            long long davez;
            scanf("%lld", &davez);
            vetor.push_back(davez);
        }
        sort(vetor.begin(), vetor.end());
        for (int i = 0; i < n; i++) {
            if (vetor[i] > resp) break;
            resp += vetor[i];
        }
        printf("%lld\n", resp);
    }
    return 0;
}
