#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct {
	int ngay,thang,nam;
}NGAYSINH;
typedef struct {
	char mssv[11];
	char hoten[51];
	char gt;
	NGAYSINH ngay_sinh;
	char lop[11];
	float toan,ly,hoa;
}SV;
void nhapns(NGAYSINH *ns) {
	scanf("%d%d%d", &ns->ngay , &ns->thang , &ns->nam);
}
void nhapsv(SV *x) {
	printf("nhap ma so sinh vien: ");scanf("%s", x->mssv);
	getchar();
	printf("nhap ho ten sinh vien: ");gets(x->hoten);
	printf("nhap gioi tinh (x/y): ");scanf("%c", &x->gt);
	printf("nhap ngay sinh (ngay/thang/nam): ");nhapns(&x->ngay_sinh);
	printf("nhap lop: ");scanf("%s", x->lop);
	printf("nhap diem toan , ly , hoa: ");scanf("%f%f%f", &x->toan, &x->ly , &x->hoa);
}
void xuatsv(SV *x) {
	printf("%s - %s - ", x->mssv , x->hoten);
	if(x->gt == 'x') {
		printf("Nam - ");
	} else {
		printf("Nu - ");
	}
	printf("%d%d%d - %s - %.2f - %.2f - %.2f", x->ngay_sinh.ngay , x->ngay_sinh.thang , x->ngay_sinh.nam , x->lop, x->toan , x->ly , x->hoa);
}
int main() {
	SV *x;
	x = (SV *) malloc(sizeof(SV));
	nhapsv(x);
	xuatsv(x);
	return 0;
}
