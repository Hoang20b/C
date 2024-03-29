#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
//ham kiem tra mang tang
int check_tang(int a[], int n) {
	for(int i = 0; i < n - 1; i++) {
		//neu co phan tu truoc lon hon phan tu sau thi mang sai return 0
		if(a[i] > a[i + 1]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	if(check_tang(a,n)) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}
