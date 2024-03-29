#include<stdio.h>
#include<math.h>
int check_scp(int n) {
	if(sqrt(n) == (int) sqrt(n)) {
		return 1;
	}
	return 0;
}
void nhap_mang(int a[100] , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
int dem_scp(int a[], int n) {
	int dem = 0;
	for(int i = 0; i < n; i++) {
		if(check_scp(a[i])) {
			dem++;
		}
	}
	return dem;
}
int tong_scp(int a[], int n) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		if(check_scp(a[i])) {
			tong += a[i];
		}
	}
	return tong;
}
void lk_scp(int a[100], int n) {
	for(int i = 0; i < n; i++) {
		if(check_scp(a[i])) {
			printf("%d ", a[i]);
		}
	}
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	printf("%d\n%d\n", dem_scp(a,n), tong_scp(a,n));
	lk_scp(a,n);
	return 0;
}
