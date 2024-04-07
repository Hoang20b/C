#include<stdio.h>
#include<math.h>
typedef struct {
	int ngay , thang , nam;
}NGAYSINH;
typedef struct {
	char mssv[11];
	char hoten[51];
	char gt;
	NGAYSINH ngay_sinh;
	char lop[11];
	float dtb;
}SINHVIEN;
//ham nhap ngay sinh
NGAYSINH nhapns(NGAYSINH n) {
	scanf("%d%d%d", &n.ngay , &n.thang , &n.nam);
	return n;
}
//ham nhap thong tin sinh vien
SINHVIEN nhapsv(SINHVIEN x) {
	printf("nhap ma so sinh vien: ");
	scanf("%s", x.mssv);
	printf("nhap ho ten sinh vien: ");
	//xoa bo nho dem voi getchar
	getchar();
	gets(x.hoten);
	printf("nhap gioi tinh: ");
	scanf("%c", &x.gt);
	printf("nhap ngay sinh sinh vien (ngay/thang/nam): ");
	x.ngay_sinh = nhapns(x.ngay_sinh);
	printf("nhap lop cua sinh vien: ");
	scanf("%s", x.lop);
	printf("nhap diem trung binh cua sinh vien: ");
	scanf("%f", &x.dtb);
	return x;
}
void xuat_thongtinsinhvien(SINHVIEN x) {
	printf("%s - %s - ", x.mssv , x.hoten);
	if(x.gt == 'x') {
		printf("Nam - ");
	} else {
		printf("Nu - ");
	}
	printf("%d/%d/%d - %s - %.2f", x.ngay_sinh.ngay , x.ngay_sinh.thang , x.ngay_sinh.nam , x.lop , x.dtb);
}
int main() {
	SINHVIEN x;
	x = nhapsv(x);
	xuat_thongtinsinhvien(x);
	return 0;
}
