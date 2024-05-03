#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
/*chuong trinh dao nguoc so nguyen duong 3 chu so 
- so giao dong tu 0 - 999
- in nguoc lai cac so nhap tu ban phim
*/
int main() {
	int n;
	int count = 1;
	scanf("%d", &n);
	//neu khong nam trong khoang 0 - 999 thi in None va ket thuc chuong trinh
	if(n < 0 || n > 999) {
		printf("None");return 0;
	}
	//cho vong lap chay 3 lan va viet nguoc lai so duong sau moi lan lap
	while(count <= 3) {
		int res = n % 10;
		n /= 10;
		count++;
		printf("%d", res);
	}
	return 0;
}
