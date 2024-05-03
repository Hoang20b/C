#include<stdio.h>
#include<stdlib.h>
void nhap_matran(int *a, int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", a + (i * m + j));
		}
	}
}
int snt(int n) {
	if(n <= 1) {
		return 0;
	}
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int tong_chan(int *a, int n , int m) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) % 2 == 0) {
				tong += *(a + (i * m + j));
			}
		}
	}
	return tong;
}
int tong_le(int *a, int n , int m) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) % 2 != 0) {
				tong += *(a + (i * m + j));
			}
		}
	}
	return tong;
}
int tong_snt(int *a, int n , int m) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(snt(*(a + (i * m + j)))) {
				tong += *(a + (i * m + j));
			}
		}
	}
	return tong;
}
int main() {
	int *a, n , m;
	scanf("%d%d", &n, &m);
	a = (int *) malloc((n * m) * sizeof(int));
	nhap_matran(a,n,m);
	printf("%d\n%d\n%d", tong_chan(a,n,m), tong_le(a,n,m), tong_snt(a,n,m));
	return 0;
}
