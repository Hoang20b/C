#include<stdio.h>
#include<stdlib.h>
//Bai toan xoa 2 so sao cho tong mang chan.
/*
- Cho day so va tim cach loai 2 so sao cho tong cua mang la chan.
- Tinh so cach loai 2 so cho tong mang chan.
*/
//y tuong: neu tat ca la so chan thi n + (n - 1) + .... khong thi dung 2 vong lap for.
void nhap_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int so_cach_xoa(int *a, int n) {
	int sole = 0;
	int cach = 0;
	long long int tong = 0;
	for(int i = 0; i < n; i++) {
		tong += *(a + i);
		if(*(a + i) % 2 != 0) {
			sole++;
		} 
	}
	if(sole == 0) {
		while(n--) {
			cach += n;
		}
		return cach;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if((tong - *(a + i) - *(a + j)) % 2 == 0) {
				cach++;
			}
		}
	}
	return cach;
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("%d", so_cach_xoa(a,n));
	return 0;
}
