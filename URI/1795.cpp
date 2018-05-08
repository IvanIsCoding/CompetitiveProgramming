#include <cstdio>
int main(){
	int n;
	long long resposta=1;
	scanf("%d",&n);
	while(n--) resposta *= 3;
	printf("%lld\n",resposta);
	return 0;
}
