#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
void nhap_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int tong_chan(int *a , int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		if(*(a + i) % 2 == 0) {
			tong += *(a + i);
		}
	}
	return tong;
}
int tong_le(int *a , int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		if(*(a + i) % 2 != 0) {
			tong += *(a + i);
		}
	}
	return tong;
}
int tong_snt(int *a , int n) {
	int tong = 0; 
	for(int i = 0; i < n; i++) {
		if(snt(*(a + i))) {
			tong += *(a + i);
		}
	}
	return tong;
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("tong chan: %d\n", tong_chan(a,n));
	printf("tong le: %d\n", tong_le(a,n));
	printf("tong so nguyen to: %d", tong_snt(a,n));
	free(a);
	return 0;
}
