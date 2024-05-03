#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap_matran(int *a , int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", a + i * n + j);
		}
	}
}
int tong_cheo_chinh(int *a , int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		tong += *(a + (i * n + i));
	}
	return tong;
}
int tong_cheo_phu(int *a , int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		tong += *(a + (i + 1) * (n - 1));
	}
	return tong;
}
int tong_bien(int *a , int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		tong += *(a + i * n + 0);
	}
	for(int i = 0; i < n; i++) {
		tong += *(a + i * n + (n - 1));
	}
	for(int i = 0; i < n; i++) {
		tong += *(a + 0 * n + i);
	}
	for(int i = 0; i < n; i++) {
		tong += *(a + (n - 1) * n + i);
	}
	return tong;
}
void xuat_matran(int *a , int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", *(a + i * n + j));
		}
		printf("\n");
	}
}
int main() {
	int *a, n;
	scanf("%d", &n);
	a = (int *) malloc((n * n) * sizeof(int));
	nhap_matran(a,n);
	printf("tong cheo chinh: %d\n", tong_cheo_chinh(a,n));
	printf("tong cheo phu: %d\n", tong_cheo_phu(a,n));
	printf("tong bien: %d", tong_bien(a,n));
	free(a);
	return 0;
}

