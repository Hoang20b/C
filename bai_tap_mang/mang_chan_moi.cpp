#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
void mang_chan(int a[], int b[] , int n , int &k) {
	for(int i = 0;i < n; i++) {
		if(a[i] % 2 == 0) {
			b[k] = a[i];
			k++;
		}
	}
}
void xuat_mang(int a[] , int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
int main() {
	int a[100] , b[100] , n , k = 0;
	scanf("%d", &n);
	nhap_mang(a,n);
	mang_chan(a,b,n,k);
	xuat_mang(b,k);
	return 0;
}
