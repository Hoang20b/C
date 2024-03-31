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
//ham tim max
int tim_max(int a[][100], int n , int m) {
	int max = a[0][0];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(max < a[i][j]) {
				max = a[i][j];
			}
		}
	}
	return max;
}
//ham tim min
int tim_min(int a[][100], int n , int m) {
	int min = a[0][0];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(min > a[i][j]) {
				min = a[i][j];
			}
		}
	}
	return min;
}
int main() {
	int a[100][100], n , m;
	printf("nhap so cot: ");scanf("%d", &n);
	printf("nhap so hang: ");scanf("%d", &m);
	nhap_matran(a,n,m);
	printf("%d\n", tim_max(a,n,m));
	printf("%d", tim_min(a,n,m));
	return 0;
}
