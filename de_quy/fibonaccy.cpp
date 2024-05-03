#include<stdio.h>
#include<stdlib.h>
int fibo(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}
void lkfib(int n) {
	if(n == 0) {
		return;
	}
	lkfib(n - 1);
	printf("%d ", fibo(n - 1));
}
int main() {
	int n;
	scanf("%d", &n);
	lkfib(n);
	return 0;
}
