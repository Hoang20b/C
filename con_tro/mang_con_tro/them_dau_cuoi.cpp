#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap_mang(int *a, int n) {
	for(int i = 0;i < n; i++) {
		scanf("%d", a + i);
	}
}
void them_pt_dau(int *a, int &n , int pt_dau) {
	for(int i = n; i > 0; i--) {
		*(a + i) = *(a + (i - 1));
	}
	*(a + 0) = pt_dau;
	n++;
}
void them_pt_cuoi(int *a , int &n, int cuoi) {
    *(a + n) = cuoi;
    n++;
}
void xuat_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {

	int *a , n, them_dau , them_cuoi;
	scanf("%d", &n);
	a = (int *) malloc(n + 2 * sizeof(int));
	nhap_mang(a,n);
	scanf("%d%d", &them_dau , &them_cuoi);
	them_pt_dau(a,n,them_dau);
	xuat_mang(a,n);printf("\n");
	them_pt_cuoi(a,n,them_cuoi);
	xuat_mang(a,n);
	free(a);
	return 0;
}
