// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2444
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int v, t;
    scanf("%d %d", &v, &t);
    while (t--) {
        int a;
        scanf("%d", &a);
        v = min(100, max(v + a, 0));
    }
    printf("%d\n", v);
    return 0;
}
