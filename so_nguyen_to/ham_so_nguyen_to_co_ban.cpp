#include<stdio.h>
int snt(int n) {
	int dem = 0;
	//chay tu 1 den n neu n chia het i thi dem++
	for(int i = 1; i <= n; i++) {
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
