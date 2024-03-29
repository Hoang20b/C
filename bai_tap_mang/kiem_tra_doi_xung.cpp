#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
//ham kiem tra doi xung
int kiem_tra_dx(int a[] , int n) {
	for(int i = 0; i < n / 2;i++) {
		//cong thuc vi tri doi xung neu khong doi xung lap tuc return 0
		if(a[i] != a[n - i - 1]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	if(kiem_tra_dx(a,n)) {
		printf("TRUE");
	} else {
		printf("FALSE");
	}
	return 0;
}
