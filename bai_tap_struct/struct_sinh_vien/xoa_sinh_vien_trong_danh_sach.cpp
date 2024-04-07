#include<stdio.h>
#include<math.h>
#include<string.h>
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
}SV;
typedef struct {
	int sosv;
	SV moisv[100];
}MSV;
NGAYSINH nhapns(NGAYSINH n) {
	scanf("%d%d%d", &n.ngay , &n.thang , &n.nam);
	return n;
}
SV nhapsv(SV x) {
	printf("nhap ma so sinh vien: ");
	scanf("%s", x.mssv);
	getchar();
	printf("nhap ho ten sinh vien: ");
	gets(x.hoten);
	printf("nhap gioi tinh sinh vien: ");
	scanf("%c", &x.gt);
	printf("nhap ngay sinh (ngay/thang/nam): ");
	x.ngay_sinh = nhapns(x.ngay_sinh);
	printf("nhap lop: ");
	scanf("%s", x.lop);
	printf("nhap diem trung binh: ");
	scanf("%f", &x.dtb);
	return x;
}
void xuatsv(SV x) {
	printf("%s - %s - ", x.mssv , x.hoten);
	if(x.gt == 'x') {
		printf("Nam - ");
	} else {
		printf("Nu - ");
	}
	printf("%d/%d/%d - %s - %.2f", x.ngay_sinh.ngay , x.ngay_sinh.thang , x.ngay_sinh.nam, x.lop , x.dtb);
}
MSV nhapmsv(MSV n) {
	scanf("%d", &n.sosv);
	for(int i = 0; i < n.sosv; i++) {
		printf("nhap thong tin sinh vien %d\n", i + 1);
		n.moisv[i] = nhapsv(n.moisv[i]);
	}
	return n;
}
void xuatmsv(MSV n) {
	for(int i = 0; i < n.sosv; i++) {
		xuatsv(n.moisv[i]);
		if(i + 1 < n.sosv) {
			printf("\n");
		}
	}
}
void xoasv(MSV n,char mssvxoa[]) {
	int check = 0;
	for(int i = 0; i < n.sosv; i++) {
		if(strstr(n.moisv[i].mssv,mssvxoa)) {
			for(int j = i; j < n.sosv; j++) {
				n.moisv[j] = n.moisv[j + 1];
				check = 1;
			}
			n.sosv--;
		}
	}
	if(!check) {
		printf("NOT FOUND!");
	} else {
		xuatmsv(n);
	}
}
int main() {
	MSV n;
	char svxoa[11];
	n = nhapmsv(n);
	scanf("%s", svxoa);
	xoasv(n,svxoa);
	return 0;
}
