#include<stdio.h>
#include<math.h>
//bai toan so smith voi t testcase.
/*
- so smith la so ma tong cua cac uoc chu so nguyen to cua so do bang tong chu so cua so do.
+ vd: 4 la so smith. Gom cac uoc 2 + 2.
*/
//y tuong: 
int tong_so(int n) {
	int tong = 0;
	while(n) {
		tong += n % 10;
		n /= 10;
	}
	return tong;
}
int smith(int n) {
	int tong1 = tong_so(n);
	int tong2 = 0;
	for(int i = 2; i <= n; i++) {
		if(n % i == 0) {
			//neu so co hon 2 chu so thi cong cac chu so co trong so do. vd: 37 se tach thanh 3 + 7.
			while(n % i == 0) {
				tong2 += tong_so(i);
				n /= i;
			}
		}
	}
	return tong2 == tong1;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		if(smith(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
