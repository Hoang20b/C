#include<stdio.h>
#include<math.h>
void nhap_matran(int a[100][100], int n , int m) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap ma tran n[%d][%d]: ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham tinh tich 2 ma tran 
void TinhTich(int a[100][100], int b[100][100], int m, int n,int p , int q)
{
	int c[100][100];
	//neu cot ma tran nay khong bang hang ma tran kia thi khong nhan duoc
    if(n != p) {
    	return;
	}
	//bat dau tu hang cua ma tran a lam hang , cot ma tran b lam cot 
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < q; j++) {
			c[i][j] = 0;
			for(int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int a[100][100] , b[100][100] , n , m , p , q;
	printf("nhap so cot ma tran A: ");scanf("%d", &n);
	printf("nhap so hang ma tran A: ");scanf("%d", &m);
	nhap_matran(a,n,m);
	printf("nhap so cot ma tran B: ");scanf("%d", &p);
	printf("nhap so hang ma tran B: ");scanf("%d", &q);
	nhap_matran(b,p,q);
	TinhTich(a,b,m,n,q,p);
	return 0;
}
