#include<stdio.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	if(n == 0) {
		return;
	}
	nhap_mang(a,n - 1);
	scanf("%d", a + n - 1);
}
int pt_min(int *a , int n) {
	if(n == 0) {
		return *(a + 0);
	}
	if(*(a + n - 1) < pt_min(a,n - 1)) {
		return *(a + n - 1);
	}
	return pt_min(a,n - 1);
}
int pt_max(int *a , int n) {
	if(n == 0) {
		return *(a + 0);
	}
	if(*(a + n - 1) > pt_max(a,n - 1)) {
		return *(a + n - 1);
	}
	return pt_max(a,n - 1);
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("%d\n", pt_min(a,n));
	printf("%d", pt_max(a,n));
	free(a);
	return 0;
}
