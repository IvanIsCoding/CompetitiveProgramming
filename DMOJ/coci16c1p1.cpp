#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,n,tot;
	cin >> x >> n;
	tot = (n+1)*x;
	while(n--){
		int v;
		cin >> v;
		tot -= v;
	}
	cout << tot << endl;
	return 0;
}