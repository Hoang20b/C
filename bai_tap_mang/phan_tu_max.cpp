#include<stdio.h>
#include<math.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
int Max(int a[], int n) {
	int max = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
int dem_max(int a[], int n) {
	int dem = 0;
	int max = Max(a,n);
	for(int i = 0; i < n;i++) {
		if(a[i] == max) {
			dem++;
		}
	}
	return dem;
}
void vt_max(int a[], int n) {
	int max = Max(a,n);
	for(int i = 0; i < n; i++) {
		if(a[i] == max) {
			printf("%d ", i);
		}
	}
}
int main() {
	int a[100], n;
	scanf("%d", &n);
	nhap_mang(a,n);
	printf("%d\n", Max(a,n));
	printf("%d\n", dem_max(a,n));
	vt_max(a,n);
	return 0;
}
