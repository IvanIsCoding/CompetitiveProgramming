// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2298
#include <algorithm>
#include <cstdio>
#include <vector>
#define PB push_back
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        int pontuacao = 0;
        vector<int> cartas;
        for (int i = 0; i <= 14; i++) cartas.PB(0);
        for (int i = 0; i < 5; i++) {
            int davez;
            scanf("%d", &davez);
            cartas[davez]++;
        }
        for (int i = 1; i <= 13; i++)
            if (cartas[i] == 2) pontuacao = max(i, pontuacao);
        for (int i = 1; i <= 13; i++) {
            if (cartas[i] != 2) continue;
            for (int j = i + 1; j <= 13; j++) {
                if (cartas[j] != 2) continue;
                for (int k = 1; k <= 13; k++) {
                    if (cartas[k] != 1) continue;
                    pontuacao = max(pontuacao, 3 * j + 2 * i + 20);
                }
            }
        }
        for (int i = 1; i <= 13; i++)
            if (cartas[i] == 3) pontuacao = max(pontuacao, 140 + i);
        for (int i = 1; i <= 13; i++) {
            if (cartas[i] != 3) continue;
            for (int j = 1; j <= 13; j++) {
                if (cartas[j] != 2) continue;
                pontuacao = max(pontuacao, 160 + i);
            }
        }
        for (int i = 1; i <= 13; i++)
            if (cartas[i] == 4) pontuacao = max(pontuacao, 180 + i);
        for (int i = 1; i <= 9; i++) {
            if (cartas[i] == 1 && cartas[i + 1] == 1 && cartas[i + 2] == 1 &&
                cartas[i + 3] == 1 && cartas[i + 4] == 1)
                pontuacao = max(pontuacao, 200 + i);
        }
        printf("Teste %d\n%d\n\n", caso, pontuacao);
    }
    return 0;
}
