#include<stdio.h>
int main() {
	int n; 
	long long int s = 1;
	printf("nhap n: ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		s *= i;
	}
	printf("%lld", s);
	return 0;
}
