#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
void duong_dau_cuoi(int a[], int n) {
	int check = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > 0) {
			printf("%d\n", a[i]);
			check = 1;
			break;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] > 0) {
			printf("%d", a[i]);
			break;
		}
	}
	if(!check) {
		printf("None");
	}
}
int main() {
	int a[100] , n;
	scanf("%d", &n);
	nhap_mang(a,n);
	duong_dau_cuoi(a,n);
	return 0;
}
