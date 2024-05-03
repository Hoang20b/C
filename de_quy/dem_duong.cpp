#include<stdio.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	if(n == 0) {
		return;
	}
	scanf("%d", a + n - 1);
	nhap_mang(a,n - 1);
}
int dem_duong(int *a , int n) {
	if(n == 0) {
		return 0;
	}
	int count = dem_duong(a,n - 1);
	if(*(a + n - 1) > 0) {
		count++;
	}
	return count;
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("%d", dem_duong(a,n));
	free(a);
	return 0;
}
