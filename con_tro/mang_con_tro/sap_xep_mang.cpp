#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int *a , int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
void sap_xep(int *a, int n) {
	for(int i = 1; i < n; i++) {
		int key = *(a + i);
		int pos = i - 1;
		while(pos >= 0 && a[pos] > key) {
			*(a + (pos + 1)) = *(a + pos);
			pos--;
		}
		*(a + (pos + 1)) = key;
	}
}
void xuat_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	sap_xep(a,n);
	xuat_mang(a,n);
	return 0;
}
