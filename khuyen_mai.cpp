#include<stdio.h>
#include<math.h>
/*bai toan khuyen mai trong cua hang tien loi;
-neu mua 3 cay but se duoc tang 1 va tinh tien 3 but
*/
int main() {
	//n la so but va t la gia tien
	int n,  t;
	long long int thanh_toan = 0;
	scanf("%d%d", &n, &t);
	while(n) {
		//neu n lon hon 3 se duoc khuyen mai 1
		if(n > 3) {
			thanh_toan += 3 * t;
			//khuyen mai
			n--;
			//sau khi tinh thi - so but da tinh
			n -= 3;
		} else {
			//neu khong lon hon 3 thi khong khuyen mai
			thanh_toan += n * t;
			//sau khi tinh thi - so but da tinh
			n -= n;
		}
	}
	printf("%lld", thanh_toan);
	return 0;
}
