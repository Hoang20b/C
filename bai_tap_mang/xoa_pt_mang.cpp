#include<stdio.h>
#include<math.h>
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
//ham xoa phan tu mang
void xoa_pt(int a[], int &n , int vt_xoa) {
	//bat dau day cac gia tri phia sau phan tu bi xoa len
	for(int i = vt_xoa; i < n; i++) {
		a[i] = a[i + 1];
	}
	//sau khi xoa chieu dai cua mang se giam
	n--;
}
int main() {
	int a[100] , n , x;
	scanf("%d", &n);
	nhap_mang(a,n);
	scanf("%d", &x);
	xoa_pt(a,n,x);
	xuat_mang(a,n);
	return 0;
}
