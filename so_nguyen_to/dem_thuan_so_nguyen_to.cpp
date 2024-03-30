#include<stdio.h>
#include<math.h>
int prime[1000001];
//su dung phuong phap sang de kiem tra so nguyen to
void sang() {
	for(int i = 0; i <= 1000000; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= 1000; i++) {
		for(int j = i * i; j <= 1000000; j += i) {
			prime[j] = 0;
		}
	}
}
//kiem tra so do co full so nguyen to khong
int full_snt(int n) {
	while(n) {
		int r = n % 10;
		//neu khong co tung so la so nguyen to thi tra ve 0
		if(r != 2 && r != 3 && r != 5 && r != 7) {
			return 0;
		}
		n /= 10;
	}
	//neu full so nguyen to thi tra ve 1
	return 1;
}
int main() {
	sang();
	int a, b;
	int dem = 0;
	scanf("%d%d", &a , &b);
	for(int i = a; i <= b; i++) {
		if(prime[i] && full_snt(i)) {
			dem++;
		}
	}
	printf("%d", dem);
	return 0;
}
 
