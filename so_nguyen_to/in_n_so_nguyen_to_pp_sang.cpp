#include<stdio.h>
int prime[1000001];
void sang() {
	for(int i = 0; i <= 1000000; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * i ; j <= 1000000; j += i) {
			prime[j] = 0;
		}
	}
}
int main() {
	sang();
	int n;
	scanf("%d", &n);
	int i = 0;
	//dung ham sang de in ra n so nguyen to
	while(n) {
		if(prime[i]) {
			printf("%d ", i);
			n--;
		}
		i++;
	}
	return 0;
}
