#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int &n) {
	int i = 0;
	//neu mang duong se tiep tuc nhap
	do {
		scanf("%d", &a[i]);
		++i;
	} while(a[i - 1]  > 0);
	//gan n bang do dai mang duong
	n = i - 1; 
}
void xuat_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
		if(n - 1 > i) {
			printf(", ");
		}
	}
}
int main() {
	int a[100] , n;
	nhap_mang(a,n);
	xuat_mang(a,n);
	return 0;
}
