// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2655
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
set<int> cjt[51];
int vetor[MAXN], N, Q, M;
int main() {
    scanf("%d %d %d", &N, &Q, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &vetor[i]);
        cjt[vetor[i]].insert(i);
    }
    while (Q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            int resp = 0;
            for (int i = 1; i <= M; i++) {
                auto it = cjt[i].lower_bound(l);
                if (it == cjt[i].end()) {
                    continue;
                }
                if (*it <= r) resp++;
            }
            printf("%d\n", resp);
        }
        if (op == 2) {
            cjt[vetor[l]].erase(l);
            vetor[l] = r;
            cjt[vetor[l]].insert(l);
        }
    }
    return 0;
}
