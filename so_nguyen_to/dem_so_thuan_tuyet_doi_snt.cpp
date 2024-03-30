#include<stdio.h>
//ham kiem tra so nguyen to
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
//ham kiem tra full so nguyen to
int full_snt(int n) {
	while(n) {
		int r = n % 10;
		if(r != 2 && r != 3 && r != 5 && r != 7) {
			return 0;
		}
		n /= 10;
	}
	return 1;
}
//ham kiem tra tong co phai so nguyen to hay khong
int tong_snt(int n) {
	int tong = 0;
	while(n) {
		tong += n % 10;
		n /= 10;
	}
	if(snt(tong)) {
		return 1;
	} else {
		return 0;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a , b;
		int dem = 0;
		scanf("%d%d", &a , &b);
		for(int i = a; i <= b; i++) {
			if(full_snt(i) && snt(i) && tong_snt(i)) {
				dem++;
			}
		}
		printf("%d\n", dem);
	}
	return 0;
}
