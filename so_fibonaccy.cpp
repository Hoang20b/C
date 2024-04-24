#include<stdio.h>
#include<math.h>
//bai toan liet ke day so fibonaccy.
/*
- Cho t testcase voi moi testcase dua vao n va liet ke ra n so fibonaccy.
- so fibonaccy la so ma tong cua 2 so sau = so truoc.
- day so fib co ban: 0 1 1 2 3 5 ....
- n tu 2 -> 92.
*/
//y tuong: voi cong thuc n = (n - 1) + (n - 2). co the lam de quy.
int fibo(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}
//vi n gioi han 2 -> 92 (so nho) nen thuat toan O(n) khong dang ke.
void xuatfib1(int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", fibo(i));
	}
}
/*y tuong: dich 2 fib1 va fib2 len. 
+ fib1 = fib2 va fib2 = fibn sau moi lan lap.
- chi nen dung khi n >= 2.
*/
void xuatfib2(int n) {
	if(n >= 2) {
		printf("0 1 "); //viet thu cong.
	}
	int fib1 = 0;
	int fib2 = 1;
	//bat dau duyet tu 3.
	for(int i = 3; i <= n; i++) {
		int fib = fib1 + fib2;
		printf("%d ", fib);
		fib1 = fib2;
		fib2 = fib;
	}
}
// y tuong: dung mang de luu tru cac gia tri fibo
void xuatfib3(int n) {
	long long int fib[n];
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i < n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", fib[i]);
	}
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		xuatfib3(n);printf("\n");
	}
	return 0;
}
