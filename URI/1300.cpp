#include <cstdio>
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		printf("%c\n",(n%6) == 0 ? 'Y' : 'N');
	}
	return 0;
}
