#include<stdio.h>
#include<stdlib.h>
void nhap_matran(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", a + (i * m + j));
		}
	}
}
int am_dau(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) < 0) {
				return *(a + (i * m + j));	
			}
		}
	}
	return 0;
}
int duong_cuoi(int *a , int n , int m) {
	int duong = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) > 0) {
				duong = *(a + (i * m + j));
			}
		}
	}
	return duong;
}
void xuat_matran(int *a , int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) < 0) {
				printf("%d ", *(a + (i * m + j)));
			}
		}
	}
}
int main() {
	int *a , n ,m;
	scanf("%d%d", &n , &m);
	a = (int *) malloc((n * m) * sizeof(int));
	nhap_matran(a,n,m);
	if(am_dau(a,n,m)) {
		printf("%d\n", am_dau(a,n,m));
	} else {
		printf("Not Found\n");
	}
	if(duong_cuoi(a,n,m)) {
		printf("%d", duong_cuoi(a,n,m));
	} else {
		printf("Not Found");
	}
	return 0;
}
