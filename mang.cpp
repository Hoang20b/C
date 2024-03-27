#include<stdio.h>
#include<math.h>
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
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
void xuat_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
void pt_chan(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0) {
			printf("%d ", a[i]);
		}
	}
}
void pt_le(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 != 0) {
			printf("%d ", a[i]);
		}
	}
}
void pt_snt(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if(snt(a[i])) {
			printf("%d ", a[i]);
		}
	}
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	xuat_mang(a,n);
	printf("\n");
	pt_chan(a,n);
	printf("\n");
	pt_le(a,n);
	printf("\n");
	pt_snt(a,n);
	return 0;
}
