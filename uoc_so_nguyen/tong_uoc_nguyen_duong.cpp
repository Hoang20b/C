#include<stdio.h>
#include<math.h>
//dem so luong uoc cua 1 so nguyen duong voi t testcase.
/*
- Dem cac uoc cua so nguyen xem co bao nhieu uoc.
- 16: co cac uoc 1 , 2 , 4 , 8 , 16 => tong uoc = 1 + 2 + 4 + 8 + 16.
*/
//y tuong: lap tu 1 -> n neu la uoc cua n thi cong vao tong . Don gian nhung khong toi uu.
int tong_uoc1(int n) {
	int tong = 0;
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) {
			tong += i;
		}
	}
	return tong;
}
//y tuong: lap tu 1 -> log(n). neu la uoc i thi se + i va n/i.
int tong_uoc2(int n) {
	int tong = 0;
	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i == 0) {
			if(n/i != i) {
				tong += i + n/i;
			} else {
				tong += i;
			}
		}
	}
	return tong;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		printf("%d %d\n", tong_uoc1(n), tong_uoc2(n));
	}
	return 0;
}
