#include<stdio.h>
#include<math.h>
void nhap_matran(int a[][100] , int n , int m) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap phan tu a[%d][%d]: ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham tinh tong
int tong(int a[][100], int n , int m) {
	int tong = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}
//ham tinh trung binh cong
float tbc(int a[][100], int n , int m) {
	int dem = 0;
	int tong = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0;j < n; j++) {
			tong += a[i][j];
			dem++;
		}
	}
	return (float) tong / dem;
}
//ham tinh trung binh cong cac phan tu duong
float tbcd(int a[][100], int n , int m) {
	int tong = 0;
	int dem = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n;j++) {
			if(a[i][j] > 0) {
				tong += a[i][j];
				dem++;
			} 
		}
	}
	return (float) tong/dem;
}
int main() {
	int a[100][100], n , m;
	printf("nhap so cot: ");scanf("%d", &n);
	printf("nhap so dong: ");scanf("%d", &m);
	nhap_matran(a,n,m);
	printf("%d\n", tong(a,n,m));
	printf("%.2f\n", tbc(a,n,m));
	printf("%.2f", tbcd(a,n,m));
	return 0;
}
