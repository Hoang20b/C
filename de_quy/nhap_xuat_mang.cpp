#include<stdio.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	if(n == 0) {
		return;
	}
	nhap_mang(a,n - 1);
	scanf("%d", a + n - 1);
}
void xuat_mang(int *a , int n) {
	if(n == 0) {
		return;
	}
	xuat_mang(a,n - 1);
	printf("%d ", *(a + n - 1));
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	xuat_mang(a,n);
	return 0;
}
