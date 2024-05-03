#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int tong(int *a , int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		tong += *(a + i);
	}
	return tong;
}
void xuat_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("%d", tong(a,n));
	free(a);
	return 0;
}
