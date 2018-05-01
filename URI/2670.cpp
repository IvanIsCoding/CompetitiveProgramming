#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int resp = 2*a+b;
	resp = min(resp,a+c);
	resp = min(resp,b + 2*c);
	cout << 2*resp << endl;
	return 0;
}
