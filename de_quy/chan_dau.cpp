#include<stdio.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	if(n == 0) {
		return;
	}
	nhap_mang(a, n - 1);
	scanf("%d", a + n - 1);
}
void chan_dau(int *a , int n) {
	if(n == 0) {
		return;
	}
	if(*a % 2 == 0) {
		printf("%d", *a);
		return;
	}
	chan_dau(a + 1, n - 1);
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	chan_dau(a,n);
	free(a);
	return 0;
}
