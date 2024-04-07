#include<stdio.h>
#include<math.h>
typedef struct {
	int tuso;
	int mauso;
}PHANSO;
//ham uoc chung lon nhat
int ucln(int a , int b) {
	a = abs(a);
	b = abs(b);
	while(a != 0 && b != 0) {
		if(a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}
	if(a == 0) {
		return b;
	} else {
		return a;
	}
}
//ham rut gon phan so
PHANSO uocluoc(PHANSO n) {
	//tim ra uoc chung lon nhat de rut gon
	int uoc = ucln(n.tuso , n.mauso);
	n.tuso /= uoc; //rut gon tu so
	n.mauso /= uoc; // rut gon mau so
	return n;
}
//ham nhap phan so
PHANSO nhapps(PHANSO n) {
	printf("nhap tu so: ");scanf("%d", &n.tuso);
	printf("nhap mau so: ");scanf("%d", &n.mauso);
	//neu mau so am thi tu so se am va mau so tro lai duong
	if(n.mauso < 0) {
		n.tuso = -n.tuso;
		n.mauso = -n.mauso;
	}
	//rut gon truoc khi tra ve n
	n = uocluoc(n);
	return n;
}
//ham tinh tong phan so
PHANSO tongps(PHANSO a , PHANSO b) {
	PHANSO n;
	//tinh tu so va mau so bang cach quy dong 2 phan so
	n.tuso = (a.tuso * b.mauso) + (b.tuso * a.mauso);
	n.mauso = a.mauso * b.mauso;
	//rut gon truoc khi tra ve n
	n = uocluoc(n);
	return n;
}
//ham tru 2 phan so
PHANSO hieups(PHANSO a, PHANSO b) {
	PHANSO n;
	//tinh tu so va mau so bang cach quy dong 2 phan so
	n.tuso = (a.tuso * b.mauso) - (b.tuso * a.mauso);
	n.mauso = a.mauso * b.mauso;
	//rut gon truoc khi tra ve n
	n = uocluoc(n);
	return n;
}
//ham nhan 2 phan so
PHANSO tichps(PHANSO a , PHANSO b) {
	PHANSO n;
	//tu nhan tu mau nhan mau
	n.tuso = a.tuso * b.tuso;
	n.mauso = a.mauso * b.mauso;
	//rut gon truoc khi tra ve n
	n = uocluoc(n);
	return n;
}
//ham chia 2 phan so
PHANSO thuongps(PHANSO a , PHANSO b) {
	PHANSO n;
	// tu so nhan mau so va mau so nhan tu so
	n.tuso = a.tuso * b.mauso;
	n.mauso = a.mauso * b.tuso;
	//rut gon
	n = uocluoc(n);
	//kiem tra khi cheo tu mau co bi am mau khong
	if(n.mauso < 0) {
		n.tuso = -n.tuso;
		n.mauso = -n.mauso;
	}
	return n;
}
//ham kiem tra phan so toi gian
void kt_toi_gian(PHANSO n) {
	int uoc = ucln(n.tuso,n.mauso);
	//neu ucln cua tu so va mau so = 1 thi phan so toi gian
	if(uoc == 1) {
		printf("Phan so toi gian");
	} else {
		printf("Phan so khong toi gian");
	}
}
//ham kiem tra phan so am duong
void kt_am_duong(PHANSO n) {
	//neu tu so la so am va mau so la so duong thi phan so la so am
	if(n.tuso < 0) {
		printf("Phan so am");
	} else if(n.tuso == 0) {
		printf("phan so = 0");
	} else {
		printf("Phan so duong");
	}
}
//ham so sanh 2 phan so
void so_sanhps(PHANSO a, PHANSO b) {
	//lay gia tri A va B de so sanh
	float gtA = (float) a.tuso / a.mauso;
	float gtB = (float) b.tuso / b.mauso;
	if(gtA > gtB) {
		printf("gia tri phan so A lon hon gia tri phan so B");
	} else if(gtA == gtB) {
		printf("2 phan so bang nhau");
	} else {
		printf("gia tri phan so B lon hon gia tri phan so A");
	}
}
//ham xuat phan so
void xuatps(PHANSO n) {
	if(n.mauso == 0) {
		printf("Infinity"); // neu mau so = 0 thi ket qua se vo cuc
	} else if(n.tuso == 0) {
		printf("0"); // tu so = 0 thi in ra 0
	} else if(n.mauso == 1) {
		printf("%d", n.tuso);
	} else {
		printf("%d/%d", n.tuso , n.mauso);
	}
}
int main() {
	PHANSO a , b , n;
	printf("nhap phan so N\n");
	n = nhapps(n);
	printf("nhap phan so A\n");
	a = nhapps(a);
	printf("nhap phan so B\n");
	b = nhapps(b);
	xuatps(n);printf("\n");
	n = tongps(a,b);
	xuatps(n);printf("\n");
	n = hieups(a,b);
	xuatps(n);printf("\n");
	n = tichps(a,b);
	xuatps(n);printf("\n");
	n = thuongps(a,b);
	xuatps(n);printf("\n");
	kt_toi_gian(n);printf("\n");
	kt_am_duong(n);printf("\n");
	so_sanhps(a,b);
	return 0;
}
