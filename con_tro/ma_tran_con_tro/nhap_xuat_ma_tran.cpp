#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_matran(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", a + (i * m + j));
		}
	}
}
void xuat_matran(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", *(a +(i * m + j)));
		}
		printf("\n");
	}
}
int main() {
	int *a, n , m;
	scanf("%d%d", &n , &m);
	a = (int *) malloc((n * m) * sizeof(int));
	nhap_matran(a,n,m);
	xuat_matran(a,n,m);
	return 0;
}
