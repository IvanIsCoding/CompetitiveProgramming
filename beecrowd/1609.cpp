// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1609
#include <cstdio>
#include <set>
using namespace std;
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        set<int> carneiros;
        int n;
        scanf("%d", &n);
        while (n--) {
            int davez;
            scanf("%d", &davez);
            carneiros.insert(davez);
        }
        printf("%d\n", (int)carneiros.size());
    }
    return 0;
}
