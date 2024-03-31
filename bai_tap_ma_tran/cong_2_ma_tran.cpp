#include<stdio.h>
#include<math.h>
void nhap_matran(int a[][100], int n , int m) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap gia tri a[%d][%d]: ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham tinh tong ma tran a b
void tong_matran(int a[][100] , int b[][100] , int n , int m) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			//moi khi thay doi so hang , so cot thi cong gia tri 2 pt cua 2 ma tran
			a[i][j] += b[i][j];
		}
	}
}
void xuat_matran(int a[][100], int n , int m) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int a[100][100] , b[100][100] , n , m;
	printf("nhap so cot: ");scanf("%d", &n);
	printf("nhap so hang: ");scanf("%d", &m);
	printf("nhap gia tri ma tran A\n");
	nhap_matran(a,n,m);
	printf("nhap gia tri ma tran B\n");
	nhap_matran(b,n,m);
	tong_matran(a,b,n,m);
	xuat_matran(a,n,m);
	return 0;
}
