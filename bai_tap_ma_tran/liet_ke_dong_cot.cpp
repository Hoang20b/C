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
//ham liet ke cung hang
void liet_ke_dong(int a[][100] , int n , int m , int k) {
	int check = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(i == k) {
				printf("%d ", a[i][j]);
				check = 1;
			}
		}
	}
	if(!check) {
		printf("None");
	}
}
//ham liet ke cot
void liet_ke_cot(int a[][100] , int n , int m , int x) {
	int check = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(j == x) {
				printf("%d ", a[i][j]);
				check = 1;
			}
		}
	}
	if(!check) {
		printf("None");
	}
}
int main() {
	int a[100][100], n , m , k , x;
	printf("nhap so cot: "); scanf("%d", &n);
	printf("nhap so hang: ");scanf("%d", &m);
	printf("nhap hang muon tim kiem: ");scanf("%d", &k);
	printf("nhap so cot muon tim kiem: ");scanf("%d", &x);
	nhap_matran(a,n,m);
	liet_ke_dong(a,n,m,k);
	printf("\n");
	liet_ke_cot(a,n,m,x);
	return 0;
}
