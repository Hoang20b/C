#include<stdio.h>
#include<math.h>
typedef struct {
	float heso;
	int bac;
}DONTHUC; 
typedef struct {
	int sodonthuc;
	DONTHUC moidt[100];
}DATHUC;
DONTHUC nhapdonthuc(DONTHUC x) {
	printf("nhap he so: ");scanf("%f", &x.heso);
	printf("nhap bac: ");scanf("%d", &x.bac);
	return x;
}
void xuatdonthuc(DONTHUC x) {
	if(x.bac == 0) {
		printf("%.2f", x.heso);
	} else if(x.heso == 0) {
		printf("0");
	} else if(x.heso == 1) {
		printf("x^%d", x.bac);
	} else {
		printf("%.2fx^%d", x.heso , x.bac);
	}
}
DATHUC trung_bac(DATHUC n) {
	for(int i = 0; i < n.sodonthuc; i++) {
		for(int j = i + 1; j < n.sodonthuc; j++) {
			if(n.moidt[i].bac == n.moidt[j].bac) {
				n.moidt[i].heso += n.moidt[j].heso;
				for(int k = j; k < n.sodonthuc; k++) {
					n.moidt[k] = n.moidt[k + 1];
				}
				n.sodonthuc--;
				j--;
			}
		}
	}
	return n;
}
DATHUC sap_xep(DATHUC n) {
	DONTHUC tmp;
	for(int i = 0; i < n.sodonthuc; i++) {
		for(int j = 0; j < n.sodonthuc - i - 1; j++) {
			if(n.moidt[j].bac < n.moidt[j + 1].bac) {
				tmp = n.moidt[j];
				n.moidt[j] = n.moidt[j + 1];
				n.moidt[j + 1] = tmp;
			}
		}
	}
	return n;
}
DATHUC nhapdathuc(DATHUC n) {
	printf("nhap so don thuc: ");scanf("%d", &n.sodonthuc);
	for(int i = 0; i < n.sodonthuc; i++) {
		n.moidt[i] = nhapdonthuc(n.moidt[i]);
	}
	n = trung_bac(n);
	n = sap_xep(n);
	return n;
}
void xuatdathuc(DATHUC n) {
	for(int i = 0; i < n.sodonthuc;i++) {
		xuatdonthuc(n.moidt[i]);
		if(i + 1 < n.sodonthuc) {
			printf(" + ");
		}
	}
}
int main() {
	DATHUC n;
	n = nhapdathuc(n);
	xuatdathuc(n);
	return 0;
}
