#include<stdio.h>
#include<math.h>
typedef struct {
	float heso;
	int bac;
}DONTHUC;
//ham nhap don thuc
DONTHUC nhapdonthuc(DONTHUC x) {
	printf("nhap he so cua don thuc: ");scanf("%f", &x.heso);
	printf("nhap bac cua don thuc: ");scanf("%d", &x.bac);
	return x;
}
//ham tinh tich 2 don thuc
DONTHUC tichdonthuc(DONTHUC a , DONTHUC b) {
	DONTHUC x;
	x.heso = a.heso * b.heso;
	x.bac = a.bac + b.bac;
	return x;
}
//ham tinh thuong 2 don thuc
DONTHUC thuongdonthuc(DONTHUC a , DONTHUC b) {
	DONTHUC x;
	x.heso = a.heso / b.heso;
	x.bac = a.bac - b.bac;
	return x;
}
//ham dao ham don thuc
DONTHUC daohamdonthuc(DONTHUC x) {
	DONTHUC daoham;
	//khi dao ham thi heso se nhan so bac va so bac - 1
	daoham.heso = x.heso * x.bac;
	daoham.bac = x.bac - 1;
	return daoham;
}
//ham tinh gia tri don thuc
int giatridonthuc(DONTHUC x, int giatri) {
	int gtdonthuc = x.heso * pow(giatri , x.bac);
	return gtdonthuc;
}
//xuat don thuc
void xuatdonthuc(DONTHUC x) {
	if(x.heso == 0) {
		printf("0");
	} else if(x.bac == 0) {
		printf("%.2f", x.heso);
	} else if(x.heso == 1) {
		printf("x^%d", x.bac);
	} else {
		printf("%.2fx^%d", x.heso , x.bac);
	}
}
int main() {
	DONTHUC a , b , x;
	printf("nhap don thuc X\n");
	x = nhapdonthuc(x);
	printf("nhap don thuc A\n");
	a = nhapdonthuc(a);
	printf("nhap don thuc B\n");
	b = nhapdonthuc(b);
	printf("gia tri don thuc x la: ");
	xuatdonthuc(x);printf("\n");
	x = tichdonthuc(a,b);
	printf("tich 2 don thuc la: ");
	xuatdonthuc(x);printf("\n");
	x = thuongdonthuc(a,b);
	printf("thuong 2 don thuc la: ");
	xuatdonthuc(x);printf("\n");
	x = daohamdonthuc(x);
	printf("dao ham cua don thuc la: ");
	xuatdonthuc(x);printf("\n");
	printf("gia tri cua don thuc tai x = 3 la: ");
	printf("%d", giatridonthuc(x,3));
	return 0;
}
