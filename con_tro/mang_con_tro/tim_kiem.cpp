#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int snt(int n) {
	if(n <= 1) {
		return 0;
	}
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return 0;
		}
	} 
	return 1;
}
int chan_dau(int *a , int n) {
	for(int i = 0; i < n; i++) {
		if(*(a + i) % 2 == 0) {
			return *(a + i);
		}
	}
	return -1;
}
int le_dau(int *a , int n) {
	for(int i = 0; i < n; i++) {
		if(*(a + i) % 2 != 0) {
			return *(a + i);
		}
	}
	return -1;
}
int snt_dau(int *a , int n) {
	for(int i = 0; i < n; i++) {
		if(snt(*(a + i))) {
			return *(a + i);
		}
	}
	return -1;
}
int main() {
	int *a, n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	if(chan_dau(a,n) == -1) {
		printf("chan dau: None\n");
	} else {
		printf("chan dau: %d\n", chan_dau(a,n));
	}
	if(le_dau(a,n) == -1) {
		printf("le dau: None\n");
	} else {
		printf("le dau: %d\n", le_dau(a,n));
	}
	if(snt_dau(a,n) == -1) {
		printf("so nguyen to dau: None");
	} else {
		printf("so nguyen to dau: %d", snt_dau(a,n));
	}
	free(a);
	return 0;
}
