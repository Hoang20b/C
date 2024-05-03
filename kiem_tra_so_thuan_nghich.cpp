#include<stdio.h>
#include<math.h>
//bai toan so thuan nghich.
/*
- Kiem tra so thuan nghich voi t testcase.
+ Neu la so thuan nghich thi in YES khong thi in NO.
+ so thuan nghich la so nguoc nhau: 1221 , 12321 , ....
*/
//y tuong: dao nguoc so lai va so sanh voi so ban dau . Neu so dao nguoc = so ban dau => thuan nghich.
int kt_thuan_nghich(long long int n) {
	long long int rev = 0;
	//luu gia tri cua bien n vao bien tmp;
	long long int tmp = n;
	while(n) {
		rev = (rev * 10) + (n % 10);
		n /= 10;
	}
	//sau khi ket thuc vong lap n da = 0.
	//tmp se so sanh gia tri thay cho n.
	if(tmp == rev) {
		return 1;
	}
	return 0;
}
int main() {
	int t;scanf("%d", &t);
	while(t--) {
		//gia tri dua vao co the len toi 10^18.
		long long int n;scanf("%lld", &n);
		if(kt_thuan_nghich(n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
