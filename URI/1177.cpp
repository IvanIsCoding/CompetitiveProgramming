#include <cstdio>
int main(){
	int i,a,davez=0;
	scanf("%d",&a);
	for(i=0;i<1000;i++){
		davez = davez % a;
		printf("N[%d] = %d\n",i,davez);
		davez++;
	}
	return 0;
}
