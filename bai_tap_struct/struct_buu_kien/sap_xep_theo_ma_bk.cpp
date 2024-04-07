#include<stdio.h>
#include<math.h>
#include<string.h>
typedef struct {
	int ngay , thang , nam;
}NGAY;
typedef struct {
	int mabk;
	char ten_nguoi_gui[51];
	char ten_nguoi_nhan[51];
	float trong_luong;
	NGAY ngay_gui;
	char noi_dung[101];
	long int don_gia;
}BK;
typedef struct {
	int sobk;
	BK moibk[100];
}DSBK;
NGAY nhap_ngay_gui(NGAY n) {
	scanf("%d%d%d", &n.ngay , &n.thang , &n.nam);
	return n;
}
BK nhapbk(BK x) {
	printf("nhap ma buu kien: ");
	scanf("%d", &x.mabk);
	getchar();
	printf("nhap ten nguoi gui: ");
	gets(x.ten_nguoi_gui);
	printf("nhap ten nguoi nhan: ");
	gets(x.ten_nguoi_nhan);
	printf("nhap trong luong buu kien: ");
	scanf("%f", &x.trong_luong);
	printf("nhap ngay gui (ngay/thang/nam): ");
	x.ngay_gui = nhap_ngay_gui(x.ngay_gui);
	getchar();
	printf("nhap noi dung: ");
	gets(x.noi_dung);
	printf("nhap don gia: ");
	scanf("%ld", &x.don_gia);
	return x;
}
void xuatbk(BK x) {
	printf("%d - %s - %s - %.2f - ", x.mabk , x.ten_nguoi_gui , x.ten_nguoi_nhan , x.trong_luong);
	printf("%d/%d/%d - %s - %ld", x.ngay_gui.ngay , x.ngay_gui.thang , x.ngay_gui.nam , x.noi_dung , x.don_gia);
}
DSBK nhapdsbk(DSBK n) {
	printf("nhap so luong buu kien: ");scanf("%d", &n.sobk);
	for(int i = 0; i < n.sobk; i++) {
		n.moibk[i] = nhapbk(n.moibk[i]);
	}
	return n;
}
DSBK sap_xep(DSBK n) {
	BK temp;
	for(int i = 0; i < n.sobk; i++) {
		for(int j = 0; j < n.sobk - i - 1; j++) {
			if(n.moibk[j].mabk > n.moibk[j + 1].mabk) {
				temp = n.moibk[j];
				n.moibk[j] = n.moibk[j + 1];
				n.moibk[j + 1] = temp;
			}
		}
	}
	return n;
}
void xuatdsbk(DSBK n) {
	n = sap_xep(n);
	for(int i = 0; i < n.sobk; i++) {
		xuatbk(n.moibk[i]);
		if(i + 1 < n.sobk) {
			printf("\n");
		}
	}
}
int main() {
	DSBK n;
	n = nhapdsbk(n);
	xuatdsbk(n);
	return 0;
}
