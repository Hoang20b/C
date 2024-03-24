#include<stdio.h>
#include<math.h>
int main() {
	int dien_tieu_thu;
	long long int tien_dien;
	printf("Hay nhap dien tieu thu cua ban trong thang nay: ");
	scanf("%d", &dien_tieu_thu);
	if(dien_tieu_thu >= 0 && dien_tieu_thu <= 50) {
		printf("Bac 1\n");
		tien_dien = dien_tieu_thu * 1806;
	} else if(dien_tieu_thu >= 51 && dien_tieu_thu <= 100) {
		printf("Bac 2\n");
		tien_dien = ((dien_tieu_thu - 50) * 1866) + (50 * 1806);
	} else if(dien_tieu_thu >= 101 && dien_tieu_thu <= 200) {
		printf("Bac 3\n");
		tien_dien = ((dien_tieu_thu - 100) * 2167) + (50 * 1866) + (50 * 1806);
	} else if(dien_tieu_thu >= 201 && dien_tieu_thu <= 300) {
		printf("Bac 4\n");
		tien_dien = ((dien_tieu_thu - 200) * 2729) + (100 * 2167) + (50 * 1866) + (50 * 1806); 
	} else if(dien_tieu_thu >= 301 && dien_tieu_thu <= 400) {
		printf("Bac 5\n");
		tien_dien = ((dien_tieu_thu - 300) * 3050) + (100 * 2729) + (100 * 2167) + (50 * 1866) + (50 * 1806);
	} else if(dien_tieu_thu >= 401) {
		printf("Bac 6\n");
		tien_dien = ((dien_tieu_thu - 400) * 3151) + (100 * 3050) + (100 * 2729) + (100 * 2167) + (50 * 1866) + (50 * 1806);
	} else {
		printf("Loi ! hay nhap lai luong dien tieu thu");
	}
	printf("%lld dong", tien_dien);
	return 0;
}
