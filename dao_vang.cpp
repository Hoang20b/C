#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Bai toan tim vang.
-Ban dang co 1 may khoan de khai thac cac o dat co chua vang
-May khoan co 2 che do 1 va 2
+ che do 1 thi dao duoc khoang san lai 1 va khoang san 2 se bi pha huy
+ che do 2 tuong tu che do 1
-Cac loai khoang san
+Khoang san 1 a[i][j] > 0 ;
+Khoang san 2 a[i][j] < 0;
+O dat trong a[i][j] = 0;
-Hay lap trinh de dao duoc nhieu khoang san nhat
-In ra so khoang san max co the khai thac.
*/
void nhap_matran(int *a , int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", a + (i * m + j));
		}
	}
}
//ham tim hang co the khai thac toi da khoang san loai 1
int khoang_san1(int *a , int n , int m) {
	int max1 = 0;
	for(int i = 0; i < n; i++) {
		int tong = 0;
		for(int j = 0; j < m; j++) {
			//a[i][j] > 0 -> khoang san loai 1;
			if(*(a + (i * m + j)) > 0) {
				tong += *(a + (i * m + j));
			}
		}
		//tim ra hang khai thac toi da khoang san loai 1
		if(tong > max1) {
			max1 = tong;
		}
	}
	return max1;
}
int khoang_san2(int *a , int n , int m) {
	int max2 = 0;
	for(int i = 0; i < n; i++) {
		int tong = 0;
		for(int j = 0; j < m; j++) {
			if(*(a + (i * m + j)) < 0) {
				tong += *(a + (i * m + j));
			}
		}
		if(tong < max2) {
			max2 = tong;
		}
	}
	return max2;
}
int main() {
	int *a , n , m;
	scanf("%d%d", &n , &m);
	a = (int *) malloc(n * m * sizeof(int));
	nhap_matran(a,n,m);
	printf("khoang san khai thac duoc la: %d", khoang_san1(a,n,m) - khoang_san2(a,n,m));
	return 0;
}
