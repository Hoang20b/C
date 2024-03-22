#include<stdio.h>
int main() {
	int a , b , n;
	scanf("%d%d%d", &a , &b , &n);
	if(2 * a < b) {
		printf("%ld", a * n);
	} else {
		if(b % 2 == 0) {
			printf("%d", (b / 2) * n);
		} else {
			printf("%d", ((b/ 2) * n) + a);
		}
	}
	return 0;
}
