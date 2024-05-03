#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//bai toan so so chia het cho 3 so.
/*
- Tao ra 4 bien: x , y , z , n.
+ Voi n la so chu so. Tao ra so chia het cho 3 bien x y z.
- Thuc hien voi t testcase.
- Neu tim khong thay tra ra -1.
*/
//y tuong se lap tu so dau tien co so chu so den so cuoi cung.
long long int solve(int x , int y , int z , int n) {
	//bat dau tu 10^n-1 chu so den < 10^n chu so.
	for(long long int i = pow(10, n - 1); i < pow(10, n); i++) {
		if(i % x == 0 && i % y == 0 && i % z == 0) {
			return i;
		}
	}
	return -1;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int x , y , z , n;scanf("%d%d%d%d", &x , &y , &z , &n);
		printf("%lld\n", solve(x,y,z,n));
	}
	return 0;
}
