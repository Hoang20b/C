#include<stdio.h>
#include<math.h>
void nhap_mang(int a[100] , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
void xuat_mang(int a[100], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
//ham sap xep tang
void sap_xep_tang(int a[] , int n) {
	int temp;
	for(int i = 0; i < n; i++) {
		//dua cac phan tu lon nhat ve cuoi mang
		for(int j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
//ham sap xep giam
void sap_xep_giam(int a[] , int n) {
	int temp;
	for(int i = 0; i < n; i++) {
		//dua cac phan tu nho nhat ve cuoi mang
		for(int j = 0; j < n - i - 1; j++) {
			if(a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	sap_xep_tang(a,n);
	xuat_mang(a,n);
	printf("\n");
	sap_xep_giam(a,n);
	xuat_mang(a,n);
	return 0;
}
