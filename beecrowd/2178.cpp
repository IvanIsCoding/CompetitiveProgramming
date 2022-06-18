// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2178
#include <algorithm>
#include <cstdio>
using namespace std;
int voltas, a, p, n;
int main() {
    scanf("%d %d", &a, &p);
    while (a--) {
        int atual = 0, davez = 0;
        scanf("%d", &n);
        while (n--) {
            int agora;
            scanf("%d", &agora);
            if (agora < atual) davez++;
            atual = agora;
        }
        if (atual != 0) davez++;
        voltas = max(davez, voltas);
    }
    printf("%d\n", voltas);
    return 0;
}
