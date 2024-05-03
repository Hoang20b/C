#include<stdio.h>
#include<math.h>
//dem so luong uoc cua 1 so nguyen duong.
/*
- Dem cac uoc cua so nguyen xem co bao nhieu uoc.
- 16: 1 , 2 , 4 , 8 , 16 => co 5 uoc so nguyen.
*/
//y tuong: cach thong thuong duyet tu 1 -> n . Neu n % i == 0 => count++. Cach don gian va han che nhat.
int dem_uoc1(int n) {
	int count = 0;
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) {
			count++;
		}
	}
	return count;
}
//y tuong: neu n % i == 0 thi n % (n/i) se = 0. Co the ap dung de toi uu vong lap.
int dem_uoc2(int n) {
	int count = 0;
	//lap tu 1 -> log(n);
	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i == 0) {
			if(n/i != i) {
				//khong cung 1 uoc => 2 uoc -> count + 2;
				count += 2;
			} else {
				//cung 1 uoc thi se +1 gia tri cho count
				count++;
			}
		}
	}
	return count;
}
//y tuong: tonguoc = (e1 + 1) * (e2 + 1) * ....
int dem_uoc3(int n) {
	int count = 1;
	for(int i = 2; i <= sqrt(n); i++) {
		//so mu cua 1 uoc nguyen to nao do.
		int tmp = 0;
		while(n % i == 0) {
			tmp++;
			n /= i;
		}
		count *= tmp + 1;
	}
	if(n != 1) {
		count *= 2;
	}
	return count;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		int n;scanf("%d", &n);
		printf("%d %d %d\n", dem_uoc1(n) , dem_uoc2(n), dem_uoc3(n));
	}
	return 0;
}
