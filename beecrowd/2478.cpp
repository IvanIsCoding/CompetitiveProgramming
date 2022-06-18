// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2478
#include <iostream>
#include <map>
#include <string>
#define endl '\n'
using namespace std;
map<string, string> mapa1, mapa2, mapa3;
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        mapa1[s1] = s2;
        mapa2[s1] = s3;
        mapa3[s1] = s4;
    }
    string a, b;
    while (cin >> a >> b) {
        if (mapa1[a] == b || mapa2[a] == b || mapa3[a] == b) {
            cout << "Uhul! Seu amigo secreto vai adorar o/" << endl;
        } else {
            cout << "Tente Novamente!" << endl;
        }
    }
    return 0;
}
