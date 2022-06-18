// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2461
#include <cstdio>
#include <set>
using namespace std;
int main() {
    set<int> conjuntoa, conjuntob;
    set<int>::iterator it;
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++) {
        int davez;
        scanf("%d", &davez);
        conjuntoa.insert(davez);
    }
    for (int i = 0; i < b; i++) {
        int davez;
        scanf("%d", &davez);
        if (conjuntoa.count(davez)) {
            conjuntob.insert(davez);
            continue;
        }
        bool verdade = true;
        for (it = conjuntob.begin(); it != conjuntob.end(); it++) {
            if (conjuntob.count(davez - *it)) {
                conjuntob.insert(davez);
                verdade = false;
                break;
            }
        }
        if (verdade) {
            printf("%d\n", davez);
            return 0;
        }
    }
    printf("sim\n");
    return 0;
}
