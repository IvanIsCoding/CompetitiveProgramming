// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2880
#include <bits/stdc++.h>
using namespace std;

string A, B;

int main() {
    int matches = 0;
    cin >> A >> B;
    int N = A.size(), M = B.size();

    for (int i = 0; i < N; i++) {
        if (i + M - 1 >= N) continue;
        int delta = 1;
        for (int j = 0; j < M; j++) {
            if (B[j] == A[i + j]) {
                delta = 0;
                break;
            }
        }
        matches += delta;
    }

    cout << matches << endl;

    return 0;
}
