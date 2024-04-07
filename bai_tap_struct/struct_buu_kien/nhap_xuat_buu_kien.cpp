#include<stdio.h>
#include<math.h>
#include<string.h>
typedef struct {
	int ngay , thang , nam;
}NGAYGUI;
typedef struct {
	int mabk;
	char ten_gui[50];
	char ten_nhan[50];
	float trong_luong;
	NGAYGUI ngay_gui;
	char noi_dung[100];
	long int don_gia;
}BUUKIEN;
NGAYGUI nhapng(NGAYGUI n) {
	scanf("%d%d%d", &n.ngay , &n.thang , &n.nam);
	return n;
}
BUUKIEN nhapbk(BUUKIEN x) {
	scanf("%d", &x.mabk);
	getchar();
	gets(x.ten_gui);
	gets(x.ten_nhan);
	scanf("%f", &x.trong_luong);
	x.ngay_gui = nhapng(x.ngay_gui);
	getchar();
	gets(x.noi_dung);
	scanf("%ld", &x.don_gia);
	return x;
}
void xuatbk(BUUKIEN x) {
	printf("%d - %s - %s - %.2f - %d/%d/%d - %s - %ld", x.mabk , x.ten_gui , x.ten_nhan , x.trong_luong , x.ngay_gui.ngay , x.ngay_gui.thang , x.ngay_gui.nam , x.noi_dung , x.don_gia);
}
int main() {
	BUUKIEN x;
	x = nhapbk(x);
	xuatbk(x);
	return 0;
}
