#include <cstdio>
int vetor[1010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k;
			scanf("%d",&k);
			vetor[i] |= k;
			vetor[j] |= k;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",vetor[i]);
	printf("\n");
	return 0;
}