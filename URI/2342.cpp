#include <cstdio>
int main() {
	int a,b,c;
	char digito;
	scanf("%d",&a);
	scanf("%d %c %d",&b,&digito,&c);
	if (digito==43) {
		if (a>=(b+c)){
			printf("OK\n");
		}
		else {
			printf("OVERFLOW\n");
		}
	}
	else {
		if (a>=(b*c)) {
			printf("OK\n");
		}
		else {
			printf("OVERFLOW\n");
		}
	}
	return 0;
}
