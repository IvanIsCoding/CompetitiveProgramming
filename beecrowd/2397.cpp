// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2397
#include <algorithm>
#include <cstdio>
using namespace std;
#define desigugalde(A, B, C) ((A + B) > (C))
int main() {
    int a, b, c, x, y, z;
    scanf("%d %d %d", &a, &b, &c);
    if (!desigugalde(a, b, c) || !desigugalde(b, c, a) ||
        !desigugalde(c, a, b)) {
        printf("n\n");
        return 0;
    }
    x = max(a, max(b, c));
    y = min(a, min(b, c));
    z = a + b + c - x - y;
    x *= x;
    y *= y;
    z *= z;
    if (x == y + z)
        printf("r\n");
    else if (x > y + z)
        printf("o\n");
    else
        printf("a\n");
    return 0;
}
