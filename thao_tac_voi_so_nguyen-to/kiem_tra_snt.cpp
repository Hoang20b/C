#include<stdio.h>
#include<math.h>
// bai tap kiem tra so nguyen to voi t testcase.
/*
- Moi testcase nhap mot so nguyen n va kiem tra.
+ Neu n la so nguyen to in YES khong thi in NO.
*/
//y tuong: sang truoc cac so nguyen to bang ham sang nguyen to.
int prime[1000001];
void sang() {
	for(int i = 0; i <= 1000000; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= 1000; i++) {
		if(prime[i]) {
			for(int j = i * i; j <= 1000000; j += i) {
				prime[j] = 0;
			}
		}
	}	
}
int main() {
	int t;scanf("%d", &t);
	sang();
	while(t--) {
		int n;scanf("%d", &n);
		if(prime[n]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
