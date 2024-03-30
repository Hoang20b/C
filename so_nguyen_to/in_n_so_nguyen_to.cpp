#include<stdio.h>
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
int main() {
	int n;
	scanf("%d", &n);
	int i = 0;
	//vong lap giup in ra n lan so nguyen to
	while(n) {
		if(snt(i)) {
			printf("%d ", i);
			//neu tim thay so nguyen to n se giam gia tri den 0
			n--;
		}
		i++;
	}
	return 0;
}
