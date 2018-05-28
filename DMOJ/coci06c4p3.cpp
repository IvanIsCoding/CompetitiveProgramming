#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,v;
	cin >> n >> v;
	n--;
	while(n--){
		int u;
		cin >> u;
		int mdc = __gcd(u,v);
		cout << v / mdc << "/" <<  u / mdc << endl;
	}
	return 0;
}