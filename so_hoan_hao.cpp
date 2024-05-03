#include<stdio.h>
#include<math.h>
//bai toan so hoan hao.
/*
- So hoan hao la so ma cac uoc (tru chinh no) cua chung + bang chinh n.
+ vd cac so hoan hao: 6 , 28 , ...
+ 6 co cac uoc 1 ,2 ,3 , 6. Va tru 6 ra thi 1 + 2 + 3 == 6.
*/
//y tuong: duyet tu 1 -> n / 2 neu tong cac uoc == n thi in yes khong in no. O(n/2); thuat toan don gian khong toi uu neu n qua lon.
int snt(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return n > 1;
}
int so_hh1(int n) {
	int tong = 0;
	for(int i = 1; i <= n/2; i++) {
		if(n % i == 0) {
			tong += i;
		}
	}
	return tong == n;
}
//y tuong: duyet tu 2 -> log(n) . Neu n % i == 0 thi tong += i + n/i . tong se cong tu 1 va n != 1;
int so_hh2(int n) {
	int tong = 1;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			if(n/i != i) {
				tong += i + n/i;
			} else {
				tong += i;
			}
		}
	}
	return tong == n && n != 1;
}
/*y tuong: 
- tu cong thuc co san: 2^(p-1) * (2^p - 1) se tao ra so hoan hao voi dieu kien:
+p la so nguyen to.
+2^p - 1 la so nguyen to.
- ap dung neu so kiem tra qua lon.
*/
//neu so do la so nguyen to thi ham nay sieu toi uu con khong phai so nguyen to se rat rat te. !!Han che dung
int so_hh3(long long int n) {
	for(int i = 1; i <= 32; i++) {
		if(snt(i)) {
			int tmp = (int)pow(2,i) - 1;
			if(snt(tmp)) {
				long long int tong = 1ll * tmp * (int)pow(2,i - 1);
				if(tong == n) {
					return 1;
				}
			}
		}
	}
	return 0;
}
//con 1 y tuong nua ma mai lam : 24/4/2024.
//bo sung.
//y tuong: tao 1 mang global de tra ra ket qua cua 1 so hoan hao.
long long ans[32];
void so_hh4() {
	int n = 0;
	for(int i = 1; i <= 32; i++) {
		if(snt(i)) {
			long long int tmp = pow(2,i) - 1;
			if(snt(tmp)) {
				ans[n++] = 1ll * pow(2,i - 1) * tmp;
			}
		}
	}
} //su dung tuong tu ham sang nt;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		long long int n;
		scanf("%lld", &n);
		if(so_hh3(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
