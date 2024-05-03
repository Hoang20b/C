#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int tuso;
	int mauso;
}PS;
typedef struct {
	int sops;
	PS *moips;
}DPS;
int ucln(int a , int b) {
	if(b == 0) {
		return a;
	}
	return ucln(b , a % b);
}
void uocluoc(PS *x) {
	int uoc = ucln(x->tuso , x->mauso);
	x->tuso /= uoc;
	x->mauso /= uoc;
}
void nhapps(PS *x) {
	printf("nhap tu so: ");scanf("%d", &x->tuso);
	printf("nhap mau so: ");scanf("%d", &x->mauso);
	uocluoc(x);
	if(x->mauso < 0) {
		x->tuso = -x->tuso;
		x->mauso = -x->mauso;
	}
}
void xuatps(PS *x) {
	if(x->mauso == 0) {
		printf("Infinity");
	} else if(x->mauso == 1) {
		printf("%d", x->tuso);
	} else if(x->tuso == 0) {
		printf("0");
	} else {
		printf("%d/%d", x->tuso , x->mauso);
	}
}
void nhapdps(DPS *n) {
	printf("nhap so luong phan so: ");scanf("%d", &n->sops);
	n->moips = (PS *) malloc(n->sops * sizeof(PS));
	for(int i = 0; i < n->sops; i++) {
		printf("nhap phan so %d\n", i + 1);
		nhapps(n->moips + i);
	}
}
void xuatdps(DPS *n) {
	for(int i = 0; i < n->sops; i++) {
		xuatps(n->moips + i);
		printf(" ");
	}
}
int main() {
	DPS *n;
	n = (DPS *) malloc(sizeof(DPS));
	nhapdps(n);
	xuatdps(n);
	return 0;
}
