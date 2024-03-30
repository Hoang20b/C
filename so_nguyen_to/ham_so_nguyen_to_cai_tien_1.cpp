#include<stdio.h>
//ham kiem tra so nguyen to
int snt(int n) {
	int dem = 1;
	//chay tu 1 den 1 nua cua n neu chia het thi dem++
	for(int i = 1; i <= n / 2; i++) {
		if(n % i == 0) {
			dem++;
		}
	}
	//neu dem = 2 thi se la so nguyen to
	if(dem == 2) {
		return 1;
	}
	return 0;
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
