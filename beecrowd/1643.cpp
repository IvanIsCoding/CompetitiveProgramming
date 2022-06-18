// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1643
#include <cstdio>
#include <vector>
#define MAXIMUM 25001
using namespace std;
vector<int> fibs;
int main() {
    fibs.push_back(1);
    fibs.push_back(1);
    while (fibs.back() < MAXIMUM) {
        fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
    }
    fibs[0] = 0;
    int n, TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        int resp = 0;
        for (int i = fibs.size() - 1; i >= 2; i--) {
            int davez = fibs[i];
            resp += (n / davez) * fibs[i - 1];
            n %= davez;
        }
        printf("%d\n", resp);
    }
    return 0;
}
