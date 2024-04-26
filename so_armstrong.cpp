#include<stdio.h>
#include<math.h>
//Bai toan kiem tra so armstrong.
/*
- So armstrong vd: 371 gom 3 chu so.
+ 3^3 + 7^3 + 1^3 = 371.
- de bai gom t testcase.
*/
//y tuong: tao 1 ham dem chu so va 1 ham kiem tra.
int dem_so(int n) {
	int count = 0;
	while(n) {
		count++;
		n /= 10;
	}
	return count;
}
int armstrong(int n) {
	int so = dem_so(n);
	int tong = 0;
	int tmp = n;
	while(n) {
		tong += pow(n%10,so);
		n /= 10;
	}
	return tong == tmp;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		if(armstrong(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
