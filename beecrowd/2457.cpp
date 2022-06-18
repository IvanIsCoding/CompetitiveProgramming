// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2457
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int i, contem = 0, total = 0, valido = 1;
    char letra;
    string texto;
    cin >> letra;
    cin.ignore();
    getline(cin, texto);
    int tamanho = texto.length();
    for (i = 0; i <= tamanho; i++) {
        char caractere = texto[i];
        if (caractere == '\0') {
            total++;
            break;
        } else if (caractere == letra && valido == 1) {
            contem++;
            valido = 0;
        } else if (caractere == ' ') {
            total++;
            valido = 1;
        }
    }
    printf("%.1lf\n", (100.0 * contem) / (1.0 * total));
    return 0;
}
