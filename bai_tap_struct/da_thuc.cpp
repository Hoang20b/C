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
		printf("");
	} else if(x.heso == 1) {
		printf("x^%d", x.bac);
	} else {
		printf("%.2fx^%d", x.heso , x.bac);
	}
}
//ham tim kiem nhung don thuc co cung so bac va cong tru chung vao voi nhau 
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
//ham sap xep nhung don thuc co so bac lon hon se dung truoc
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
//ham tinh tong 2 da thuc
DATHUC tong_dathuc(DATHUC a , DATHUC b) {
	DATHUC c;
	//cho cac vi tri don thuc bat dau tu vi tri dau tien
	int i = 0, j = 0, k = 0;
	while(i < a.sodonthuc && j < b.sodonthuc) {
		//neu 2 don thuc co cung so bac thi cong chung lai voi nhau
		if(a.moidt[i].bac == b.moidt[j].bac) {
			c.moidt[k].heso = a.moidt[i].heso + b.moidt[j].heso;
			c.moidt[k].bac = a.moidt[i].bac;
			i++;j++;k++;
		} else if(a.moidt[i].bac > b.moidt[j].bac) { //uu tien lay nhung da thuc co bac lon 
			c.moidt[k].heso = a.moidt[i].heso;
			c.moidt[k].bac = a.moidt[i].bac;
			i++;k++;
		} else {
			c.moidt[k].heso = b.moidt[j].heso;
			c.moidt[k].bac = b.moidt[j].bac;
			j++;k++;
		}
	}
	//sau khi chay xong vong lap tren nhung da thuc co bac nho se duoc in trong 2 vong lap duoi
	while(i < a.sodonthuc) {
		c.moidt[k] = a.moidt[i];
		i++;k++;
	}
	while(j < b.sodonthuc) {
		c.moidt[k] = b.moidt[j];
		j++;k++;
	}
	//lay so don thuc la k
	c.sodonthuc = k;
	return c;
}
//ham tinh hieu cua 2 da thuc. Lay da thuc a - b
DATHUC hieu_dathuc(DATHUC a , DATHUC b) {
	DATHUC c;
	int i = 0, j = 0, k = 0;
	while(i < a.sodonthuc && j < b.sodonthuc) {
		if(a.moidt[i].bac == b.moidt[j].bac) {
			c.moidt[k].heso = a.moidt[i].heso - b.moidt[j].heso;
			c.moidt[k].bac = a.moidt[i].bac;
			i++;j++;k++;
		} else if(a.moidt[i].bac > b.moidt[j].bac) {
			c.moidt[k] = a.moidt[i];
			i++;k++;
		} else {
			c.moidt[k].heso = -b.moidt[j].heso;
			c.moidt[k].bac = b.moidt[j].bac;
			j++;k++;
		}
	}
	while(i < a.sodonthuc) {
		c.moidt[k] = a.moidt[i];
		i++;k++;
	}
	while(j < b.sodonthuc) {
		c.moidt[k].heso = -b.moidt[j].heso;
		c.moidt[k].bac = b.moidt[i].bac;
		j++;k++;
	}
	c.sodonthuc = k;
	return c;
}
//ham tich 2 da thuc
DATHUC tich_dathuc(DATHUC a , DATHUC b) {
	DATHUC c;
	int k = 0;
	for(int i = 0; i < a.sodonthuc; i++) {
		for(int j = 0; j < b.sodonthuc; j++) {
			c.moidt[k].heso = a.moidt[i].heso * b.moidt[j].heso;
			c.moidt[k].bac = a.moidt[i].bac + b.moidt[j].bac;
			k++;
		}
	}
	c.sodonthuc = k;
	c = trung_bac(c);
	c = sap_xep(c);
	return c;
}
//ham dao ham da thuc cap k
DATHUC daoham_capk(DATHUC n , int k) {
	//cho bien da thuc = n
	DATHUC dathuc = n;
	//lap qua k lan tuong ung voi da thuc cap k
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < n.sodonthuc; j++) {
				//moi lan da thuc se * bac va bac - 1
				dathuc.moidt[j].heso  *= dathuc.moidt[j].bac;
				dathuc.moidt[j].bac -= 1;
		}
	}
	return dathuc;
}
//ham tinh gia tri da thuc neu x = ???;
double gtdt(DATHUC n , int gt) {
	//cho tong gia tri = 0;
	double gt_dathuc = 0;
	for(int i = 0; i < n.sodonthuc; i++) {
		//moi lan se cong heso * gt^bac
		gt_dathuc += (double) (n.moidt[i].heso * pow(gt, n.moidt[i].bac));
	}
	return gt_dathuc;
}
//ham nhap da thuc
DATHUC nhapdathuc(DATHUC n) {
	printf("nhap so don thuc: ");scanf("%d", &n.sodonthuc);
	for(int i = 0; i < n.sodonthuc; i++) {
		printf("nhap da thuc thu %d\n", i + 1);
		n.moidt[i] = nhapdonthuc(n.moidt[i]);
	}
	n = trung_bac(n);
	n = sap_xep(n);
	return n;
}
void xuatdathuc(DATHUC n) {
	for(int i = 0; i < n.sodonthuc;i++) {
		xuatdonthuc(n.moidt[i]);
		if(i + 1 < n.sodonthuc && n.moidt[i + 1].heso > 0) {
			printf(" + ");
		} else if(i + 1 < n.sodonthuc && n.moidt[i + 1].heso < 0) {
			printf(" - ");
			n.moidt[i + 1].heso = -n.moidt[i + 1].heso;
		}
	}
}
int main() {
	DATHUC a , b , n;
	printf("nhap da thuc N\n");
	n = nhapdathuc(n);
	n = daoham_capk(n,2);
	xuatdathuc(n);printf("\n");
	printf("nhap da thuc A\n");
	a = nhapdathuc(a);
	printf("nhap da thuc B\n");
	b = nhapdathuc(b);
	n = tong_dathuc(a,b);
	xuatdathuc(n);printf("\n");
	n = hieu_dathuc(a,b);
	xuatdathuc(n);printf("\n");
	n = tich_dathuc(a,b);
	xuatdathuc(n);printf("\n");
	printf("%.2f", gtdt(n,3));
	return 0;
}
