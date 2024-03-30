#include<stdio.h>
#include<math.h>
int max(int a , int b) {
	if(a > b) {
		return a;
	}
	return b;
}
//ham sang so nguyen to tren doan
void sang_doan(int a, int b) {
	int prime[b - a + 1];
	for(int i = 0; i <= b - a; i++) {
		prime[i] = 1;
	}
	//neu j la boi cua i thi khong phai so nguyen to
	for(int i = 2; i <= sqrt(b);i++) {
		for(int j = max(i * i , (a + i - 1)/i * i); j <= b ;j += i) {
			prime[j - a] = 0;
		}
	}
	//in ra cac so nguyen to tren doan a -> b
	for(int i = max(a,2); i <= b; i++) {
		if(prime[i - a]) {
			printf("%d ", i);
		}
	}
}
int main() {
	int a , b;
	scanf("%d%d", &a , &b);
	sang_doan(a,b);
	return 0;
}
