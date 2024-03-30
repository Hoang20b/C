#include<stdio.h>
int prime[10001];
void sang() {
	for(int i = 0; i <= 10000; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= 100;i++) {
		for(int j = i * i; j <= 10000; j += i) {
			prime[j] = 0;
		}
	}
}
int main() {
	sang();
	int t;
	scanf("%d", &t);
	for(int l = 1; l <= t; l++) {
		int check = 0;
		int n;
		scanf("%d", &n);
		for(int i = 0; i <= n/2; i++) {
			if(prime[i] && prime[n - i]) {
				printf("%d %d\n", i , n - i);
				check = 1;
			}
		}
		if(!check) {
			printf("None\n");
		}
	}
	return 0;
}
