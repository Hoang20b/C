#include<stdio.h>
//ham kiem tra so nguyen to
int snt(int n) {
	//neu so be hon 1 se khong phai la so nguyen to
	if(n <= 1) {
		return 0;
	}
	//cho i chay tu 2 den can 2 cua n neu n chia het i se khong phai so nguyen to
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	if(snt(n)) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}
