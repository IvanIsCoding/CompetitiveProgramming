// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2463
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n, m1 = 0, m2 = 0, d;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &d);
        m1 = max(0, m1 + d);
        m2 = max(m1, m2);
    }
    printf("%d\n", m2);
    return 0;
}
