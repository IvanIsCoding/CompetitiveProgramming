// Ivan Carvalho
// Solution to https://www.beecrowd.com.br/judge/problems/view/2667
#include <bits/stdc++.h>
using namespace std;
int main() {
    int resp = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) resp += (s[i] - '0');
    if (resp % 3 == 1)
        printf("1\n");
    else if (resp % 3 == 2)
        printf("2\n");
    else
        printf("0\n");
    return 0;
}
