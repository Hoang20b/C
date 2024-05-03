#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
void xuat_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
void xoa_chan_dau(int *a , int &n) {
	int check = 0;
	for(int i = 0; i < n; i++) {
		if(*(a + i) % 2 == 0) {
			for(int j = i; j < n; j++) {
				*(a + j) = *(a + (j + 1));
			}
			check = 1;
			n--;
			break;
		}
	}
	if(!check) {
		printf("None");
	} else {
		xuat_mang(a,n);
	}
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	xoa_chan_dau(a,n);
	return 0;
}
