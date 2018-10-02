// Ivan Carvalho
// Solution to https://www.urionlinejudge.com.br/judge/problems/view/2395
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a,b,c,x,y,z,resposta;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d %d",&x,&y,&z);
	printf("%d\n",(x/a)*(y/b)*(z/c));
	return 0;
} 
