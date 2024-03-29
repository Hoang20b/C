#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
//ham kiem tra xem co phan tu le trong mang khong
int kiem_tra_le(int a[], int n) {
	//cho bien check = 0 khi chua tim duoc phan tu le cua mang
	int check = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 != 0) {
			//khi tim duoc phan tu le thi cho bien check = 1;
			check = 1;
		}
	}
	//tra ra ket qua dung sai
	return check;
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	if(kiem_tra_le(a,n)) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}
