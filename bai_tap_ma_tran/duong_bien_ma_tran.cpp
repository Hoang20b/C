#include<stdio.h>
#include<math.h>
void nhap_matran(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap phan tu a[%d][%d]: " , i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham in ra cac phan tu bien trai
void bien_trai(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i][0]);
	}
}
//ham in ra cac phan tu bien phai
void bien_phai(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i][n - 1]);
	}
}
//ham in ra cac phan tu bien tren
void bien_tren(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[0][i]);
	}
}
//ham in ra cac phan tu bien duoi
void bien_duoi(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[n - 1][i]);
	}
}
int main() {
	int a[100][100] , n;
	printf("nhap so dong va so cot: ");scanf("%d", &n);
	nhap_matran(a,n);
	bien_trai(a,n);
	printf("\n");
	bien_phai(a,n);
	printf("\n");
	bien_tren(a,n);
	printf("\n");
	bien_duoi(a,n);
	return 0;
}
