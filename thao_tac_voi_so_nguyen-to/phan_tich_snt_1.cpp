#include<stdio.h>
#include<math.h>
//bai toan phan tich thua so nguyen to
/*
- In ra cac uoc thua so nguyen to cua 1 so n.
- Cho t test case moi test case nhap va in ra cac uoc so nguyen to nhan thanh n
*/
//ham phan tich cac uoc so nguyen to cua n
void pt(int n) {
	//duyet tu i den log(n);
	for(int i = 2; i <= sqrt(n) ; i++) {
		if(n % i == 0) {
			//luoc cac uoc nguyen to chung;
			while(n % i == 0) {
				printf("%d ", i);
				n /= i;
			}
		}
	}
	if(n != 1) {
		printf("%d", n);
	}
}
int main() {
	//tao ra t test case;
	int t;scanf("%d", &t);
	while(t--) {
		//moi test case tao cac bien de phan tich
		int n;scanf("%d", &n);
		pt(n);printf("\n");
	}
	return 0;
}
