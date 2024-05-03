#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	if(n == 0) {
		return;
	}
	nhap_mang(a,n - 1);
	scanf("%d", a + n - 1);
}
int tong_mang(int *a , int n) {
	if(n == 0) {
		return 0;
	}
	return *(a + n - 1) + tong_mang(a,n - 1);
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("%d", tong_mang(a,n));
	free(a);
	return 0;
}
