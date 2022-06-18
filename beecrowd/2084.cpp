// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2084
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> candidatos;
int total, n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int davez;
        scanf("%d", &davez);
        total += davez;
        candidatos.push_back(davez);
    }
    sort(candidatos.begin(), candidatos.end());
    int nosso = candidatos[n - 1];
    candidatos.pop_back();
    if (100 * nosso >= 45 * total) {
        printf("1\n");
        return 0;
    }
    if (100 * nosso >= 40 * total &&
        10 * (nosso - candidatos[n - 2]) >= total) {
        printf("1\n");
        return 0;
    }
    printf("2\n");
    return 0;
}
