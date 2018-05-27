#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	cout << m - __gcd(n,m) << endl;
	return 0;
}