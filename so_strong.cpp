#include<stdio.h>
#include<math.h>
//bai toan so Strong.
/*
-So strong duoc hieu la so ma tong giai thua cua chu so do == so do.
- vd 145 la so strong: 1! = 1, 4! = 24 , 5! = 120. Tong cac giai thua = 145.
*/
//y tuong: viet 1 ham giai thua va dung ham do vao ham kiem tra so strong.
long long int gt(int n) {
	long long int s = 1;
	while(n >= 1) {
		s *= n;
		n--;
	}
	return s;
}
int soStrong(int n) {
	//luu tru gia tri cua n qua bien tmp.
	int tmp = n;
	int tong = 0;
	while(n) {
		tong += gt(n % 10);
		n /= 10;
	}
	return tong == tmp;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		if(soStrong(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
