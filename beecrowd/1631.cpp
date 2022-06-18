// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1631
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
double X[1000], Y[1000];
int main() {
    while (scanf("%d", &n) && n) {
        double resp = 1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf", &X[i], &Y[i]);
        }
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                double a = Y[i] - Y[j];
                double b = X[i] - X[j];
                double c = X[i] * Y[j] - Y[i] * X[j];
                double divisor = sqrt(a * a + b * b);
                double somal = 0.0, somar = 0.0;
                for (int k = 1; k <= n; k++) {
                    if (a * X[k] - b * Y[k] + c > 0) {
                        somal += abs(a * X[k] - b * Y[k] + c) / divisor;
                    }
                    if (a * X[k] - b * Y[k] + c < 0) {
                        somar += abs(a * X[k] - b * Y[k] + c) / divisor;
                    }
                }
                resp = min(abs(somal - somar), resp);
            }
        }
        printf("%.3lf\n", resp);
    }
    return 0;
}
