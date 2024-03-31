#include<stdio.h>
#include<math.h>
void nhap_matran(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("nhap gia tri a[%d][%d]: ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
}
//ham kiem tra doi xung
int kiem_tra_dx(int a[][100], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			//neu so dong , cot != cot , dong thi khong doi xung
			if(a[i][j] != a[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	int a[100][100] , n;
	printf("nhap so dong va cot: ");scanf("%d" , &n);
	nhap_matran(a,n);
	if(kiem_tra_dx(a,n)) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}
