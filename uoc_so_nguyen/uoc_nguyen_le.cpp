#include<stdio.h>
#include<math.h>
//bai toan kiem tra so luong uoc so nguyen to le.
//cho t testcase
/*
- Neu n co so luong uoc nguyen la so le thi in YES khong thi in NO;
- 16: 1 2 4 8 16 => YES .
*/
//y tuong: dem moi so uoc va kiem tra chan le so uoc. Don gian nhung khong toi uu.
int uoc_le1(long long int n) {
	int count = 0;
	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i == 0) {
			if(n/i != i) {
				count += 2;
			} else {
				count++;
			}
		}
	}
	if(count % 2 != 0) {
		return 1;
	} else {
		return 0;
	}
}
//y tuong: so co uoc le la so chinh phuong.
int uoc_le2(long long int n) {
	int can = sqrt(n);
	if(can * can == n) {
		return 1;
	}
	return 0;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		long long int n;
		scanf("%lld", &n);
		if(uoc_le2(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
