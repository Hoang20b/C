#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void nhap_mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}
//ham them phan tu
void thempt(int a[], int n, int x) {
	//cho vitrichen la lon nhat
	int viTrichen = n;
	while (viTrichen > 0 && a[viTrichen - 1] > x) {
        a[viTrichen] = a[viTrichen - 1];
        //neu khong dung thi tru dan
        viTrichen--;
    }
    a[viTrichen] = x;
    n++;
    for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int main() {
    int a[100], n , x;
    scanf("%d", &n);
    nhap_mang(a,n);
    scanf("%d", &x);
    thempt(a,n,x);
    return 0;
}
