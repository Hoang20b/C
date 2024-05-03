#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int sht(int n) {
	int tong = 0;
	for(int i = 1; i <= n / 2; i++) {
		if(n % i == 0) {
			tong += i;
		}
	}
	if(tong == n) {
		return 1;
	} else {
		return 0;
	}
}
int Max(int *a , int n) {
	int max = *(a + 0);
	for(int i = 1; i < n; i++) {
		if(max < *(a + i)) {
			max = *(a + i);
		}
	}
	return max;
}
int dem_chan(int *a, int n) {
	int dem = 0;
	for(int i = 0; i < n; i++) {
		if(*(a + i) % 2 == 0) {
			dem++;
		}
	}
	return dem;
}
int dem_sht(int *a , int n) {
	int dem = 0;
	for(int i = 0; i < n; i++) {
		if(sht(*(a + i))) {
			dem++;
		}
	}
	return dem;
}
int dem_max(int *a, int n) {
	int dem = 0;
	int max = Max(a,n);
	for(int i = 0; i < n; i++) {
		if(*(a + i) == max) {
			dem++;
		}
	}
	return dem;
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("so phan tu chan la: %d\n", dem_chan(a,n));
	printf("so phan tu la so hoan thien: %d\n", dem_sht(a,n));
	printf("so phan tu max: %d", dem_max(a,n));
	return 0;
}
