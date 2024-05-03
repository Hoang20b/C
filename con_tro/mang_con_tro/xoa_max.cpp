#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int Max(int *a, int n) {
	int max = *(a + 0);
	for(int i = 1; i < n; i++) {
		if(max < *(a + i)) {
			max = *(a + i);
		}
	}
	return max;
}
void xoa_max(int *a, int &n) {
	int max = Max(a,n);
	for(int i = 0; i < n; i++) {
		if(*(a + i) == max) {
			for(int j = i; j < n; j++) {
				*(a + j) = *(a + (j + 1));
			}
			i--;
			n--;
		}
	}
}
void xuat_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	xoa_max(a,n);
	xuat_mang(a,n);
	return 0;
}
