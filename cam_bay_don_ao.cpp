#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//bai toan "cam bay don hang ao".
/*
- Bai toan noi ve chuyen dat don ao tren mang. Nguoi tham gia se ung truoc tien hang.
- Sau 5 lan ung tien se nhan lai tien hoan va hoa hong 10%. Gia su khong bi lua dao thi se lai lo bao nhieu tien khi tham gia.
- vd nguoi tham gia mua 6 don hang voi gia tri lan luot la: 100 , 200 , 300 , 400 , 400 , 2000.
+ 5 lan dau tien se nhan lai tien va hoa hong 10%: (100 + 200 + 300 + 400 + 400) * 110% = 1540 => loi 140
+ lan thu 6 mat 2000 -> 140 - 2000 = -1860 => lo.
*/
void nhap_mang(int *a , int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
}
int solve(int *a , int n) {
	int tong = 0;
	int lailo = 0;
	int hoan_hh = 0; //bien dai dien cho tien hoan va hoa hong.
	for(int i = 0; i < n; i++) {
		tong += *(a + i);
		lailo -= *(a + i);
		//cu moi lan duoc 5 don thi tien hoan se + tong va tong bat dau cong tu don moi.
		if((i + 1) % 5 == 0) {
			hoan_hh += tong;
			tong = 0;
		}
	}
	lailo += hoan_hh * 11 / 10;
	return lailo;
}
int main() {
	int *a , n;
	scanf("%d", &n);
	a = (int *) malloc(n * sizeof(int));
	nhap_mang(a,n);
	printf("%d", solve(a,n));
	return 0;
}
