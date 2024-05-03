#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct {
	int tuso;
	int mauso;
}PS;
int ucln(int a , int b) {
	if(b == 0) {
		return a;
	}
	return ucln(b , a % b);
}
void uocluoc(PS *x) {
	int uoc = ucln(x->tuso,x->mauso);
	x->tuso /= uoc;
	x->mauso /= uoc;
}
void nhapps(PS *x) {
	printf("nhap tu so: ");scanf("%d", &x->tuso);
	printf("nhap mau so: ");scanf("%d", &x->mauso);
	if(x->mauso < 0) {
		x->tuso = -x->tuso;
		x->mauso = -x->mauso;
	}
}
void xuatps(PS *x) {
	uocluoc(x);
	if(x->mauso == 0) {
		printf("Infinity");
	} else if(x->tuso == 0) {
		printf("0");
	} else if(x->mauso == 1) {
		printf("%d", x->tuso);
	} else {
		printf("%d/%d", x->tuso , x->mauso);
	}
}
int main() {
	PS *x = (PS *) malloc(sizeof(PS));
	nhapps(x);
	xuatps(x);
	return 0;
}
