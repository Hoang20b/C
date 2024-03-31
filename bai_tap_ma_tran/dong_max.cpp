#include<stdio.h>
#include<math.h>
void nhap_matran(int a[][100], int n) {
	for(int i = 0;i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap phan tu a[%d][%d]: ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham tim dong max
int max_dong(int a[][100], int n) {
	//cho bien max = 0
	int max = 0;
	for(int i = 0; i < n; i++) {
		//moi dong tao ra 1 bien tong = 0
		int tong = 0;
		for(int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		//neu tong lon hon max thi gan max = tong
		if(max < tong) {
			max = tong;
		}
	}
	return max;
}
void liet_ke_dong_max(int a[][100], int n) {
	//lay dong max
	int max = max_dong(a,n);
	for(int i = 0; i < n; i++) {
		int tong = 0;
		for(int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		//neu co dong = dong max thi in ra dong do
		if(tong == max) {
			printf("%d ", i);
		}
	}
}
int main() {
	int a[100][100] , n;
	printf("nhap so dong va so cot: ");scanf("%d", &n);
	nhap_matran(a,n);
	liet_ke_dong_max(a,n);
	return 0;
}
