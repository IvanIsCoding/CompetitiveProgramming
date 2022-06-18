// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2155
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const double EPS = 1e-5;
vector<int> resposta;
double menor;
int TC, X[10], Y[10];
int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        menor = 1e9;
        scanf("%d %d", &X[4], &Y[4]);
        vector<int> brute;
        for (int i = 1; i <= 6; i++) {
            int x, y, id;
            scanf("%d %d %d", &id, &x, &y);
            X[id] = x;
            Y[id] = y;
        }
        brute.push_back(1);
        brute.push_back(2);
        brute.push_back(3);
        brute.push_back(5);
        brute.push_back(6);
        brute.push_back(7);
        do {
            double temp = hypot(X[4] - X[brute[0]], Y[4] - Y[brute[0]]) +
                          hypot(X[4] - X[brute[5]], Y[4] - Y[brute[5]]);
            for (int i = 0; i + 1 < 6; i++) {
                temp += hypot(X[brute[i]] - X[brute[i + 1]],
                              Y[brute[i]] - Y[brute[i + 1]]);
            }
            if (temp + EPS <= menor) {
                menor = temp;
                resposta = brute;
            } else if (fabs(temp - menor) < EPS) {
                if (brute < resposta) {
                    resposta = brute;
                }
            }
            // printf("4->");
            // for(int i=0;i<6;i++){
            //	printf("%d->",brute[i]);
            // }
            // printf("4: %.5lf\n",temp);
        } while (next_permutation(brute.begin(), brute.end()));
        printf("Caso %d:\n", tc);
        printf("4->");
        for (int i = 0; i < 6; i++) {
            printf("%d->", resposta[i]);
        }
        printf("4: %.5lf\n", menor);
    }
    return 0;
}
