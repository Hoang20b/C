#include<stdio.h>
#include<math.h>
#include<string.h>
typedef struct {
	int x , y;
}DIEM;
//ham nhap toa do
DIEM nhap_toa_do(DIEM n) {
	printf("nhap hoanh do: ");scanf("%d", &n.x);
	printf("nhap tung do: ");scanf("%d", &n.y);
	return n;
}
//ham tinh khoang cach
float khoang_cach(DIEM a , DIEM b) {
	//cong thuc: khoang_cach = can((x2^2 - x1^2) + (y2^2 - y1^2)) 
	float distance = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y , 2));
	return distance;
}
//ham tim diem doi xung cua diem can tim
DIEM diem_doi_xung(DIEM n) {
	DIEM diem_dx;
	//la diem doi xung qua truc Ox/Oy
	diem_dx.x = -n.x;
	diem_dx.y = -n.y;
	return diem_dx;
}
//ham kiem tra phan tu cua n
int kiem_tra_phan_tu(DIEM n) {
	//x > 0 && y > 0 => phan tu I
	if(n.x > 0 && n.y > 0) {
		return 1;
	} else if(n.x < 0 && n.y > 0) { //x < 0 && y > 0 => phan tu II
		return 2;
	} else if(n.x < 0 && n.y < 0) { // x < 0 && y < 0 => phan tu III
		return 3;
	} else if(n.x > 0 && n.y < 0) { // x > 0 && y > 0 => phan tu IV
		return 4;
	} else {
		return 0; // neu khong => n nam tren O
	}
}
void xuat_toa_do(DIEM n) {
	printf("(%d , %d)", n.x , n.y);
}
int main() {
	DIEM a , b , n;
	printf("nhap toa do diem a\n");
	a = nhap_toa_do(a);
	printf("nhap toa do diem b\n");
	b = nhap_toa_do(b);
	printf("nhap toa do diem n\n");
	n = nhap_toa_do(n);
	printf("toa do cua diem n la: ");xuat_toa_do(n);
	printf("\n");
	int check = kiem_tra_phan_tu(n);
	printf("phan tu cua n la: ");
	if(check == 1) {
		printf("I");
	} else if(check == 2) {
		printf("II");
	} else if(check == 3) {
		printf("III");
	} else if(check == 4) {
		printf("IV");
	} else {
		printf("Nam tren goc toa do");
	}
	printf("\n");
	printf("khoang cach cua diem a va b la: %.2f\n", khoang_cach(a,b));
	printf("diem doi xung cua diem n la : (%d , %d)", diem_doi_xung(n).x , diem_doi_xung(n).y);
	return 0;
}
