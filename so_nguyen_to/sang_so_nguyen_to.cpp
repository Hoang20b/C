#include<stdio.h>
#include<math.h>
//so nguyen to sang toi da la 1.000.000
int prime[1000001];
void sang() {
	//cho tat ca cac so tu 0 - 1.000.000 deu la so nguyen to
	for(int i = 0; i <= 1000000; i++) {
		prime[i] = 1;
	}
	//loc thu cong 2 so 0 va 1
	prime[0] = prime[1] = 0;
	//neu so chia het cho so nguyen to thi so do khong phai so nguyen to
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * i; j <= 1000000; j += i) {
			prime[j] = 0;
		}
	}
}
int main() {
	sang();
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		if(prime[i]) {
			printf("%d ", i);
		}
	}
	return 0;
}
 
