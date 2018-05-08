#include <cstdio>
int main(){
	int n;
	while(scanf("%d",&n) && n){
		if (n%2) n++;
		printf("%d\n",5*n + 20);
	}
	return 0;
}
