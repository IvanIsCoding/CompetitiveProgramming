// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2345
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int pos1 = abs(a + b - c - d);
    pos1 = min(pos1, abs(a + c - b - d));
    pos1 = min(pos1, abs(a + d - b - c));
    pos1 = min(pos1, abs(b + d - a - c));
    pos1 = min(pos1, abs(b + c - a - d));
    pos1 = min(pos1, abs(c + d - a - b));
    printf("%d\n", pos1);
    return 0;
}
