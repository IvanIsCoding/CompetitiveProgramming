#include <cstdio>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",(n%2==0) ? 1 : 9);
	}
	return 0;
}
