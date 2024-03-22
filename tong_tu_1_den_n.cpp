#include<stdio.h>

int main() {
	int n;
	int tong = 0;
	printf("nhap n tu ban phim: ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		tong += i;
	}
	printf("%d", tong);
	return 0;
}
