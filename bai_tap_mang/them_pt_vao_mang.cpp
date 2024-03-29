#include<stdio.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
// ham them 1 phan tu vao dau mang
void them_pt_dau_mang(int a[] , int &n, int x) {
	for(int i = n; i > 0; i--) {
		//cho nhung gia tri lui xuong 1 vi tri 
		a[i] = a[i - 1];
	}
	//vi tri dau tien se la phan tu can them
	a[0] = x;
	n++;
}
//ham them 1 phan tu vao 1 vi tri mong muon
void them_pt_vt(int a[], int &n, int ptthem , int vtthem) {
	//chay den vi tri mong muon va cho moi phan tu lui lai 1 vi tri
	for(int i = n; i > vtthem; i--) {
		a[i] = a[i - 1];
	}
	//gan vi tri mong muon bang 1 gia tri mong muon them
	a[vtthem] = ptthem;
	n++;
}
void xuat_mang(int a[],int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
int main() {
	int a[100] , n , x;
	int pt_them , vt_them;
	scanf("%d", &n);
	nhap_mang(a,n);
	scanf("%d", &x);
	scanf("%d%d", &pt_them , &vt_them);
	them_pt_dau_mang(a,n,x);
	them_pt_vt(a,n,pt_them,vt_them);
	xuat_mang(a,n);
	return 0;
	
}
