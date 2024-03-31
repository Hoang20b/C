#include<stdio.h>
#include<math.h>
void nhap_matran(int a[][100] , int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap gia tri a[%d][%d]: ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham liet ke nhung phan tu tren duong cheo chinh
void cheo_chinh(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
}
//ham liet ke nhung phan tu nam tren duong cheo phu
void cheo_phu(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == n - j - 1) {
				printf("%d ", a[i][j]);
			}
		}
	}
	/*code cai tien
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i][n - i - 1]);
	}
	*/
}
int main() {
	int a[100][100], n;
	printf("nhap so hang cot: ");scanf("%d", &n);
	nhap_matran(a,n);
	cheo_chinh(a,n);
	printf("\n");
	cheo_phu(a,n);
	return 0;
}
