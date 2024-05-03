#include<stdio.h>
#include<math.h>
// bai toan kiem tra so smith.
/*
- so sphenic duoc hieu la so co 3 so nguyen to ma so do khong co so mu lon hon = 2.
+ vd: 30 , 42 , ...
- voi t testcase kiem tra so sphenic.
*/
//y tuong: lap cac so nguyen to neu so mu cua 1 so >= 2 thi return 0. Cuoi cung so sanh neu so snt == 3 thi return 1.
int sphenic(int n) {
	int rev = 0;
	for(int i = 2; i <= n; i++) {
		if(n % i == 0) {
			int count = 0;
			while(n % i == 0) {
				count++;
				n /= i;
			}
			//neu so mu >= 2 thi
			if(count >= 2) {
				return 0;
			} else {
				//neu khong thi tang rev len 1
				rev++;
			}
		}
	}
	return rev == 3;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		if(sphenic(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
