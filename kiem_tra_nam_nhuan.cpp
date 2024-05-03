#include<stdio.h>
/*bai toan kiem tra nam nhuan.
-nhap t so testcase.
-nam n neu n la nam nhuan thi in yes khong thi in no;
*/
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if(n % 100 != 0 && n % 4 == 0 || n % 400 == 0) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
} 


