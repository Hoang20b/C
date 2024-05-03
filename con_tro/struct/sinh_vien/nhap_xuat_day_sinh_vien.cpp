#include<stdio.h>
#include<stdlib.h>
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
	float toan , ly , hoa;
}SV;
typedef struct {
	int sosv;
	SV *moisv;
}DSV;
void nhapns(NGAYSINH *ns) {
	scanf("%d%d%d", &ns->ngay , &ns->thang , &ns->nam);
}
void nhapsv(SV *x) {
	printf("nhap ma so sinh vien: ");scanf("%s", x->mssv);
	getchar();
	printf("nhap ho ten sinh vien: ");gets(x->hoten);
	printf("nhap gioi tinh (x/y): ");scanf("%c", &x->gt);
	printf("nhap ngay sinh (ngay/thang/nam): "); nhapns(&x->ngay_sinh);
	printf("nhap lop: ");scanf("%s", x->lop);
	printf("nhap diem (toan/ly/hoa): ");scanf("%f%f%f", &x->toan , &x->ly , &x->hoa);
}
void xuatsv(SV *x) {
	printf("%s - %s - ", x->mssv , x->hoten);
	if(x->gt == 'x') {
		printf("Nam - ");
	} else {
		printf("Nu - ");
	}
	printf("%d%d%d - %s - ", x->ngay_sinh.ngay , x->ngay_sinh.thang, x->ngay_sinh.nam , x->lop);
	printf("%.2f - %.2f - %.2f", x->toan , x->ly , x->hoa);
}
void nhapdsv(DSV *n) {
	printf("nhap so sinh vien: ");scanf("%d", &n->sosv);
	n->moisv = (SV *) malloc(n->sosv * sizeof(SV));
	for(int i = 0; i < n->sosv; i++) {
		printf("nhap thong tin sinh vien %d\n", i + 1);
		nhapsv(n->moisv + i);
	}
}
void xuatdsv(DSV *n) {
	for(int i = 0; i < n->sosv; i++) {
		xuatsv(n->moisv + i);
		if(i + 1 < n->sosv) {
			printf("\n");
		}
	}
}
int main() {
	DSV *n;
	n = (DSV *) malloc(sizeof(DSV));
	nhapdsv(n);
	xuatdsv(n);
	return 0;
}
