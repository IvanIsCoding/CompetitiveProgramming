// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1594
#include <cstdio>
#include <deque>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 1;
ll vetor[MAXN], arvore[4 * MAXN], soma;
int N, K, TC;
int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d %lld", &N, &K, &vetor[1]);
        for (int i = 2; i <= N; i++) {
            vetor[i] = (vetor[i - 1] * 1103515245 + 12345) % (2147483648LL);
            // printf("%lld\n",vetor[i]);
        }
        deque<int> janela;
        janela.push_back(1);
        for (int i = 2; i <= K; i++) {
            while (!janela.empty() && vetor[i] >= vetor[janela.back()])
                janela.pop_back();
            janela.push_back(i);
        }
        soma = vetor[janela.front()];
        for (int i = K + 1; i <= N; i++) {
            while (!janela.empty() && vetor[i] >= vetor[janela.back()])
                janela.pop_back();
            janela.push_back(i);
            if (janela.front() + K <= i) janela.pop_front();
            soma += vetor[janela.front()];
        }
        printf("%lld\n", soma);
    }
    return 0;
}
