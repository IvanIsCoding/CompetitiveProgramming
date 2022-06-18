// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2116
#include <cmath>
#include <cstdio>
bool prime(int n) {
    if (n == 2) {
        return true;
    }
    if (n <= 1 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n + 1) + 1; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    while (true) {
        if (prime(x)) break;
        x--;
    }
    while (true) {
        if (prime(y)) break;
        y--;
    }
    printf("%d\n", x * y);
    return 0;
}
