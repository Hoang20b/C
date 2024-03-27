#include<stdio.h>
#include<math.h>
// tong cac so nguyen to can sang
int snt[1000001];
//ham sang so nguyen to
void sang() {
	for(int i = 0; i <= 1000000;i++) {
		snt[i] = 1;
	}
	snt[0] = snt[1] = 0;
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * i; j <= 1000000;j += i) {
			if(snt[j]) {
				snt[j] = 0;
			}
		}
	}
}
// ham kiem tra so chinh phuong
int scp(int n) {
	if(sqrt(n) == (int) sqrt(n)) {
		return 1;
	}
	return 0;
}
// ham kiem tra so hoan thien 
int sht(int n) {
	int tong = 0;
	for(int i = 1; i <= n / 2; i++) {
		tong += i;
	}
	if(tong == n) {
		return 1;
	}
	return 0;
}
//ham nhap ma tran
void nhap_matran(int a[][100], int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
//ham xuat ma tran
void xuat_matran(int a[][100], int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
	}
}
//ham xuat so chan
void xuat_ptchan(int a[][100], int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] % 2 == 0) {
				printf("%d ", a[i][j]);
			}
		}
	}
}
//ham xuat ra so le
void xuat_ptle(int a[][100], int n , int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] % 2 != 0) {
				printf("%d ", a[i][j]);
			}
		}
	}
}
// ham xuat ra so nguyen to
void xuat_ptsnt(int a[][100], int n , int m) {
	sang();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(snt[a[i][j]]) {
				printf("%d ", a[i][j]);
			}
		}
	}
}
//ham xuat so chinh phuong
void xuat_ptscp(int a[][100], int n , int m) {
	sang();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(scp(a[i][j])) {
				printf("%d ", a[i][j]);
			}
		}
	}
}
//ham xuat so hoan thien
void xuat_ptsht(int a[][100], int n , int m) {
	sang();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(sht(a[i][j])) {
				printf("%d ", a[i][j]);
			}
		}
	}
}
int main() {
	int a[100][100] , n , m;
	scanf("%d%d", &n , &m);
	nhap_matran(a,n,m);
	xuat_matran(a,n,m);
	printf("\n");
	xuat_ptchan(a,n,m);
	printf("\n");
	xuat_ptle(a,n,m);
	printf("\n");
	xuat_ptsnt(a,n,m);
	printf("\n");
	xuat_ptscp(a,n,m);
	printf("\n");
	xuat_ptsht(a,n,m);
	return 0;
}
