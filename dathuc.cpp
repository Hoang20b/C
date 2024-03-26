#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
	float heso;
	int bac;
}DONTHUC;
typedef struct {
	int sodt;
	DONTHUC moidt[100];
}DATHUC;
DONTHUC nhapdt(DONTHUC x) {
	printf("nhap he so: ");
	scanf("%f", &x.heso);
	printf("nhap so bac: ");
	scanf("%d", &x.bac);
	return x;
}
void xuatdt(DONTHUC x) {
	if(x.heso == 0) {
		printf("");
	} else if(x.bac == 0) {
		printf("%.2f", x.heso);
	} else {
		printf("%.2fx^%d", x.heso , x.bac);
	}
}
DATHUC nhapdathuc(DATHUC x) {
	scanf("%d", &x.sodt);
	for(int i = 0; i < x.sodt; i++) {
		x.moidt[i] = nhapdt(x.moidt[i]);
	}
	for(int i = 0; i < x.sodt; i++) {
		for(int j = i + 1; j < x.sodt; j++) {
			if(x.moidt[i].bac == x.moidt[j].bac) {
				x.moidt[i].heso += x.moidt[j].heso;
				for(int e = j; e < x.sodt; e++) {
					x.moidt[e] = x.moidt[e + 1];
				}
				x.sodt--;
				j--;
			}
		}
	}
	return x;
}
DATHUC cong(DATHUC dt1, DATHUC dt2) {
    DATHUC ketqua;
    int i = 0, j = 0, k = 0;

    while (i < dt1.sodt && j < dt2.sodt) {
        if (dt1.moidt[i].bac == dt2.moidt[j].bac) {
            ketqua.moidt[k].heso = dt1.moidt[i].heso + dt2.moidt[j].heso;
            ketqua.moidt[k].bac = dt1.moidt[i].bac;
            i++;
            j++;
        } else if (dt1.moidt[i].bac < dt2.moidt[j].bac) {
            ketqua.moidt[k] = dt1.moidt[i];
            i++;
        } else {
            ketqua.moidt[k] = dt2.moidt[j];
            j++;
        }
        k++;
    }

    while (i < dt1.sodt) {
        ketqua.moidt[k] = dt1.moidt[i];
        i++;
        k++;
    }

    while (j < dt2.sodt) {
        ketqua.moidt[k] = dt2.moidt[j];
        j++;
        k++;
    }
    ketqua.sodt = k;
	for(int i = 0; i < ketqua.sodt; i++) {
		for(int j = i + 1; j < ketqua.sodt; j++) {
			if(ketqua.moidt[i].bac == ketqua.moidt[j].bac) {
				ketqua.moidt[i].heso += ketqua.moidt[j].heso;
				for(int e = j; e < ketqua.sodt; e++) {
					ketqua.moidt[e] = ketqua.moidt[e + 1];
				}
				ketqua.sodt--;
				j--;
			}
		}
	}
    return ketqua;
}
DATHUC tru(DATHUC dathuc1 , DATHUC dathuc2) {
	DATHUC ketqua;
	int i = 0 , j = 0, k = 0;
	while(i < dathuc1.sodt && j < dathuc2.sodt) {
		if(dathuc1.moidt[i].bac == dathuc2.moidt[j].bac) {
			ketqua.moidt[k].heso = dathuc1.moidt[i].heso - dathuc2.moidt[j].heso;
			ketqua.moidt[k].bac = dathuc1.moidt[i].bac;
			i++;
			j++;
		} else if(dathuc1.moidt[i].bac > dathuc2.moidt[j].bac) {
			ketqua.moidt[k] = dathuc1.moidt[i];
			i++;
		} else {
			ketqua.moidt[k].heso = -dathuc2.moidt[j].heso;
			ketqua.moidt[k].bac = dathuc2.moidt[j].bac;
			j++;
		}
		k++;
	}
	while(i < dathuc1.sodt) {
		ketqua.moidt[k] = dathuc1.moidt[i];
		i++;
		k++;
	}
	while(j < dathuc2.sodt) {
		ketqua.moidt[k].heso = -dathuc2.moidt[j].heso;
		ketqua.moidt[k].bac = dathuc2.moidt[j].bac;
		j++;
		k++;
	}
	ketqua.sodt = k;
	for(int i = 0; i < ketqua.sodt; i++) {
		for(int j = i + 1; j < ketqua.sodt; j++) {
			if(ketqua.moidt[i].bac == ketqua.moidt[j].bac) {
				ketqua.moidt[i].heso += ketqua.moidt[j].heso;
				for(int e = j; e < ketqua.sodt; e++) {
					ketqua.moidt[e] = ketqua.moidt[e + 1];
				}
				ketqua.sodt--;
				j--;
			}
		}
		if(ketqua.moidt[i].heso == 0) {
			for(int j = i; j < ketqua.sodt; j++) {
				ketqua.moidt[j] = ketqua.moidt[j + 1];
			}
			ketqua.sodt--;
		}
	}
	return ketqua;
}
DATHUC nhan(DATHUC dathuc1 , DATHUC dathuc2) {
	DATHUC ketqua;
	int k = 0;
	for(int i = 0; i < dathuc1.sodt; i++) {
		for(int j = 0; j < dathuc2.sodt; j++) {
			ketqua.moidt[k].heso = dathuc1.moidt[i].heso * dathuc2.moidt[j].heso;
			ketqua.moidt[k].bac = dathuc1.moidt[i].bac + dathuc2.moidt[j].bac;
			k++;
		}
	}
	ketqua.sodt = k;
	for(int i = 0; i < ketqua.sodt; i++) {
		for(int j = i + 1; j < ketqua.sodt; j++) {
			if(ketqua.moidt[i].bac == ketqua.moidt[j].bac) {
				ketqua.moidt[i].heso += ketqua.moidt[j].heso;
				for(int e = j; e < ketqua.sodt; e++) {
					ketqua.moidt[e] = ketqua.moidt[e + 1];
				}
				ketqua.sodt--;
				j--;
			}
		}
		if(ketqua.moidt[i].heso == 0) {
			for(int j = i; j < ketqua.sodt; j++) {
				ketqua.moidt[j] = ketqua.moidt[j + 1];
			}
			ketqua.sodt--;
		}
	}
	return ketqua;
}
DATHUC daohamcap1(DATHUC x) {
	DATHUC dathuc;
	for(int i = 0; i < x.sodt; i++) {
		dathuc.moidt[i].heso = x.moidt[i].heso * x.moidt[i].bac;
		dathuc.moidt[i].bac = x.moidt[i].bac - 1;
	}
	dathuc.sodt = x.sodt;
	return dathuc;
}
DATHUC daohamcapk(DATHUC x, int k) {
	DATHUC ketqua = x;
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < ketqua.sodt; j++) {
			ketqua.moidt[j].heso *= ketqua.moidt[j].bac;
			ketqua.moidt[j].bac -= 1;
		}
	}
	return ketqua;
}
float giatridathuc(DATHUC x, int gt) {
	float gtdt = 0;
	for(int i = 0; i < x.sodt; i++) {
		gtdt += (x.moidt[i].heso * pow(gt,x.moidt[i].bac));
	}
	return gtdt;
}
void sap_xep_tang(DATHUC *x) {
	DONTHUC temp;
	for(int i = 0; i < x->sodt - 1; i++) {
		for(int j = 0; j < x->sodt - i - 1; j++) {
			if(x->moidt[j].bac < x->moidt[j + 1].bac) {
				temp = x->moidt[j];
				x->moidt[j] = x->moidt[j + 1];
				x->moidt[j + 1] = temp;
			}
		}
	}
}
void xuatdathuc(DATHUC x) {
	for(int i = 0; i < x.sodt; i++) {
		xuatdt(x.moidt[i]);
		if(i + 1 < x.sodt) {
			if(x.moidt[i + 1].heso > 0) {
				printf(" + ");
			} else {
				printf(" ");
			}
		}
	}
}
int main() {
	DATHUC a , b , x;
	printf("nhap da thuc a\n");
	a = nhapdathuc(a);
	printf("nhap da thuc b\n");
	b = nhapdathuc(b);
	x = nhan(a,b);
	sap_xep_tang(&x);
	xuatdathuc(x);
	printf("\n");
	DATHUC dat = daohamcap1(x);
	sap_xep_tang(&dat);
	xuatdathuc(dat);
	printf("\n");
	DATHUC dhcapk = daohamcapk(x,2);
	sap_xep_tang(&dhcapk);
	xuatdathuc(dhcapk);
	printf("\n");
	printf("%.2f", giatridathuc(dhcapk,2));
	return 0;
}
