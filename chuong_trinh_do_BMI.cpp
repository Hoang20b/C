#include<stdio.h>
#include<math.h>
int main() {
	float can_nang , chieu_cao;
	printf("nhap can nang cua ban: ");
	scanf("%f", &can_nang);
	printf("nhap chieu cao cua ban: ");
	scanf("%f", &chieu_cao);
	float chi_so_BMI = can_nang / pow(chieu_cao,2);
	printf("%.2f\n", chi_so_BMI);
	if(chi_so_BMI < 18.5) {
		printf("Coi xuong , suy dinh duong");
	} else if(chi_so_BMI >= 18.5 && chi_so_BMI <= 22.9) {
		printf("Can nang tieu chuan");
	} else if(chi_so_BMI >= 23) {
		printf("Thua can\n");
		if(chi_so_BMI >= 23 && chi_so_BMI <= 24.9) {
			printf("Tien beo phi");
		} else if(chi_so_BMI >= 25 && chi_so_BMI <= 29.9) {
			printf("Beo phi do 1");
		} else {
			printf("Beo phi do 2");
		}
	}
	return 0;
}
