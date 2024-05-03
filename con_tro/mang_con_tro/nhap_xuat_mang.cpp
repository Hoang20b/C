#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
void xuat_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {
	int *a,  n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	xuat_mang(a,n);
	free(a);
	return 0;
}
