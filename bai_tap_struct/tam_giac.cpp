#include<stdio.h>
#include<math.h>
typedef struct {
	float a , b , c;
}TAMGIAC;
TAMGIAC nhaptg(TAMGIAC x) {
	printf("nhap canh a: ");scanf("%f", &x.a);
	printf("nhap canh b: ");scanf("%f", &x.b);
	printf("nhap canh c: ");scanf("%f", &x.c);
	return x;
}
void xuat_tg(TAMGIAC x) {
	printf("do dai cac canh la a = %.2f , b = %.2f , c = %.2f", x.a , x.b , x.c);
}
float chu_vi_tamgiac(TAMGIAC x) {
	float chu_vi = x.a + x.b + x.c;
	return chu_vi;
}
float dien_tich_tamgiac(TAMGIAC x) {
	float p = chu_vi_tamgiac(x) / 2;
	float dien_tich = sqrt(p * (p - x.a) * (p - x.b) * (p - x.c));
	return dien_tich;
}
int main() {
	TAMGIAC x;
	x = nhaptg(x);
	xuat_tg(x);
	printf("chu vi tam giac la: %.2f\n", chu_vi_tamgiac(x));
	printf("dien tich tam giac: %.2f", dien_tich_tamgiac(x))
	return 0;
}
