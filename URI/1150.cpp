
#include <cstdio>
#define MENOSINFINITO -2147483647
int main(){
	int x,z=MENOSINFINITO,temp=0,resposta=0;
	scanf("%d",&x);
	while(z<=x) scanf("%d",&z);
	while(temp<z){
		resposta++;
		temp += x;
		x++;
	}
	printf("%d\n",resposta);
	return 0;
}





