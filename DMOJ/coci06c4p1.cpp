#include <cstdio>
int main(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	while(n--){
		int c;
		scanf("%d",&c);
		if(c*c <= a*a + b*b) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}