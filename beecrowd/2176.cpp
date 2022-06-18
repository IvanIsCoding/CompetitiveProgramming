// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2176
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string entrada;
    cin >> entrada;
    int uns = 0;
    for (int i = 0; i < entrada.size(); i++) uns += (int)(entrada[i] == '1');
    cout << entrada;
    if (uns % 2 == 0)
        cout << "0" << endl;
    else
        cout << "1" << endl;
    return 0;
}
