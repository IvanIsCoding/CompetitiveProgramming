// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2122
#include <algorithm>
#include <cstdio>
#include <vector>
#define gc getchar_unlocked
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}
using namespace std;
struct candidato {
    int id;
    vector<int> op;
};
int n, v, k;
candidato vetor[101];
bool comp(candidato A, candidato B) {
    for (int i = 0; i < A.op.size(); i++) {
        if (A.op[i] > B.op[i]) {
            return 1;
        }
        if (A.op[i] < B.op[i]) {
            return 0;
        }
    }
    return A.id < B.id;
}
int main() {
    while (scanf("%d %d %d", &n, &v, &k) != EOF) {
        for (int i = 0; i <= v; i++) {
            vetor[i].id = i;
            vetor[i].op.clear();
            vetor[i].op.assign(v + 1, 0);
        }
        while (n--) {
            int votos;
            getint(votos);
            for (int i = 1; i <= votos; i++) {
                int davez;
                getint(davez);
                if (davez > v || i > k) continue;
                vetor[davez].op[0]++;
                vetor[davez].op[i]++;
            }
        }
        // for(int i=1;i<=v;i++){
        //	printf("%d",i);
        //	for(int j=0;j<vetor[i].op.size();j++){
        //		printf(" %d",vetor[i].op[j]);
        //	}
        //	printf("\n");
        // }
        sort(vetor + 1, vetor + v + 1, comp);
        int iterador = 1;
        vector<int> utlimoop;
        int primeirao = 0;
        for (; iterador <= k; iterador++) {
            if (primeirao)
                printf(" ");
            else
                primeirao = 1;
            printf("%d", vetor[iterador].id);
            utlimoop = vetor[iterador].op;
        }
        while (iterador <= v && vetor[iterador].op == utlimoop) {
            if (primeirao)
                printf(" ");
            else
                primeirao = 1;
            printf("%d", vetor[iterador].id);
            iterador++;
        }
        printf("\n");
    }
    return 0;
}
