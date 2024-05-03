#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
void them_pt(int *a , int &n , int pt , int vt) {
	for(int i = n; i > vt - 1; i--) {
        *(a + i) = *(a + (i - 1)); 
    }
    *(a + (vt - 1)) = pt;
    n++;
}
void xuat_mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}
int main() {
	int *a , n, ptthem , vtthem;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	scanf("%d%d", &ptthem, &vtthem);
	if(vtthem > n) {
		printf("Error");return 0;
	}
	them_pt(a,n,ptthem,vtthem);
	xuat_mang(a,n);
	return 0;
}

