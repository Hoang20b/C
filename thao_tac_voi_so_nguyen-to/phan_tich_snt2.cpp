#include<stdio.h>
#include<stdio.h>
//bai toan phan tich thanh phan uoc so nguyen to.
/*
- phan tich ra thanh phan uoc so cua 1 so.
- ghi ra so mu va nhan.
- vd 28: 2^2 * 7.
- lam voi t testcase.
*/
void pt(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			int count = 0;
			while(n % i == 0) {
				count++;
				n /= i;
			}
			printf("%d^%d", i , count);
			if(i <= n) {
				printf(" * ");
			}
		}
	}
	if(n != 1) {
		printf("%d^1", n);
	}
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		pt(n);
		printf("\n");
	}
	return 0;
}
