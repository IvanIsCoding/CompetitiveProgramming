#include <cstdio>
#include <cmath>
int main(){
	int resposta = 0,n;
	double maximo = 0.0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		double davez = y * log(x);
		if (davez > maximo){
			maximo = davez;
			resposta = i;
		}
	}
	printf("%d\n",resposta);
	return 0;
} 
