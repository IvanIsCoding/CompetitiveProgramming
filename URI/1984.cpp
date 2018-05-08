#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string numero;
	cin >> numero;
	reverse(numero.begin(),numero.end());
	cout << numero << endl;
	return 0;
}
