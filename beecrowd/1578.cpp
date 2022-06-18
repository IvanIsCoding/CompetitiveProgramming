// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/1578
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
typedef unsigned long long llu;
#define endl '\n'
#define MAXN 25
#define max(A, B) (A > B) ? (A) : (B)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int casos;
    cin >> casos;
    for (int davez = 4; davez < casos + 4; davez++) {
        if (davez != 4) cout << endl;
        int ordem;
        cin >> ordem;
        cout << "Quadrado da matriz #" << davez << ":\n";
        llu matriz[MAXN][MAXN], digitos[MAXN];
        for (int i = 0; i < ordem; i++) digitos[i] = 1LL;
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                cin >> matriz[i][j];
                matriz[i][j] *= matriz[i][j];
                if (matriz[i][j])
                    digitos[j] = max(digitos[j], llu(log10(matriz[i][j])) + 1);
            }
        }
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                if (j == 0)
                    cout << setw(digitos[j]) << matriz[i][j];
                else
                    cout << " " << setw(digitos[j]) << matriz[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
