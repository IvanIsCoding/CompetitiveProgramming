// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2884
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int ligados, luzes[MAXN], N, M;
vector<int> processo[MAXN];

void toggle(int j) {
    if (luzes[j])
        ligados--;
    else
        ligados++;
    luzes[j] ^= 1;
}

void processa(int i) {
    for (int j : processo[(i - 1) % N]) {
        toggle(j);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    int qtd;
    cin >> qtd;
    for (int i = 1; i <= qtd; i++) {
        int x;
        cin >> x;
        toggle(x);
    }

    for (int i = 1; i <= N; i++) {
        int qtt;
        cin >> qtt;
        while (qtt--) {
            int x;
            cin >> x;
            processo[i - 1].push_back(x);
        }
    }

    for (int i = 1; i <= 2 * N; i++) {
        processa(i);
        if (ligados == 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
