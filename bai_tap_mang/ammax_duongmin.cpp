#include<stdio.h>
#include<math.h>
#include<limits.h>
void nhap_mang(int a[100] , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
//ham tim so am lon nhat
void am_max(int a[], int n) {
	int check = 0;
	//cho bien max bang so nho nhat
	int max = INT_MIN;
	for(int i = 0; i < n; i++) {
		//kiem tra neu co thi thay bien max
		if(a[i] > max && a[i] < 0) {
			max = a[i];
			check = 1;
		}
	}
	//thuc hien kiem tra va in ra ket qua
	if(check) {
		printf("%d", max);
	} else {
		printf("None");
	}
}
void duong_min(int a[], int n) {
	int check = 0;
	//cho bien min bang so lon nhat
	int min = INT_MAX;
	for(int i = 0; i < n; i++) {
		//kiem tra neu co thi thay bien min
		if(a[i] < min && a[i] > 0) {
			min = a[i];
			check = 1;
		}
	}
	//thuc hien kiem tra va in ra ket qua
	if(check) {
		printf("%d", min);
	} else {
		printf("None");
	}
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	am_max(a,n);
	printf("\n");
	duong_min(a,n);
	return 0;
}
